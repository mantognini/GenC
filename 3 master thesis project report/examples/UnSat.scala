
object UnSat {

  def dot(a: Array[Int], b: Array[Int]): Int = {
    // require(a.length == b.length)
    var sum = 0
    var i = 0
    while (i < a.length) {
      sum += a(i) * b(i) // overflow + invalid access
      i += 1
    }
    sum
  }

  def foo = {
    val a = Array(0, 1)
    val b = Array(1, 0, 0)
    dot(a, b)
  }
}

