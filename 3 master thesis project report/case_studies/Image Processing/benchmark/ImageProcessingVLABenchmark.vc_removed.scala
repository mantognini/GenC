/* Copyright 2009-2016 EPFL, Lausanne */

import leon.annotation._
import leon.lang._
import leon.lang.StaticChecks._

import leon.io.{
  FileInputStream => FIS,
  FileOutputStream => FOS,
  StdOut
}
import leon.util.{ TimePoint }

import scala.annotation.tailrec

/**
 * Some basic image processing; this version uses VLA and is designed for benchmarks.
 *
 * General NOTEs
 * -------------
 *
 *  Byte ranges from -128 to 127, not 0 to 255. It is important to remember
 *  that when manipulating individual component as Byte.
 *
 *  The BMP format uses little endian.
 *
 *  See https://msdn.microsoft.com/en-us/library/dd183391(v=vs.85).aspx
 *  for the full documentation.
 *
 *  For benchmarks, the each images are loaded once, then for each filter
 *  the image is processed `BenchmarkRuns` times. Each runs prints:
 *
 *  input;kernel;runtime[ms]
 *
 *  This program is expected to be run from `run.fish`.
 */
object ImageProcessingVLABenchmark {

  /**********************************************************************
   *                                                      Constants     *
   **********************************************************************/

  @inline
  val BenchmarkRuns = 50


  // Sizes in bytes of several Windows numerical types
  @inline
  val WordSize  = 2 // 16 bits, unsigned
  @inline
  val DwordSize = 4 // 32 bits, unsigned
  @inline
  val LongSize  = 4 // 32 bits, signed


  /**********************************************************************
   *                                               Basic Algorithms     *
   **********************************************************************/

  def inRange(x: Int, min: Int, max: Int): Boolean = {
    min <= x && x <= max
  }

  def min(x: Int, y: Int): Int = {
    if (x <= y) x else y
  }

  def max(x: Int, y: Int): Int = {
    if (x <  y) y else x
  }

  def clamp(x: Int, down: Int, up: Int): Int = {
    max(down, min(x, up))
  }


  /**********************************************************************
   *                                                         Status     *
   **********************************************************************/

  sealed abstract class Status {
    def isSuccess: Boolean = this.isInstanceOf[Success]
  }

  case class Success()                  extends Status
  case class OpenError()                extends Status
  case class ReadError()                extends Status
  case class DomainError()              extends Status
  case class InvalidFileHeaderError()   extends Status
  case class InvalidBitmapHeaderError() extends Status
  case class CorruptedDataError()       extends Status
  case class ImageTooBigError()         extends Status
  case class NoImageError()             extends Status
  case class WriteError()               extends Status
  case class NotImplementedError()      extends Status

  def statusCode(s: Status): Int = s match {
    case Success()                  => StdOut.println("success");                          0
    case OpenError()                => StdOut.println("couldn't open file");               1
    case ReadError()                => StdOut.println("couldn't read some expected data"); 2
    case DomainError()              => StdOut.println("integer out of range");             3
    case InvalidFileHeaderError()   => StdOut.println("file format unsupported");          4
    case InvalidBitmapHeaderError() => StdOut.println("bitmap format unsupported");        5
    case CorruptedDataError()       => StdOut.println("the file appears to be corrupted"); 6
    case ImageTooBigError()         => StdOut.println("the image is too big");             7
    case NoImageError()             => StdOut.println("the image is empty");               8
    case WriteError()               => StdOut.println("couldn't write image");             9
    case NotImplementedError()      => StdOut.println("not yet implemented");              99
  }


  /**********************************************************************
   *                                                    MaybeResult     *
   **********************************************************************/

  // Basically, MaybeResult[A] is Either[A, B] where B is Status
  abstract class MaybeResult[A] {
    def isDefined = this match {
      case Result(_) => true
      case _         => false
    }

    def getResult: A = {
      this.asInstanceOf[Result[A]].result
    }

    def getStatus: Status = {
      this.asInstanceOf[Failure[A]].status
    }

    def toStatus: Status = {
      if (isDefined) Success()
      else           getStatus
    }
  }

  case class Result[A](result: A) extends MaybeResult[A]
  case class Failure[A](status: Status) extends MaybeResult[A] {
  }

  // Extra operations for MaybeResult[Int].
  implicit class MaybeResultIntOps(val result: MaybeResult[Int]) {
    def expect(value: Int): MaybeResult[Int] = result match {
      case Result(res) if res == value => result
      case Result(_)                   => Failure[Int](DomainError())
      case _                           => result // a Failure remains a Failure
    }
  }

  // Combine two, three or four MaybeResult to a MaybeResult of tuple.
  def combine[A, B](a: MaybeResult[A], b: MaybeResult[B]): MaybeResult[(A, B)] = {
    if (a.isDefined) {
      if (b.isDefined) {
        Result((a.getResult, b.getResult))
      } else Failure[(A, B)](b.getStatus)
    } else Failure[(A, B)](a.getStatus)
  }

  def combine[A, B, C](a: MaybeResult[A], b: MaybeResult[B],
                       c: MaybeResult[C]): MaybeResult[(A, B, C)] = {
    val tmp = combine(combine(a, b), c)
    tmp match {
      case Result(((a, b), c)) => Result((a, b, c))
      case Failure(status)     => Failure[(A, B, C)](status)
    }
  }

  def combine[A, B, C, D](a: MaybeResult[A], b: MaybeResult[B],
                          c: MaybeResult[C], d: MaybeResult[D]): MaybeResult[(A, B, C, D)] = {
    val tmp = combine(combine(a, b, c), d)
    tmp match {
      case Result(((a, b, c), d)) => Result((a, b, c, d))
      case Failure(status)        => Failure[(A, B, C, D)](status)
    }
  }

  // Convert an Option to a MaybeResult
  def maybe[A](opt: Option[A], failStatus: Status): MaybeResult[A] = {
    opt match {
      case Some(result) => Result(result)
      case None()       => Failure(failStatus)
    }
  }

  // Special DSL for Option.
  implicit class OptionOps[A](val opt: Option[A]) {
    def toResultOr(failStatus: Status) = {
      maybe(opt, failStatus)
    }
  }


  /**********************************************************************
   *                                                Data Structures     *
   **********************************************************************/

  /*
   * Hold (some) information about the general file structure;
   * The file header is 14 bytes, the offset refers to the beginning of the file header.
   */
  case class FileHeader(size: Int, offset: Int) {
  }

  /*
   * Hold basic information about the bitmap.
   *
   * See https://msdn.microsoft.com/en-us/library/dd183376(v=vs.85).aspx
   *
   * NOTE We assume that
   *  - The number of bits-per-pixel is 24 (RGB format, 8-bit channels);
   *  - No compression is used;
   *  - The palette is empty.
   */
  case class BitmapHeader(width: Int, height: Int) {
  }

  /*
   * Represent an Image, using the usual RGB channels.
   *
   * NOTE use createImage to create a new instance of this class easily.
   */
  case class Image(r: Array[Byte], g: Array[Byte], b: Array[Byte], w: Int, h: Int) {
  }

  @inline // <- in order to "return" the image
  def createImage(width: Int, height: Int) = {
    // NOTE: this variant of the case study uses VLA!
    val surface = width * height
    Image(
      Array.fill[Byte](surface)(0),
      Array.fill[Byte](surface)(0),
      Array.fill[Byte](surface)(0),
      width, height
    )
  }


  /**********************************************************************
   *         I/O functions for WORD, DWORD, LONG, and other helpers     *
   **********************************************************************/

  // Skip a given number of bytes, returning true on success.
  def skipBytes(fis: FIS, count: Int)(implicit state: leon.io.State): Boolean = {
    var i = 0
    var success = true

    while (success && i < count) {
      val opt = fis.tryReadByte()
      success = opt.isDefined
      i += 1
    }

    success
  }

  // Fill the output with copies of the given byte.
  @tailrec // <- a good indicator that the C compiler could optimise out the recursion.
  def writeBytes(fos: FOS, byte: Byte, count: Int): Boolean = {
    if (count == 0) true
    else fos.write(byte) && writeBytes(fos, byte, count - 1)
  }

  // Attempt to read a WORD (16-bit unsigned integer).
  // The result is represented using an Int.
  def maybeReadWord(fis: FIS)(implicit state: leon.io.State): MaybeResult[Int] = {
    // From little to big endian
    val byte2 = fis.tryReadByte
    val byte1 = fis.tryReadByte

    if (byte1.isDefined && byte2.isDefined) Result(constructWord(byte1.get, byte2.get))
    else Failure[Int](ReadError())
  }

  private def constructWord(byte1: Byte, byte2: Byte): Int = {
    // Shift range appropriately to respect unsigned numbers representation
    val signed   = (byte1 << 8) | (byte2 & 0xff) // has Int type
    val unsigned = if (signed < 0) signed + (2 * 32768) else signed

    unsigned
  }

  // Write a WORD
  def writeWord(fos: FOS, word: Int): Boolean = {
    val (b1, b2) = destructWord(word)

    // From big endian to little endian
    fos.write(b2) && fos.write(b1)
  }

  private def destructWord(word: Int): (Byte, Byte) = {
    // Shift range appropriately to respect integer representation
    val signed = if (word >= 32768) word - (2 * 32768) else word

    val b1 = (signed >>> 8).toByte
    val b2 = signed.toByte

    (b1, b2)
  }

  private def lemmaWord(byte1: Byte, byte2: Byte): Boolean = {
    val word = constructWord(byte1, byte2)
    val (b1, b2) = destructWord(word)
    b1 == byte1 && b2 == byte2
  }.holds

  // Attempt to read a DWORD (32-bit unsigned integer).
  // The result is represented using an Int, and values bigger than 2^31 - 1 results in DomainError.
  def maybeReadDword(fis: FIS)(implicit state: leon.io.State): MaybeResult[Int] = {
    // From little to big endian
    def buildInt(b1: Byte, b2: Byte, b3: Byte, b4: Byte): Int = {
      (b4 << 24) | ((b3 & 0xff) << 16) | ((b2 & 0xff) << 8) | (b1 & 0xff)
    }

    val byte1 = fis.tryReadByte
    val byte2 = fis.tryReadByte
    val byte3 = fis.tryReadByte
    val byte4 = fis.tryReadByte // the most significant byte

    if (byte1.isDefined && byte2.isDefined && byte3.isDefined && byte4.isDefined) {
      if (byte4.get >= 0) {
        val dword = buildInt(byte1.get, byte2.get, byte3.get, byte4.get)
        Result(dword)
      } else Failure[Int](DomainError())
    } else Failure[Int](ReadError())
  }

  // Write a DWORD
  def writeDword(fos: FOS, dword: Int): Boolean = {
    val b4 = (dword >>> 24).toByte
    val b3 = (dword >>> 16).toByte
    val b2 = (dword >>> 8).toByte
    val b1 = dword.toByte

    // Big endian to little endian conversion
    fos.write(b1) && fos.write(b2) && fos.write(b3) && fos.write(b4)
  }

  // Attempt to read a LONG (32-bit signed integer).
  // The result is represented using an Int.
  def maybeReadLong(fis: FIS)(implicit state: leon.io.State): MaybeResult[Int] = {
    // From little to big endian
    def buildInt(b1: Byte, b2: Byte, b3: Byte, b4: Byte): Int = {
      (b4 << 24) | ((b3 & 0xff) << 16) | ((b2 & 0xff) << 8) | (b1 & 0xff)
    }

    val byte1 = fis.tryReadByte
    val byte2 = fis.tryReadByte
    val byte3 = fis.tryReadByte
    val byte4 = fis.tryReadByte // the most significant byte

    if (byte1.isDefined && byte2.isDefined && byte3.isDefined && byte4.isDefined) {
      val long = buildInt(byte1.get, byte2.get, byte3.get, byte4.get)
      Result(long)
    } else Failure[Int](ReadError())
  }

  // Write a LONG
  def writeLong(fos: FOS, long: Int): Boolean = {
    val b4 = (long >>> 24).toByte
    val b3 = (long >>> 16).toByte
    val b2 = (long >>> 8).toByte
    val b1 = long.toByte

    // Big endian to little endian conversion
    fos.write(b1) && fos.write(b2) && fos.write(b3) && fos.write(b4)
  }


  /**********************************************************************
   *                               I/O functions for the BMP format     *
   **********************************************************************/

  // Attempt to read the file header.
  // Upon success, 14 bytes have been read.
  def maybeReadFileHeader(fis: FIS)(implicit state: leon.io.State): MaybeResult[FileHeader] = {
    var skipSuccess = skipBytes(fis, WordSize)
    val sizeRes     = maybeReadDword(fis)
    skipSuccess     = skipSuccess && skipBytes(fis, WordSize * 2)
    val offsetRes   = maybeReadDword(fis)

    combine(sizeRes, offsetRes) match {
      case _ if !skipSuccess      => Failure[FileHeader](ReadError())
      case Failure(status)        => Failure[FileHeader](status)
      case Result((size, offset)) => {
        if (14 <= size && 14 + 40 <= offset && offset <= size) Result(FileHeader(size, offset))
        else Failure[FileHeader](InvalidFileHeaderError())
      }
    }
  }

  // Attempt to read the bitmap header (minimal version).
  // Upon success, 18 bytes have been read.
  def maybeReadBitmapHeader(fis: FIS)(implicit state: leon.io.State): MaybeResult[BitmapHeader] = {
    var skipSuccess    = skipBytes(fis, DwordSize)
    val widthRes       = maybeReadLong(fis)
    val heightRes      = maybeReadLong(fis)
    skipSuccess        = skipSuccess && skipBytes(fis, WordSize)
    val bppRes         = maybeReadWord(fis)
    val compressionRes = maybeReadWord(fis)

    combine(widthRes, heightRes, bppRes, compressionRes) match {
      case _ if !skipSuccess                => Failure[BitmapHeader](ReadError())
      case Failure(status)                  => Failure[BitmapHeader](status)
      case Result((w, h, bpp, compression)) =>
        if (w < 0 || h < 0 || bpp != 24 || compression != 0) {
          Failure(InvalidBitmapHeaderError())
        } else Result(BitmapHeader(w, h))
    }
  }

  def loadImageData(fis: FIS, image: Image)(implicit state: leon.io.State): Status = {
    val size = image.w * image.h
    var i = 0
    var status: Status = Success()

    while (status.isSuccess && i < size) {
      val rOpt = fis.tryReadByte()
      val gOpt = fis.tryReadByte()
      val bOpt = fis.tryReadByte()

      if (rOpt.isEmpty || gOpt.isEmpty || bOpt.isEmpty) {
        status = ReadError()
      } else {
        image.r(i) = rOpt.get
        image.g(i) = gOpt.get
        image.b(i) = bOpt.get
      }

      i += 1
    }

    status
  }

  def saveImage(fos: FOS, image: Image): Status = {
    def writeFileHeader(): Boolean = {
      // Size: the headers and 3 channels per pixel, 1 byte per pixel component.
      val size      = 14 + 40 + image.w * image.h * 3
      val reserved  = 0 // two WORDs are reserved
      val offset    = 14 + 40 // after the two headers

      fos.write(0x42.toByte) && fos.write(0x4d.toByte) && // the signature "BM"
      writeDword(fos, size) &&
      writeWord(fos, reserved) && writeWord(fos, reserved) &&
      writeDword(fos, offset)
    }

    def writeBitmapHeader(): Boolean = {
      val size   = 40
      val w      = image.w
      val h      = image.h
      val planes = 1
      val bpp    = 24
      val comp   = 0

      writeDword(fos, size) &&
      writeLong(fos, w) && writeLong(fos, h) &&
      writeWord(fos, planes) &&
      writeWord(fos, bpp) &&
      writeWord(fos, comp) &&
      writeBytes(fos, 0, 22) // the last 22 bytes are all not relevant for us and are set to 0
    }

    def writeImage(): Boolean = {
      val count = image.w * image.h
      var i = 0
      var success = true

      while (success && i < count) {
        success = fos.write(image.r(i)) && fos.write(image.g(i)) && fos.write(image.b(i))
        i += 1
      }

      success
    }

    if (writeFileHeader() && writeBitmapHeader() && writeImage()) Success()
    else WriteError()
  }


  /**********************************************************************
   *                            Kernel & Image Processing Algorithm     *
   **********************************************************************/

  case class Kernel(size: Int, scale: Int, kernel: Array[Int]) {
    /*
     * Apply the kernel on the given channel. Return the new value for pixel component
     * at the given index.
     */
    private def apply(channel: Array[Byte], width: Int, height: Int, index: Int): Byte = {
      // Clamping helper
      def fix(x: Int, side: Int): Int = {
        clamp(x, 0, side - 1)
      }

      // Get the color component at the given position in the range [0, 255]
      def at(col: Int, row: Int): Int = {
        val c = fix(col, width)
        val r = fix(row, height)

        val component = channel(r * width + c) // unsigned
        if (component < 0) component + 255 else component
      }

      val mid = size / 2

      val i = index % width
      val j = index / width

      var res = 0
      var p   = -mid

      while (p <= mid) {
        var q = -mid

        val oldP = p // Fix p for the inner loop (the invariant is not automatically inferred)
        while (q <= mid) {
          val kcol = p + mid
          val krow = q + mid
          val kidx = krow * size + kcol

          // Here, the += and * operation could overflow
          res += at(i + p, j + q) * kernel(kidx)

          q += 1
        }

        p += 1
      }

      res = clamp(res / scale, 0, 255)
      res.toByte
    }

    def apply(src: Image, dest: Image): Unit = {
      val size = src.w * src.h
      var i = 0

      while (i < size) {
        dest.r(i) = apply(src.r, src.w, src.h, i)
        dest.g(i) = apply(src.g, src.w, src.h, i)
        dest.b(i) = apply(src.b, src.w, src.h, i)

        i += 1
      }
    }
  }


  /**********************************************************************
   *                                                   Main Program     *
   **********************************************************************/

  @extern
  def main(args: Array[String]): Unit = _main()

  def _main(): Int = {
    val res = benchmark()

    if (res != 0) StdOut.println("ERROR")

    res
  }

  def benchmark(): Int = {
    // Note: GenC currently doesn't support string manipulations so
    //       we need to hard code some literals.
    implicit val state = leon.io.newState
    benchmarkKernels("../../../input1.bmp", "output1id.bmp", "output1smooth.bmp", "output1emboss.bmp", "output1blur.bmp", "output1edges.bmp", "output1sharpen.bmp") +
    benchmarkKernels("../../../input2.bmp", "output2id.bmp", "output2smooth.bmp", "output2emboss.bmp", "output2blur.bmp", "output2edges.bmp", "output2sharpen.bmp") +
    benchmarkKernels("../../../input3.bmp", "output3id.bmp", "output3smooth.bmp", "output3emboss.bmp", "output3blur.bmp", "output3edges.bmp", "output3sharpen.bmp") +
    benchmarkKernels("../../../input4.bmp", "output4id.bmp", "output4smooth.bmp", "output4emboss.bmp", "output4blur.bmp", "output4edges.bmp", "output4sharpen.bmp") +
    benchmarkKernels("../../../input5.bmp", "output5id.bmp", "output5smooth.bmp", "output5emboss.bmp", "output5blur.bmp", "output5edges.bmp", "output5sharpen.bmp") +
    benchmarkKernels("../../../input6.bmp", "output6id.bmp", "output6smooth.bmp", "output6emboss.bmp", "output6blur.bmp", "output6edges.bmp", "output6sharpen.bmp") +
    benchmarkKernels("../../../input7.bmp", "output7id.bmp", "output7smooth.bmp", "output7emboss.bmp", "output7blur.bmp", "output7edges.bmp", "output7sharpen.bmp") +
    benchmarkKernels("../../../input7big.bmp", "output7bigid.bmp", "output7bigsmooth.bmp", "output7bigemboss.bmp", "output7bigblur.bmp", "output7bigedges.bmp", "output7bigsharpen.bmp")
  }

  // return 0 on success
  def benchmarkKernels(in: String,
                       outId: String, outSmooth: String, outEmboss: String,
                       outBlur: String, outEdges: String, outSharpen: String
                      )(implicit state: leon.io.State): Int = {
    val input         = FIS.open(in)
    val outputId      = FOS.open(outId)
    val outputSmooth  = FOS.open(outSmooth)
    val outputEmboss  = FOS.open(outEmboss)
    val outputBlur    = FOS.open(outBlur)
    val outputEdges   = FOS.open(outEdges)
    val outputSharpen = FOS.open(outSharpen)

    val kIdentity = Kernel(1, 1, Array(
      1
    ))

    val kSmooth = Kernel(3, 10, Array(
      1, 1, 1,
      1, 2, 1,
      1, 1, 1
    ))

    val kEmboss = Kernel(3, 1, Array(
      -2, -1,  0,
      -1,  1,  1,
       0,  1,  2
    ))

    val kBlur = Kernel(5, 25, Array(
      1, 1, 1, 1, 1,
      1, 1, 1, 1, 1,
      1, 1, 1, 1, 1,
      1, 1, 1, 1, 1,
      1, 1, 1, 1, 1
    ))

    val kEdges = Kernel(5, 1, Array(
      0,  0, -1,  0,  0,
      0,  0, -1,  0,  0,
     -1, -1,  8, -1, -1,
      0,  0, -1,  0,  0,
      0,  0, -1,  0,  0
    ))

    val kSharpen = Kernel(5, 8, Array(
      -1, -1, -1, -1, -1,
      -1,  2,  2,  2, -1,
      -1,  2,  8,  2, -1,
      -1,  2,  2,  2, -1,
      -1, -1, -1, -1, -1
    ))

    if (input.isOpen && outputId.isOpen && outputSmooth.isOpen && outputEmboss.isOpen && outputBlur.isOpen && outputEdges.isOpen && outputSharpen.isOpen) {

      val res = loadHeaders(input) match {
        case Failure(_) => 1
        case Result((w, h)) =>
          val image  = createImage(w, h)
          val status = loadImageData(input, image)
          if (status.isSuccess) {

            // Image loaded successfully, ready for benchmark!
            process(in, image, "id",      kIdentity, outputId)     +
            process(in, image, "smooth",  kSmooth,   outputSmooth) +
            process(in, image, "emboss",  kEmboss,   outputEmboss) +
            process(in, image, "blur",    kBlur,     outputBlur)   +
            process(in, image, "edges",   kEdges,    outputEdges)  +
            process(in, image, "sharpen", kSharpen,  outputSharpen)

          } else 1
      }

      outputSharpen.close()
      outputEdges.close()
      outputBlur.close()
      outputEmboss.close()
      outputSmooth.close()
      outputId.close()
      input.close()

      res
    } else 1
  }

  // return 0 on success
  def process(in: String, src: Image, filter: String, kernel: Kernel, fos: FOS)(implicit state: leon.io.State): Int = {
    var status = 0

    var i = 0
    while (i < BenchmarkRuns) {
      // Compute the processing time, without I/Os
      val t1 = TimePoint.now()

      val dest = createImage(src.w, src.h)
      kernel.apply(src, dest)

      val t2 = TimePoint.now()
      val ms = TimePoint.elapsedMillis(t1, t2)

      // CSV output
      StdOut.print(in)
      StdOut.print(";")
      StdOut.print(filter)
      StdOut.print(";")
      StdOut.println(ms)

      i += 1

      // Save the image on the last run
      if (i == BenchmarkRuns) {
        status = if (saveImage(fos, dest).isSuccess) 0 else 1
      }
    }

    status
  }

  def loadHeaders(fis: FIS)(implicit state: leon.io.State): MaybeResult[(Int, Int)] = {
    val fileHeaderRes   = maybeReadFileHeader(fis)
    val bitmapHeaderRes = maybeReadBitmapHeader(fis)

    combine(fileHeaderRes, bitmapHeaderRes) match {
      case Failure(status) =>
        Failure(status)

      /*
       * Report an error when the file is corrupted, i.e. it's too small.
       * 40 is the minimal bitmap header size, 14 is the file header size.
       * Note that more sanity check could be done but that's not the main
       * point of this example.
       */
      case Result((fh, bh)) if fh.size <= 14 + 40 =>
        Failure(CorruptedDataError())

      case Result((fh, bh)) =>
        // Skip bytes until the start of the bitmap data
        val toSkip  = fh.offset - (14 + 18) // some bytes were already eaten
        val success = skipBytes(fis, toSkip)

        // Break test of size so we avoid overflows.
        if (!success) Failure(CorruptedDataError())
        else if (bh.width == 0 || bh.height == 0) Failure(NoImageError())
        else Result((bh.width, bh.height))
    }
  }

}

