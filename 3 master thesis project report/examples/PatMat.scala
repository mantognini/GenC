import leon.annotation.extern

object PatMat {

  case class A(var x: Int)

  abstract class Base
  case class Derived1(a: A) extends Base
  case class Derived2(a: A) extends Base

  def foo(b: Base): Unit = b match {
    case Derived1(a)              => a.x = 100
    case Derived2(a) if a.x == 42 => a.x = 58
    case Derived2(a)              => a.x = 0
  }

  def scope: Derived2 = {
    val b = Derived2(A(42))
    foo(b)
    b
  } ensuring { res => res.a.x == 58 }

  def _main(): Int = {
    val b = scope
    b.a.x - 58
  } ensuring { _ == 0 }

  @extern
  def main(args: Array[String]): Unit = _main()
}

