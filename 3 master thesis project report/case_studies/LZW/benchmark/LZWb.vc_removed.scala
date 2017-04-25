/* Copyright 2009-2016 EPFL, Lausanne */

import leon.lang._
import leon.proof._
import leon.annotation._
import leon.lang.StaticChecks._

import leon.io.{
  // FileInputStream => FIS,  // replaced by an efficient implementation
  // FileOutputStream => FOS, // idem
  StdOut                      // no performance issue with this one.
}

object LZWb_vc_removed {

  // GENERAL NOTES
  // =============
  //
  // Encoding using fixed size of word;
  // Input alphabet is the ASCII range (0-255);
  // A word is made of 16 bits (instead of the classic 12-bit scenario, for simplicity);
  // The dictionary is an array of Buffer where the index is the key;

  // We limit the size of the dictionary to an arbitrary size, less than or equals to 2^16.
  @inline
  val DictionarySize = 8192 // number of buffers in the dictionary

  @inline
  val DictionaryMemorySize = 524288 // DictionarySize * BufferSize

  // We use fix-sized buffers
  @inline
  val BufferSize = 64 // characters

  val AlphabetSize = Byte.MaxValue + -Byte.MinValue

  // Helper for range equality checking
  private def areRangesEqual(a: Array[Byte], b: Array[Byte], from: Int, to: Int): Boolean = {
    a(from) == b(from) && {
      if (from == to) true
      else areRangesEqual(a, b, from + 1, to)
    }
  }

  // A buffer representation using a fix-sized array for memory.
  //
  // NOTE Use `createBuffer()` to get a new buffer; don't attempt to create one yourself.
  case class Buffer(private val array: Array[Byte], private var length: Int) {
    val capacity = array.length

    def isFull: Boolean = length == capacity

    def nonFull: Boolean = length < capacity

    def isEmpty: Boolean = length == 0

    def nonEmpty: Boolean = length > 0

    def isEqual(b: Buffer): Boolean = {
      if (b.length != length) false
      else { isEmpty || areRangesEqual(array, b.array, 0, length - 1) }
    }

    def isRangeEqual(other: Array[Byte], otherStart: Int, otherSize: Int): Boolean = {
      if (size != otherSize) false
      else if (isEmpty) true
      else {
        var i = 0
        var equal = true

        while (equal && i < size) {
          equal = (other(otherStart + i) == array(i))
          i += 1
        }

        equal
      }
    }

    def size = {
      length
    }

    def apply(index: Int): Byte = {
      array(index)
    }

    def append(x: Byte): Unit = {
      array(length) = x

      length += 1
    }

    def dropLast(): Unit = {
      length -= 1
    }

    def clear(): Unit = {
      length = 0
    }

    def set(b: Buffer): Unit = {
      if (b.isEmpty) clear
      else setImpl(b)
    }

    private def setImpl(b: Buffer): Unit = {
      length = b.length

      var i = 0
      while (i < length) {
        array(i) = b.array(i)
        i += 1
      }
    }

  }

  @inline // very important because we cannot return arrays
  def createBuffer(): Buffer = {
    Buffer(Array.fill(BufferSize)(0), 0)
  }


  def tryReadNext(fis: FIS)(implicit state: leon.io.State): Option[Byte] = {
    fis.tryReadByte()
  }

  def writeCodeWord(fos: FOS, cw: CodeWord): Boolean = {
    fos.write(cw.b1) && fos.write(cw.b2)
  }

  def tryReadCodeWord(fis: FIS)(implicit state: leon.io.State): Option[CodeWord] = {
    val b1Opt = fis.tryReadByte()
    val b2Opt = fis.tryReadByte()

    (b1Opt, b2Opt) match {
      case (Some(b1), Some(b2)) => Some(CodeWord(b1, b2))
      case _ => None()
    }
  }

  def writeBytes(fos: FOS, buffer: Buffer): Boolean = {
    var success = true
    var i = 0

    val size = buffer.size

    while (success && i < size) {
      success = fos.write(buffer(i))
      i += 1
    }

    success
  }

  case class CodeWord(b1: Byte, b2: Byte) // a 16-bit code word

  def index2CodeWord(index: Int): CodeWord = {
    // Shift the index in the range [-32768, 32767] to make it signed
    val signed = index - 32768
    // Split it into two byte components
    val b2 = signed.toByte
    val b1 = (signed >>> 8).toByte
    CodeWord(b1, b2)
  }

  def codeWord2Index(cw: CodeWord): Int = {
    // When building the signed integer back, make sure to understand integer
    // promotion with negative numbers: we need to avoid the signe extension here.
    val signed = (cw.b1 << 8) | (0xff & cw.b2)
    signed + 32768
  }


  case class Dictionary(private val memory: Array[Byte], private val pteps: Array[Int], private var nextIndex: Int) {
    // NOTE `pteps` stands for Past The End PointerS. It holds the address in `memory` for the next buffer.
    //
    //      By construction, for any index > 0, the begining of the buffer is stored in pteps[index - 1].
    //
    //      It therefore holds that the length of the buffer at the given `index` is pteps[index] - pteps[index - 1]
    //      for index > 0, and pteps[0] for index == 0.

    val capacity = pteps.length
    def isEmpty = nextIndex == 0

    def nonEmpty = !isEmpty

    def isFull = !nonFull

    def nonFull = {
      nextIndex < capacity && (nextIndex == 0 || (memory.length - pteps(nextIndex - 1) >= BufferSize))
    }

    private def getBufferBeginning(index: Int): Int = {
      if (index == 0) 0
      else pteps(index - 1)
    }

    private def getNextBufferBeginning(): Int = {
      if (nextIndex == 0) 0
      else pteps(nextIndex - 1)
    }

    private def getBufferSize(index: Int): Int = {
      if (index == 0) pteps(0)
      else pteps(index) - pteps(index - 1)
    }

    def lastIndex = {
      nextIndex - 1
    }

    def contains(index: Int): Boolean = {
      index < nextIndex
    }

    def appendTo(index: Int, buffer: Buffer): Boolean = {
      val size  = getBufferSize(index)
      val start = getBufferBeginning(index)

      if (buffer.size < buffer.capacity - size) {
        var i = 0
        while (i < size) {
          buffer.append(memory(start + i))
          i += 1
        }

        true
      } else false
    }

    def insert(b: Buffer): Unit = {
      val start = getNextBufferBeginning()

      var i = 0
      while (i < b.size) {
        memory(start + i) = b(i)
        i += 1
      }

      pteps(nextIndex) = start + i

      nextIndex += 1
    }

    def encode(b: Buffer): Option[CodeWord] = {
      var found = false
      var index = 0

      while (!found && index < nextIndex) {
        val start = getBufferBeginning(index)
        val size  = getBufferSize(index)

        if (b.isRangeEqual(memory, start, size)) {
          found = true
        } else {
          index += 1
        }
      }

      if (found) Some(index2CodeWord(index)) else None()
    }
  }

  @inline // in order to "return" the arrays
  def createDictionary() = {
    Dictionary(Array.fill(DictionaryMemorySize)(0), Array.fill(DictionarySize)(0), 0)
  }


  def initialise(dict: Dictionary): Unit = {
    val buffer = createBuffer()
    var value: Int = Byte.MinValue // Use an Int to avoid overflow issues

    while (value <= Byte.MaxValue) {
      buffer.append(value.toByte) // no truncation here
      dict.insert(buffer)
      buffer.dropLast()
      value += 1
    }
  }

  def encode(fis: FIS, fos: FOS)(implicit state: leon.io.State): Boolean = {
    // Initialise the dictionary with the basic alphabet
    val dictionary = createDictionary()
    initialise(dictionary)

    // Small trick to move the static arrays outside the main encoding function;
    // this helps analysing the C code in a debugger (less local variables) but
    // it actually has no impact on performance (or should, in theory).
    encodeImpl(dictionary, fis, fos)
  }

  def encodeImpl(dictionary: Dictionary, fis: FIS, fos: FOS)(implicit state: leon.io.State): Boolean = {
    var bufferFull = false
    var ioError = false

    val buffer = createBuffer()
    var currentOpt = tryReadNext(fis)

    // Read from the input file all its content, stop when an error occurs
    // (either output error or full buffer)
    while (!bufferFull && !ioError && currentOpt.isDefined) {
      val c = currentOpt.get

      buffer.append(c)
      val code = dictionary.encode(buffer)

      val processBuffer = buffer.isFull || code.isEmpty

      if (processBuffer) {
        // Add s (with c) into the dictionary, if the dictionary size limitation allows it
        if (dictionary.nonFull) {
          dictionary.insert(buffer)
        }

        // Encode s (without c) and print it
        buffer.dropLast()
        val code2 = dictionary.encode(buffer)
        ioError = !writeCodeWord(fos, code2.get)

        // Prepare for next codeword: set s to c
        buffer.clear()
        buffer.append(c)
      }

      bufferFull = buffer.isFull

      currentOpt = tryReadNext(fis)
    }

    // Process the remaining buffer
    if (!bufferFull && !ioError) {
      val code = dictionary.encode(buffer)
      ioError = !writeCodeWord(fos, code.get)
    }

    !bufferFull && !ioError
  }

  def decode(fis: FIS, fos: FOS)(implicit state: leon.io.State): Boolean = {
    // Initialise the dictionary with the basic alphabet
    val dictionary = createDictionary()
    initialise(dictionary)

    decodeImpl(dictionary, fis, fos)
  }

  def decodeImpl(dictionary: Dictionary, fis: FIS, fos: FOS)(implicit state: leon.io.State): Boolean = {
    var illegalInput = false
    var ioError = false
    var bufferFull = false

    var currentOpt = tryReadCodeWord(fis)

    val buffer = createBuffer()

    if (currentOpt.isDefined) {
      val cw = currentOpt.get
      val index = codeWord2Index(cw)

      if (dictionary contains index) {
        bufferFull = !dictionary.appendTo(index, buffer)
        ioError = !writeBytes(fos, buffer)
      } else {
        illegalInput = true
      }

      currentOpt = tryReadCodeWord(fis)
    }

    while (!illegalInput && !ioError && !bufferFull && currentOpt.isDefined) {
      val cw = currentOpt.get
      val index = codeWord2Index(cw)
      val entry = createBuffer()

      if (dictionary contains index) {
        illegalInput = !dictionary.appendTo(index, entry)
      } else if (index == dictionary.lastIndex + 1) {
        entry.set(buffer)
        entry.append(buffer(0))
      } else {
        illegalInput = true
      }

      ioError = !writeBytes(fos, entry)
      bufferFull = buffer.isFull

      if (!bufferFull) {
        val tmp = createBuffer()
        tmp.set(buffer)
        tmp.append(entry(0))
        if (dictionary.nonFull) {
          dictionary.insert(tmp)
        }

        buffer.set(entry)
      }

      currentOpt = tryReadCodeWord(fis)
    }

    !illegalInput && !ioError && !bufferFull
  }


  sealed abstract class Status
  case class Success()     extends Status
  case class OpenError()   extends Status
  case class EncodeError() extends Status
  case class DecodeError() extends Status

  implicit def status2boolean(s: Status): Boolean = s match {
    case Success() => true
    case _         => false
  }

  def _main() = {
    implicit val state = leon.io.newState

    def statusCode(s: Status): Int = s match {
      case Success()     => StdOut.println("success");            0
      case OpenError()   => StdOut.println("couldn't open file"); 1
      case EncodeError() => StdOut.println("encoding failed");    2
      case DecodeError() => StdOut.println("decoding failed");    3
    }

    def encodeFile(): Status = {
      val input = FIS.open("input.txt")
      val encoded = FOS.open("encoded.txt")

      val res =
        if (input.isOpen && encoded.isOpen) {
          if (encode(input, encoded)) Success()
          else EncodeError()
        } else OpenError()

      encoded.close
      input.close

      res
    }

    def decodeFile(): Status = {
      val encoded = FIS.open("encoded.txt")
      val decoded = FOS.open("decoded.txt")

      val res =
        if (encoded.isOpen && decoded.isOpen) {
          if (decode(encoded, decoded)) Success()
          else DecodeError()
        } else OpenError()

      decoded.close
      encoded.close

      res
    }

    val r1 = encodeFile()
    statusCode(if (r1) decodeFile() else r1)
  }

  @extern
  def main(args: Array[String]): Unit = _main()

}

