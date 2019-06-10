/**  With Scala 2.12 on Lab machines:

 * In normal circumstances the CLASSPATH is already set for you:

fsc TestTest.scala
scala org.scalatest.run TestTest

 * If you use jar files in your own space:

fsc -cp ./scalatest_2.12-3.0.5.jar:./scalactic_2.12-3.0.5.jar TestTest.scala
scala -cp ./scalatest_2.12-3.0.5.jar:./scalactic_2.12-3.0.5.jar org.scalatest.run TestTest

 * (Once this is working you can set your CLASSPATH in .bashrc)
*/
import org.scalatest.FunSuite

class TestTest extends FunSuite
{
    test("Addition to set and check contains")
    {
        var v = IntSet()
        v.add(2)
        v.add(3)
        assert(v.contains(2)==true)
        assert(v.contains(3)==true)
        v.add(2)
        assert(v.contains(2)==true)
        assert(v.contains(4)==false)
        assert(v.contains(123)==false)
    }
    test("Add x more times, remove once, check")
    {
        var v = IntSet()
        v.add(2)
        v.add(2)
        v.add(2)
        assert(v.contains(2)==true)
        v.remove(2)
        assert(v.contains(2)==false)
        v.add(3)
        assert(v.contains(2)==false && v.contains(3)==true && v.contains(123)==false)
    }
    test("Size")
    {
        var v = IntSet()
        assert(v.size==0)
        v.add(2)
        v.add(2)
        v.add(123)
        v.add(2)
        v.add(3)
        v.add(2)
        assert(v.size==3)
        v.remove(2)
        assert(v.size==2)
        v.remove(3)
        v.remove(123)
        assert(v.size==0) //check when set is empty
    }
    test("Remove -> true or false")
    {
        var v = IntSet()
        v.add(2)
        assert(v.remove(2)==true)
        assert(v.remove(2)==false)
        v.add(3)
        assert(v.contains(2)==false && v.remove(2)==false && v.remove(3)==true)
        assert(v.contains(2)==false && v.contains(3)==false && v.remove(3)==false) //try to remove elements from empty set
    }
    test("Init")
    {
        var v = IntSet(1,2,3)
        v.add(2)
        assert(v.contains(2)==true && v.contains(3)==true && v.contains(1)==true && v.contains(0)==false && v.contains(4)==false)
        v = IntSet(3,4,5)
        assert(v.contains(3)==true && v.contains(4)==true && v.contains(5)==true && v.contains(1)==false && v.contains(2)==false)
    }
    test("Any")
    {
        var v = IntSet(1,2,3,4)
        assert(v.contains(v.any)==true)
        for(i<-1 to 100)
        {
            v.add(i)
        }
        while(v.size>0)
        {
          assert(v.remove(v.any)==true)
        }
        assert(v.size==0 && v.contains(1)==false && v.contains(100)==false)
    }
    test("Equals")
    {
        var a = IntSet(1,2,3)
        var b = IntSet(2,3,4)
        assert(a.equals(b) == false && b.equals(a)==false)
        a.add(1)
        a.add(2)
        assert(a.equals(b) == false && b.equals(a)==false)
        assert(a.equals(a) == true && b.equals(b)==true)
        a.add(4)
        b.add(4)
        b.add(1)
        assert(a.equals(b)==true && b.equals(a)==true)
        a.remove(2)
        b.remove(2)
        a.add(12)
        b.add(12)
        a.remove(3)
        b.remove(3)
        assert(a.equals(b)==true && b.equals(a)==true)
    }
    test("Equals + Diverse")
    {
        var a = IntSet(1,2,3)
        var b = IntSet(1,2,4)
        assert(a.equals(b)==false && b.equals(a)==false)
        a.add(2)
        a.add(3)
        a.add(4)
        a.add(5)
        a.add(5)
        a.add(6)
        a.remove(5)
        a.remove(6)
        assert(a.equals(b)==false && b.equals(a)==false)
        b.remove(4)
        a.remove(4)
        assert(a.equals(b)==false && b.equals(a)==false)
        assert(a.remove(3)==true && b.remove(3)==false)
        assert(a.equals(b)==true && b.equals(a)==true)
        a.remove(1)
        b.remove(1)
        a.remove(2)
        b.remove(2)
        assert(a.equals(b)==true && b.equals(a)==true)
        assert(a.equals(a)==true && b.equals(b)==true)  // a = b = {}
        assert(a.size==0 && b.size==0 && a.remove(1)==false && b.remove(2)==false)
    }
    test("SubsetOf")
    {
      var a = IntSet(1,2,3)
      var b = IntSet(1,2,4)
      assert(a.subsetOf(b)==false && b.subsetOf(a)==false)
      b.add(15)
      b.remove(15)
      b.add(3)
      b.remove(2)
      assert(a.subsetOf(b)==false && b.subsetOf(a)==false)
      b.add(2)
      b.add(12)
      assert(a.subsetOf(b)==true && b.subsetOf(a)==false)
      a.remove(1)
      b.remove(1)
      assert(a.subsetOf(b)==true && b.subsetOf(a)==false)
      assert(a.subsetOf(a)==true && b.subsetOf(b)==true)
      assert(a.remove(2)==true && a.remove(3)==true && a.size==0 && a.subsetOf(a)==true && a.subsetOf(b)==true) // check a={} is subset of b
    }
    test("ToString")
    {
        var a = IntSet(1,2,3)
        assert(a.toString == "{1, 2, 3}")
        a.add(4)
        a.add(2)
        a.add(2)
        assert(a.toString == "{1, 2, 3, 4}")
        a.remove(3)
        assert(a.toString == "{1, 2, 4}")
        a.remove(2)
        a.remove(4)
        assert(a.toString == "{1}")
        a.remove(1)
        assert(a.toString == "{}")
    }
}

/*
dinu@dinu-G751JM:~/Desktop/Practicals/Practicals - IP/Practical 2$ scalatest_cp IntSet.scala TestTest.scala
dinu@dinu-G751JM:~/Desktop/Practicals/Practicals - IP/Practical 2$ scalatest_run TestTest
Run starting. Expected test count is: 9
TestTest:
- Addition to set and check contains
- Add x more times, remove once, check
- Size
- Remove -> true or false
- Init
- Any
- Equals
- Equals + Diverse
- SubsetOf
Run completed in 246 milliseconds.
Total number of tests run: 9
Suites: completed 1, aborted 0
Tests: succeeded 9, failed 0, canceled 0, ignored 0, pending 0
All tests passed.
*/
