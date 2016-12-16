
import leon.annotation.extern
// import leon.lang._

object ClassHierarchy {

  // Example of class hierarchy
  abstract class Top

  case class One(x: Int) extends Top

  abstract class Derived extends Top {
    def sum: Int
  }

  case class Two(x: Int, y: Int) extends Derived {
    def sum: Int = x + y // can overflow
  }

  case class Three(x: Int, y: Int, z: Int) extends Derived {
    def sum: Int = x + y + z // can overflow
  }

  def foo = {
    val x = One(1)
    val y = Two(1, 2)
    bar(x, y)
  }

  def bar(one: One, d: Derived) = one.x + d.sum // can overflow

  def fun(b: Top) = b.isInstanceOf[One]
  def gun(b: Top) = {
    require(b.isInstanceOf[One])
    b.asInstanceOf[One].x
  }

  def _main(): Int = {
    val one = One(42)
    if (foo == 4 && fun(one) && gun(one) == 42) 0
    else 1
  } ensuring { _ == 0 }

  @extern
  def main(args: Array[String]): Unit = _main()

}

