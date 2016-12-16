
import leon.annotation.extern

object ArrayExample {

  def _main(): Int = {
    val array = Array((42, true), (0, false), (99, false))
    array(1)._1
  } ensuring { _ == 0 }

  @extern
  def main(args: Array[String]): Unit = _main()

}

