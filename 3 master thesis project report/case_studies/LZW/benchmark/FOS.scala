/* Copyright 2009-2016 EPFL, Lausanne */

import leon.io.{ State }
import leon.lang.{ Option, Some, None }
import leon.lang.StaticChecks._

object FOS {

  def open(filename: String): FOS = {
    new FOS(
      try {
        // Check whether the stream can be opened or not (and empty the file)
        val out = new java.io.BufferedOutputStream(new java.io.FileOutputStream(filename, false))
        Some(out)
      } catch {
        case _: Throwable => None()
      }
    )
  }

}

case class FOS private (var out: Option[java.io.OutputStream]) {

  def close(): Boolean = {
    out match {
      case Some(w) => w.close()
      case _ => ()
    }
    out = None()
    true // This implementation never fails
  }

  def isOpen(): Boolean = out.isDefined

  def write(x: Byte): Boolean = {
    require(isOpen)
    try {
      val b = Array[Byte](x)
      out.get.write(b, 0, 1)
      true
    } catch {
      case _: Throwable => false
    }
  }

}

