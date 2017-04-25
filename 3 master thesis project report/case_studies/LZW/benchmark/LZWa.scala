/* Copyright 2009-2016 EPFL, Lausanne */

import leon.lang._
import leon.proof._
import leon.annotation._

import leon.io.{
  // FileInputStream => FIS,  // replaced by an efficient implementation
  // FileOutputStream => FOS, // idem
  StdOut                      // no performance issue with this one.
}

object LZWa {

  // GENERAL NOTES
  // =============
  //
  // Encoding using fixed size of word;
  // Input alphabet is the ASCII range (0-255);
  // A word is made of 16 bits (instead of the classic 12-bit scenario, for simplicity);
  // The dictionary is an array of Buffer where the index is the key;

  // We limit the size of the dictionary to an arbitrary size, less than or equals to 2^16.
  @inline
  val DictionarySize = 8192

  // We use fix-sized buffers
  @inline
  val BufferSize = 64 // characters

  val AlphabetSize = Byte.MaxValue + -Byte.MinValue

  private def lemmaSize: Boolean = {
    DictionarySize >= AlphabetSize &&
    BufferSize > 0 &&
    AlphabetSize > 0 &&
    DictionarySize <= 65536 // Cannot encode more index using only 16-bit codewords
  }.holds

  // Helper for range equality checking
  private def isRangeEqual(a: Array[Byte], b: Array[Byte], from: Int, to: Int): Boolean = {
    require(0 <= from && from <= to && to < a.length && to < b.length)
    a(from) == b(from) && {
      if (from == to) true
      else isRangeEqual(a, b, from + 1, to)
    }
  }

  private def allValidBuffers(buffers: Array[Buffer]): Boolean = {
    def rec(from: Int): Boolean = {
      require(0 <= from && from <= buffers.length)
      if (from < buffers.length) buffers(from).isValid && rec(from + 1)
      else true
    }

    rec(0)
  }


  // A buffer representation using a fix-sized array for memory.
  //
  // NOTE Use `createBuffer()` to get a new buffer; don't attempt to create one yourself.
  case class Buffer(private val array: Array[Byte], private var length: Int) {
    val capacity = array.length
    require(isValid)

    def isValid: Boolean = length >= 0 && length <= capacity && capacity == BufferSize

    def isFull: Boolean = length == capacity

    def nonFull: Boolean = length < capacity

    def isEmpty: Boolean = length == 0

    def nonEmpty: Boolean = length > 0

    def isEqual(b: Buffer): Boolean = {
      if (b.length != length) false
      else { isEmpty || isRangeEqual(array, b.array, 0, length - 1) }
    }

    def size = {
      length
    } ensuring { res => 0 <= res && res <= capacity }

    def apply(index: Int): Byte = {
      require(index >= 0 && index < length)
      array(index)
    }

    def append(x: Byte): Unit = {
      require(nonFull)

      array(length) = x

      length += 1
    } ensuring { _ => isValid }

    def dropLast(): Unit = {
      require(nonEmpty)

      length -= 1
    } ensuring { _ => isValid }

    def clear(): Unit = {
      length = 0
    } ensuring { _ => isEmpty && isValid }

    def set(b: Buffer): Unit = {
      if (b.isEmpty) clear
      else setImpl(b)
    } ensuring { _ => b.isValid && isValid && isEqual(b) }

    private def setImpl(b: Buffer): Unit = {
      require(b.nonEmpty)

      length = b.length

      var i = 0
      (while (i < length) {
        array(i) = b.array(i)
        i += 1
      }) invariant { // TIMEOUT
        0 <= i && i <= length &&
        // lengthCheckpoint == b.length && lengthCheckpoint == length && // no mutation of the length
        isValid && nonEmpty &&
        length == b.length &&
        (i > 0 ==> isRangeEqual(array, b.array, 0, i - 1)) // avoid OutOfBoundAccess
      }
    } ensuring { _ => b.isValid && isValid && nonEmpty && isEqual(b) }

  }

  @inline // very important because we cannot return arrays
  def createBuffer(): Buffer = {
    Buffer(Array.fill(BufferSize)(0), 0)
  } ensuring { b => b.isEmpty && b.nonFull && b.isValid }


  def tryReadNext(fis: FIS)(implicit state: leon.io.State): Option[Byte] = {
    require(fis.isOpen)
    fis.tryReadByte()
  }

  def writeCodeWord(fos: FOS, cw: CodeWord): Boolean = {
    require(fos.isOpen)
    fos.write(cw.b1) && fos.write(cw.b2)
  }

  def tryReadCodeWord(fis: FIS)(implicit state: leon.io.State): Option[CodeWord] = {
    require(fis.isOpen)
    val b1Opt = fis.tryReadByte()
    val b2Opt = fis.tryReadByte()

    (b1Opt, b2Opt) match {
      case (Some(b1), Some(b2)) => Some(CodeWord(b1, b2))
      case _ => None()
    }
  }

  def writeBytes(fos: FOS, buffer: Buffer): Boolean = {
    require(fos.isOpen && buffer.nonEmpty)
    var success = true
    var i = 0

    val size = buffer.size

    (while (success && i < size) {
      success = fos.write(buffer(i))
      i += 1
    }) invariant {
      0 <= i && i <= size
    }

    success
  }

  case class CodeWord(b1: Byte, b2: Byte) // a 16-bit code word

  def index2CodeWord(index: Int): CodeWord = {
    require(0 <= index && index < 65536) // unsigned index
    // Shift the index in the range [-32768, 32767] to make it signed
    val signed = index - 32768
    // Split it into two byte components
    val b2 = signed.toByte
    val b1 = (signed >>> 8).toByte
    CodeWord(b1, b2)
  }

  def codeWord2Index(cw: CodeWord): Int = {
    // When building the signed integer back, make sure to understand integer
    // promotion with negative numbers: we need to avoid the sign extension here.
    val signed = (cw.b1 << 8) | (0xff & cw.b2)
    signed + 32768
  } ensuring { res => 0 <= res && res < 65536 }


  case class Dictionary(private val buffers: Array[Buffer], private var nextIndex: Int) {
    val capacity = buffers.length
    require(isValid)

    def isValid = 0 <= nextIndex && nextIndex <= capacity && capacity == DictionarySize && allValidBuffers(buffers)

    def isEmpty = nextIndex == 0

    def nonEmpty = !isEmpty

    def isFull = nextIndex == capacity

    def nonFull = nextIndex < capacity

    def lastIndex = {
      require(nonEmpty)
      nextIndex - 1
    } ensuring { res => 0 <= res && res < capacity }

    def contains(index: Int): Boolean = {
      require(0 <= index)
      index < nextIndex
    }

    def appendTo(index: Int, buffer: Buffer): Boolean = {
      require(0 <= index && contains(index))

      val size = buffers(index).size

      assert(buffer.capacity == BufferSize)
      if (buffer.size < buffer.capacity - size) {
        assert(buffer.nonFull)

        var i = 0
        (while (i < size) {
          buffer.append(buffers(index)(i))
          i += 1
        }) invariant {
          0 <= i && i <= size &&
          (i < size ==> buffer.nonFull)
        }

        true
      } else false
    }

    def insert(b: Buffer): Unit = {
      require(nonFull && b.nonEmpty)
      buffers(nextIndex).set(b)
      nextIndex += 1
    }

    def encode(b: Buffer): Option[CodeWord] = {
      require(b.nonEmpty)

      var found = false
      var i = 0

      (while (!found && i < nextIndex) {
        if (buffers(i).isEqual(b)) {
          found = true
        } else {
          i += 1
        }
      }) invariant {
        0 <= i && i <= nextIndex && i <= capacity &&
        isValid &&
        (found ==> (i < nextIndex && buffers(i).isEqual(b)))
      }

      if (found) Some(index2CodeWord(i)) else None()
    }
  }

  @inline // in order to "return" the arrays
  def createDictionary() = {
    Dictionary(Array.fill(DictionarySize){ createBuffer() }, 0)
  } ensuring { res => res.isEmpty }

  def initialise(dict: Dictionary): Unit = {
    require(dict.isEmpty) // initialise only fresh dictionaries

    val buffer = createBuffer()
    assert(buffer.isEmpty)

    var value: Int = Byte.MinValue // Use an Int to avoid overflow issues

    (while (value <= Byte.MaxValue) {
      buffer.append(value.toByte) // no truncation here
      dict.insert(buffer)
      buffer.dropLast()
      value += 1
    }) invariant {
      dict.nonFull &&
      buffer.isEmpty &&
      value >= Byte.MinValue && value <= Byte.MaxValue + 1 // last iteration goes "overflow" on Byte
    }
  } ensuring { _ => dict.isValid && dict.nonEmpty }

  def encode(fis: FIS, fos: FOS)(implicit state: leon.io.State): Boolean = {
    require(fis.isOpen && fos.isOpen)

    // Initialise the dictionary with the basic alphabet
    val dictionary = createDictionary()
    initialise(dictionary)

    // Small trick to move the static arrays outside the main encoding function;
    // this helps analysing the C code in a debugger (less local variables) but
    // it actually has no impact on performance (or should, in theory).
    encodeImpl(dictionary, fis, fos)
  }

  def encodeImpl(dictionary: Dictionary, fis: FIS, fos: FOS)(implicit state: leon.io.State): Boolean = {
    require(fis.isOpen && fos.isOpen && dictionary.nonEmpty)

    var bufferFull = false
    var ioError = false

    val buffer = createBuffer()
    assert(buffer.isEmpty && buffer.nonFull)

    var currentOpt = tryReadNext(fis)

    // Read from the input file all its content, stop when an error occurs
    // (either output error or full buffer)
    (while (!bufferFull && !ioError && currentOpt.isDefined) {
      val c = currentOpt.get

      assert(buffer.nonFull)
      buffer.append(c)
      assert(buffer.nonEmpty)

      val code = dictionary.encode(buffer)

      val processBuffer = buffer.isFull || code.isEmpty

      if (processBuffer) {
        // Add s (with c) into the dictionary, if the dictionary size limitation allows it
        if (dictionary.nonFull) {
          dictionary.insert(buffer)
        }

        // Encode s (without c) and print it
        buffer.dropLast()
        assert(buffer.nonFull)
        assert(buffer.nonEmpty)
        val code2 = dictionary.encode(buffer)

        assert(code2.isDefined) // (*)
        // To prove (*) we might need to:
        //  - prove the dictionary can encode any 1-length buffer
        //  - the buffer was empty when entering the loop or
        //    that the initial buffer was in the dictionary.
        ioError = !writeCodeWord(fos, code2.get)

        // Prepare for next codeword: set s to c
        buffer.clear()
        buffer.append(c)
        assert(buffer.nonEmpty)
      }

      bufferFull = buffer.isFull

      currentOpt = tryReadNext(fis)
    }) invariant {
      bufferFull == buffer.isFull &&
      ((!bufferFull && !ioError) ==> buffer.nonEmpty) // it might always be true...
    }

    // Process the remaining buffer
    if (!bufferFull && !ioError) {
      val code = dictionary.encode(buffer)
      assert(code.isDefined) // See (*) above.
      ioError = !writeCodeWord(fos, code.get)
    }

    !bufferFull && !ioError
  }

  def decode(fis: FIS, fos: FOS)(implicit state: leon.io.State): Boolean = {
    require(fis.isOpen && fos.isOpen)

    // Initialise the dictionary with the basic alphabet
    val dictionary = createDictionary()
    initialise(dictionary)

    decodeImpl(dictionary, fis, fos)
  }

  def decodeImpl(dictionary: Dictionary, fis: FIS, fos: FOS)(implicit state: leon.io.State): Boolean = {
    require(fis.isOpen && fos.isOpen && dictionary.nonEmpty)

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

    (while (!illegalInput && !ioError && !bufferFull && currentOpt.isDefined) {
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
    }) invariant {
      dictionary.nonEmpty
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

