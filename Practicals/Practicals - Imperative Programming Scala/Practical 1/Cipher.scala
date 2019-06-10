object Cipher{
  /** Bit-wise exclusive-or of two characters */
  def xor(a: Char, b: Char) : Char = (a.toInt ^ b.toInt).toChar

  /** Print ciphertext in octal */
  def showCipher(cipher: Array[Char]) =
    for(c <- cipher){ print(c/64); print(c%64/8); print(c%8); print(" ") }

  /** Read file into array */
  def readFile(fname: String) : Array[Char] =
    scala.io.Source.fromFile(fname).toArray

  /** Read from stdin in a similar manner */
  def readStdin() = scala.io.Source.stdin.toArray

  /* ----- Functions below here need to be implemented ----- */

  /** Encrypt plain using key; can also be used for decryption */
  def encrypt(key: Array[Char], plain: Array[Char]) : Array[Char] =
    {
      var ans = new Array[Char](plain.size)
      var i = 0
      for(i <- 0 until plain.size)
      {
        ans(i) = (plain(i).toInt ^ key(i%(key.size))).toChar
      }
      return ans
    }

    def verifyKey(v: Array[Char], pos: Int) : (Int, Array[Char]) =
      {
          var ans = v.size
          var i = v.size - 1
          while(i>0)
          {
              var ok = true
              // check if case is true for i and update ans if yes
              // I for i in (i,n)
              var j = 0
              // Invariant : ok = ( v[0..j) == v[i..i+j) and 0<=j<=v.size-i
              while(j<v.size-i)
              {
                  if(v(j)!=v(i+j))
                      ok = false
                  j+=1
              }
              if(ok == true)
                  ans = i
              // I for i in [i,n)
              i-=1;
          }
          // I for 0<=i<n <=> Postcondition correct implied by i = 0
          if(ans>v.size-2)
              return(0,v)
          else
          {
              var pos2 = pos
              pos2 -= (pos2/ans+1)*ans
              var j = -pos2
              var curr = new Array[Char](ans)
              var k = 0
              for(i <- j until math.min(j+ans,v.size))
              {
                curr(i-j)=v(i)
                k = i-j
              }
              i=0
              k+=1
              if(k<ans)
              {
                  var p = j-1
                  i = ans-1
                  while(i>=k)
                  {
                      curr(i)=v(p)
                      i-=1
                      p-=1
                  }
              }

            for(k <- 0 until curr.size)
              print(curr(k).toChar)
              println("")
              return(1,curr)
          }

      }
    /** Try to decrypt ciphertext, using crib as a crib */
    def tryCrib(crib: Array[Char], ciphertext: Array[Char]) : Array[Char] =
      {
          //var i = 0
          for(i <-0 until ((ciphertext.size) - (crib.size) + 1))
          {
            var j = 0
            var curr = new Array[Char](crib.size)
            for(j<-i until i+crib.size)
              curr(j-i) = (crib(j-i).toInt ^ ciphertext(j).toInt ).toChar
            var x = verifyKey(curr,i)
            if(x._1 == 1)
              return x._2
          }
          var x = new Array[Char](12)
          return x
      }

  /** The first optional statistical test, to guess the length of the key */
  def crackKeyLen(ciphertext: Array[Char]) =
    {
      for(i <- 1 to 30)
      {
        var ans = 0
        for(j <- 0 until ciphertext.length - i)
          if(ciphertext(j) == ciphertext(i+j))
            ans+=1
        println(i.toString ++ " " ++ ans.toString)
      }
    }

  /** The second optional statistical test, to guess characters of the key. */
  def crackKey(klen: Int, ciphertext: Array[Char]) =
    {
        for(i <- 0 until ciphertext.length - klen)
        {
            //println(ciphertext(i).toString ++ " " ++ ciphertext(i+klen).toString)
            var j = 0
            while(i+klen*j < ciphertext.length)
            {
              if(ciphertext(i) == ciphertext (i+klen*j) )
              {

                  var x = (ciphertext(i).toInt) ^ ((' ').toInt)
                  if(32<=x && x <=127)
                  {
                    println((i%klen).toString ++ " " ++ (x.toChar).toString)
                  }
              }
              j+=1
            }
        }
    }

/** The main method just selects which piece of functionality to run */
  def main(args: Array[String]) =
    {
      // string to print if error occurs
      val errString =
        "Usage: scala Cipher (-encrypt|-decrypt) key [file]\n"+
        "     | scala Cipher -crib crib [file]\n"+
        "     | scala Cipher -crackKeyLen [file]\n"+
        "     | scala Cipher -crackKey len [file]"

      // Get the plaintext, either from the file whose name appears in position
      // pos, or from standard input
      def getPlain(pos: Int) =
        if(args.length==pos+1) readFile(args(pos)) else readStdin

      // Check there are at least n arguments
      def checkNumArgs(n: Int) = if(args.length<n){println(errString); sys.exit}

      // Parse the arguments, and call the appropriate function
      checkNumArgs(1)
      val command = args(0)
      if(command=="-encrypt" || command=="-decrypt"){
        checkNumArgs(2); val key = args(1).toArray; val plain = getPlain(2)
        print(new String (encrypt(key,plain)))
      }
      else if(command=="-crib"){
        checkNumArgs(2); val key = args(1).toArray; val plain = getPlain(2)
        print(new String (encrypt(tryCrib(key, plain),plain)))
      }
      else if(command=="-crackKeyLen"){
        checkNumArgs(1); val plain = getPlain(1)
        crackKeyLen(plain)
      }
      else if(command=="-crackKey"){
        checkNumArgs(2); val klen = args(1).toInt; val plain = getPlain(2)
        crackKey(klen, plain)
      }
      else println(errString)
  }
}
