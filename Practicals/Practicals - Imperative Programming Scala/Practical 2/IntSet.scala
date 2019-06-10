// A class of objects to represent a set

class IntSet{
  // State: S : P(Int) (where "P" represents power set)

  // The following lines just define some aliases, so we can subsequently
  // write "Node" rather than "IntSet.Node".
  private type Node = IntSet.Node
  // Constructor
  private def Node(datum: Int, next: Node) = new IntSet.Node(datum, next)

  // Init: S = {}
  private var theSet : Node = null // or however empty set is represented

  private var siz = 0; // size variable

  /** Convert the set to a string.
    * (The given implementation is not sufficient.) */
  //Complexity: O(size_of_set)
  override def toString : String =
  {

    var s = new String();
    s = s ++ "{"

    var x = theSet;

    while(x!=null && x.next!=null)
    {
        s = s ++ x.datum.toString ++ ", "
        x = x.next
    }
    if(x!=null)
        s = s ++ x.datum.toString

    s = s ++ "}"

    return s
  }

  /** Add element e to the set
    * Post: S = S_0 U {e} */
  //Complexity: Best case O(1), worst case O(size_of_set)
  def add(e: Int) =
  {
      var x = theSet;
      var y = x;
      var ok = 1; //check if the set already has element e
      //y is the previos node, x the current node
      while(x!=null && ok==1)
      {
        y = x;
        if(x.datum==e)
            ok=0;
        x = x.next
      }
      if(ok==1)
      {
        siz += 1
        var q = Node(e,null)
        if(theSet == null)
            theSet = q;
        else
            y.next = q; // add link from last element of list to new node
      }
  }
  /** Length of the list
    * Post: S = S_0 && returns #S */
  // Complexity : O(1)
  def size : Int =
  {
      return siz
  }

  /** Does the set contain e?
    * Post: S = S_0 && returns (e in S) */
  //Complexity: Best case O(1), Worst Case O(size_of_set)
  def contains(e: Int) : Boolean =
  {
    var x = theSet;
    while(x!=null)
    {
        if(x.datum == e)
            return true
        x = x.next
    }
    return false
  }

  /** Return any member of the set.  (This is comparable to the operation
    * "head" on scala.collection.mutable.Set, but we'll use a name that does
    * not suggest a particular order.)
    * Pre: S != {}
    * Post: S = S_0 && returns e s.t. e in S
    * Returns first element in set */
  //Complexity: O(1)
  def any : Int =
  {
      if(theSet==null)
        throw new Exception("Set is empty")
      return theSet.datum
  }

  /** Does this equal that?
    * Post: S = S_0 && returns that.S = S */
    //Complexity: Best case O(1), Worst case: (n log n) where n is the size of the set
  override def equals(that: Any) : Boolean = that match {
    case that: IntSet =>
    {
        if(this.size!=that.size)
            return false
        var a = Array[Int]()
        var b = Array[Int]()
        var x = this.theSet
        // fill a and b with the values from the set
        while(x!=null)
        {
            a = a ++ Array(x.datum)
            x = x.next
        }
        x = that.theSet
        while(x!=null)
        {
            b = b ++ Array(x.datum)
            x = x.next
        }
        a = a.sorted // O(n log n)
        b = b.sorted
        /*for(i<-0 until a.size)
          print(a(i).toString ++ " ")
        println("")
        for(i<-0 until b.size)
          print(b(i).toString ++ " ")
        */
        // sort a and b so we can check if they have the same elements in the best time complexity O(n)
        var ok = true
        for(i <- 0 until a.size)
        {
            if(a(i)!=b(i))
                ok = false
        }
        return ok
    }
    case _ => false
  }

  /** Remove e from the set; result says whether e was in the set initially
    * Post S = S_0 - {e} && returns (e in S_0) */
    // Complexity: Best case O(1), worst case O(size_of_set)
  def remove(e: Int) : Boolean =
  {
    var x = theSet
    var y = x
    if(x == null)
      return false
    if(x.datum == e) // if e is the first element
    {
        theSet = x.next
        siz -= 1
        return true
    }
    x = x.next // keep x as the next element after y
    while(x!=null)
    {
        if(x.datum == e)
        {
            y.next = x.next
            siz -= 1
            return true
        }
        x = x.next
        y = y.next
    }
    return false
  }

  /** Test whether this is a subset of that.
    * Post S = S_0 && returns S subset-of that.S */
  // Complexity : O(n log n)
  def subsetOf(that: IntSet) : Boolean =
  {
    if(this.size>that.size)
        return false // if the supposedly smaller set has more elements
    var a = Array[Int]()
    var b = Array[Int]()
    var x = this.theSet
    // fill a and b with the values from the set
    while(x!=null)
    {
        a = a ++ Array(x.datum)
        x = x.next
    }
    x = that.theSet
    while(x!=null)
    {
        b = b ++ Array(x.datum)
        x = x.next
    }
    a = a.sorted // O(n log n)
    b = b.sorted
    // sort a and b so we can check if they have the same elements in the best time complexity O(n)

    var i = 0
    var j = 0
    while(i<this.size && j<that.size) // use algorithm similar with merging two sorted vectors
                       // invariant : a[0..i) is a subset of b[0..j)
    {
        if(a(i)==b(j))
        {
            i+=1
            j+=1
        }
        else
        if(a(i)<b(j))
            return false
        else
            j+=1
    }
    if(i==this.size)
        return true
    return false
  }

  // ----- optional parts below here -----

  /** return union of this and that.
    * Post: S = S_0 && returns res s.t. res.S = this U that.S */
  def union(that: IntSet) : IntSet = ???

  /** return intersection of this and that.
    * Post: S = S_0 && returns res s.t. res.S = this intersect that.S */
  def intersect(that: IntSet) : IntSet = ???

  /** map
    * Post: S = S_0 && returns res s.t. res.S = {f(x) | x <- S} */
  def map(f: Int => Int) : IntSet = ???

  /** filter
    * Post: S = S_0 && returns res s.t. res.S = {x | x <- S && p(x)} */
  def filter(p : Int => Boolean) : IntSet = ???
}


// The companion object
object IntSet{
  /** The type of nodes defined in the linked list */
  private class Node(var datum: Int, var next: Node)

  /** Factory method for sets.
    * This will allow us to write, for example, IntSet(3,5,1) to
    * create a new set containing 3, 5, 1 -- once we have defined
    * the main constructor and the add operation.
    * post: returns res s.t. res.S = {x1, x2,...,xn}
    *       where xs = [x1, x2,...,xn ] */
  def apply(xs: Int*) : IntSet = {
    val s = new IntSet; for(x <- xs) s.add(x); s
  }
}
