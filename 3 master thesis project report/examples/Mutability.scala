import leon.annotation.extern

object Mutability {

  case class A(var x: Int)

  def scope: A = {
    var i = 0
    def updateAndInc(a: A) {
      i += 1   // might overflow
      a.x += i // might overflow
    }

    val a = A(41)
    updateAndInc(a)
    assert(a.x == 42)

    a
  }

  def _main(): Int = {
    val a = scope
    a.x - 42 // == 0
  } ensuring { _ == 0 }

  @extern
  def main(args: Array[String]): Unit = _main()
}

