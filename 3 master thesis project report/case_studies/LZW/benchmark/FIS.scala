/* Copyright 2009-2016 EPFL, Lausanne */

import leon.io.{ State }
import leon.lang.{ Option, Some, None }
import leon.lang.StaticChecks._

object FIS {

  def open(filename: String)(implicit state: State): FIS = {
    state.seed += 1

    new FIS(
      try {
        // Check whether the stream can be opened or not
        val in = new java.io.BufferedInputStream(new java.io.FileInputStream(filename))
        Some(in)
      } catch {
        case _: Throwable => None()
      }
    )
  }

}

case class FIS private (var in: Option[java.io.InputStream]) {

  def close()(implicit state: State): Boolean = {
    state.seed += 1

    in match {
      case Some(r) => r.close()
      case _ => ()
    }
    in = None()
    true // This implementation never fails
  }

  def isOpen: Boolean = in.isDefined

  def readByte()(implicit state: State): Byte = {
    require(isOpen)
    tryReadByte() getOrElse 0
  }

  def tryReadByte()(implicit state: State): Option[Byte] = {
    require(isOpen)
    state.seed += 1

    val (check, value) = nativeReadByte(state.seed)
    if (check) Some(value)
    else None()
  }

  // Implementation detail
  private def nativeReadByte(seed: BigInt): (Boolean, Byte) = {
    require(isOpen)
    val b = Array[Byte](0)
    val read = in.get.read(b)

    if (read != 1) (false, 0)
    else (true, b(0))
  }

}

