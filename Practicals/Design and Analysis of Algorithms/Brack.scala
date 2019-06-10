/** Import is for readLine so that we can write input directly to the program */
import scala.io.StdIn

object Brack{
	//Maximum length of word so we can define our arrays in dynamic programming
	val MAXWORD = 30

	//Operation to take 'A', 'B' and 'C' to corresponding Ints
  def LetterToInt(a: Char) : Int = {
		if(a == 'A' || a == 'B' || a == 'C'){
			return (a.toInt - 'A'.toInt);
		} else{
			println("Please only Letters from A,B,C.")
			sys.exit
		}
	}

  //Defining the op array for everything to use
  val op = Array.ofDim[Int](3,3)
  op(0)(0) = 1; op(0)(1) = 1; op(0)(2) = 0
	op(1)(0) = 2; op(1)(1) = 1; op(1)(2) = 0
	op(2)(0) = 0; op(2)(1) = 2; op(2)(2) = 2

  /** Read file into array (discarding the EOF character) */
  def readFile(fname: String) : Array[Char] =
    scala.io.Source.fromFile(fname).toArray.init


  /* Functions below here need to be implemented */


	//TASK 1
	//PossibleRec checks whether bracketing to something is possible recursively
	//Checks whether w(i,j) can be bracketed to z

	def PossibleRec(w: Array[Int], i: Int, j: Int, z:Int): Boolean =
  {
	   if(j-i==1)
     {
       if(w(i)==z)
          return true
        return false
     }
     var ok = 0
     for(k <- i + 1 until j if(ok==0))
      {
        if(z==0)
        {
          if(PossibleRec(w,i,k,0)==true && PossibleRec(w,k,j,2)==true)
              ok=1;

          if(PossibleRec(w,i,k,1)==true && PossibleRec(w,k,j,2)==true)
              ok=1;

          if(PossibleRec(w,i,k,2)==true && PossibleRec(w,k,j,0)==true)
              ok=1;
        }
        if(z==1)
        {
          if(PossibleRec(w,i,k,0)==true && PossibleRec(w,k,j,0)==true)
              ok=1

          if(PossibleRec(w,i,k,0)==true && PossibleRec(w,k,j,1)==true)
              ok=1

          if(PossibleRec(w,i,k,1)==true && PossibleRec(w,k,j,1)==true)
              ok=1
        }
        if(z==2)
        {
          if(PossibleRec(w,i,k,1)==true && PossibleRec(w,k,j,0)==true)
              ok=1

          if(PossibleRec(w,i,k,2)==true && PossibleRec(w,k,j,1)==true)
              ok=1

          if(PossibleRec(w,i,k,2)==true && PossibleRec(w,k,j,2)==true)
              ok=1
        }
      }
      if(ok==1)
        return true
      return false
	}


	//TASK 2
	//NumberRec which checks the ways you get a result recursively
	//Computes number of ways w(i,j) can be bracketed to get z

	def NumberRec(w: Array[Int], i: Int, j: Int, z:Int): Int =
  {
    if(j-i==1)
    {
      if(w(i)==z)
         return 1
       return 0
    }
    var ok = 0
    for(k <- i + 1 until j)
     {
       for(x<- 0 to 2)
       for(y<- 0 to 2)
       {
         if(op(x)(y)==z)
          ok+=NumberRec(w,i,k,x)*NumberRec(w,k,j,y)
       }
     }
     return ok
	}


	//TASK 3
  /*
  PossibleRec and NumberRec have both the same complexity

  In each iteration the complexity is n and they call recursively for each value so
      t(n)<= 2 * sumt(i)
      t(1) = 1
      => t(n) <= t(n-1)*7
      => Time complexity O(7^n)

  for n = 4
        Bracketing values for ABBA
        A can be achieved in 2 ways
        B can be achieved in 1 way
        C can be achieved in 2 ways

        real	0m0.593s
        user	0m0.782s
        sys	0m0.054s

  for n = 8
        Bracketing values for ABBAABBA
        A can be achieved in 170 ways
        B can be achieved in 95 ways
        C can be achieved in 164 ways

        real	0m0.839s
        user	0m1.498s
        sys	0m0.075s

  for n = 9
        Bracketing values for ABBAABBAA
        A can be achieved in 331 ways
        B can be achieved in 862 ways
        C can be achieved in 237 ways

        real	0m1.330s
        user	0m2.013s
        sys	0m0.075s

  for n = 10
        Bracketing values for ABBAABBAAB
        A can be achieved in 485 ways
        B can be achieved in 3780 ways
        C can be achieved in 597 ways

        real	0m4.189s
        user	0m4.870s
        sys	0m0.106s
  The test results show roughly the time difference required. t(10)/t(9)

  */


	//You may find the following class useful for Task 7
	// Binary tree class
	abstract class BinaryTree
	case class Node (left : BinaryTree, right : BinaryTree) extends BinaryTree
	case class Leaf (value : Char) extends BinaryTree

	//Printing for a binary tree
	def print_tree(t : BinaryTree)
  {
      if(t==null)
        return
      t match
      {
        case Node(left, right) =>
        {
          (left, right) match
          {
            case (Leaf(value1),Leaf(value2)) =>
            {
                print(value1.toString ++ value2.toString)
            }
            case other =>
            {
              print("(")
              print_tree(left)
              print(")")
              print("(")
              print_tree(right)
              print(")")
            }
          }
        }
        case Leaf(value) =>
        {
          print(value.toString)
        }
      }
	}

	//These arrays should hold the relevant data for dynamic programming
	var poss = Array.ofDim[Boolean](MAXWORD, MAXWORD, 3)
	var ways = Array.ofDim[Int](MAXWORD, MAXWORD, 3)
	var exp = Array.ofDim[BinaryTree](MAXWORD, MAXWORD, 3)


	//Task 4, 5, and 7(optional)
	//TODO Fill out arrays with dynamic programming solution


	def Tabulate(w: Array[Int], n: Int): Unit =
  {
    for(i <- 0 until n)
    {
        ways(i)(i+1)(w(i))=1
        //var q = new Leaf((w(i)+'A'.toInt).toChar)
        exp(i)(i+1)(w(i)) = new Leaf((w(i)+'A'.toInt).toChar)
    }
    for(d <- 2 to n)
    {
      for(i <-0 to n-d)
      {
        var j = i + d
        for(k <-i+1 until j)
        {
          for(z <- 0 to 2)
          for(x <- 0 to 2)
          for(y <- 0 to 2)
          {
            if(op(x)(y)==z && ways(i)(k)(x) * ways(k)(j)(y)!=0)
            {
              ways(i)(j)(z) += ways(i)(k)(x) * ways(k)(j)(y)
              var q = new Node(exp(i)(k)(x),exp(k)(j)(y))
              exp(i)(j)(z) = q
            }
          }
        }
      }
    }
	}
  //the function runs in O(n^3).

	//Task 6
  /*
		We approximate the upper bound of number of ways for n, as the n th Catalan number. (1/(n+1)*C(2n,n))
    The maximum word length is 20. Above 20, the upper bound of number of possibilities exceeds the upper bound of int.

    The program should take o(n^3).


    for n = 10

    Bracketing values for ABBAABBAAB
    A can be achieved 485 ways
    For example:
    B can be achieved 3780 ways
    For example:
    C can be achieved 597 ways
    For example:

    real    0m0.673s
    user    0m1.499s
    sys     0m0.061s


    for n = 20

    Bracketing values for ABBAABBAABABBAABBAA
    A can be achieved 117903051 ways
    For example:
    B can be achieved 266318748 ways
    For example:
    C can be achieved 93416901 ways
    For example:

    real    0m0.666s
    user    0m1.441s
    sys     0m0.060s

    for n = 30

    Bracketing values for ABBAABBAABABBAABBAABABBAABBAA
    A can be achieved 984844820 ways
    For example:
    B can be achieved 25393088 ways
    For example:
    C can be achieved 1589799684 ways
    For example:

    real    0m0.730s
    user    0m1.593s
    sys     0m0.126s


		The dynamic version runs a lot faster, but uses more memory.
    The tests and their run time is in accordance with what was said before.
  */


/** The main method just selects which piece of functionality to run */
  def main(args: Array[String]) = {

    // string to print if error occurs
    val errString =
      "Usage: scala Brack -PossibleRec [file]\n"+
      "     | scala Brack -NumberRec [file]\n"+
      "     | scala Brack -Tabulate [file]\n"

		if (args.length > 2){
			println(errString)
			sys.exit
		}

    //Get the plaintext, either from the file whose name appears in position
    //pos, or from standard input
    def getPlain(pos: Int) =
      if(args.length==pos+1) readFile(args(pos)) else StdIn.readLine.toArray

    // Check there are at least n arguments
    def checkNumArgs(n: Int) = if(args.length<n){println(errString); sys.exit}

    // Parse the arguments, and call the appropriate function
    checkNumArgs(1)
		val plain = getPlain(1)
    val command = args(0)

		//Making sure the letters are of the right type
		val len = plain.length
		var plainInt = new Array[Int](len)
		if (len > MAXWORD){
			println("Word Too Long! Change MAXWORD")
			sys.exit;
		} else {
    	for (i <- 0 until len){
				plainInt(i) = LetterToInt(plain(i))
			}
		}

		//Executing appropriate command
    if(command=="-PossibleRec"){
		println("Bracketing values for "+ plain.mkString(""))
		for(i<-0 to 2){
			if(PossibleRec(plainInt, 0, len, i)){
				println(('A'.toInt + i).toChar + " is Possible");
			}
			else{
				println(('A'.toInt + i).toChar + " is not Possible");
			}
		}
    }
    else if(command=="-NumberRec"){
		var z: Int = 0
		println("Bracketing values for "+ plain.mkString(""))
    println(len)
		for(i<-0 to 2){
			z = NumberRec(plainInt, 0, len, i)
			if(z == 1){
				printf(('A'.toInt + i).toChar+ " can be achieved in %d way\n", z)
			}
			else{
				printf(('A'.toInt + i).toChar+ " can be achieved in %d ways\n", z)
			}
		}
    }

    else if(command=="-Tabulate"){
		Tabulate(plainInt,len)
		println("Bracketing values for "+ plain.mkString(""))
		for(v<-0 to 2){
		var z: Int = ways(0)(len)(v)
			if(z==0){
			println(('A'.toInt + v).toChar+ " cannot be achieved")
			}
			else if(z==1){
				printf(('A'.toInt + v).toChar+ " can be achieved %d way\n", z)
				printf("For example:")
				print_tree(exp(0)(len)(v))
				printf("\n")
			}
			else if (z > 1){
				printf(('A'.toInt + v).toChar+ " can be achieved %d ways\n", z)
				printf("For example:")
				print_tree(exp(0)(len)(v))
				printf("\n")
			}
		}
    }
    else println(errString)
  }
}

/*
dinu@dinu-G751JM:~/Desktop/Practicals/DAA$ scala Brack -Tabulate
ABBA
Bracketing values for ABBA
A can be achieved 2 ways
For example:(AB)(BA)
B can be achieved 1 way
For example:(A)((B)(BA))
C can be achieved 2 ways
For example:((AB)(B))(A)
*/
