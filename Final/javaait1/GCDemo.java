/*
Java supports 
* Creation of objects/arrays
  using the operator "new".
* Use the objects/arrays through
  some reference.
* Ignore object/array destruction
  (deallocation).

An object/array becomes eligible
for destruction (deallocation)
when all of its references get
dropped.

References to an object/array
usually get dropped due to
* Life of local reference gets over, due to completion of method in which local reference was declared.
* Reference is explicitly assigned a null value.

JVM owns a high priority thread
called as "finalizer".
It periodically or on demand
scans the heap segment for
unreferenced objects/arrays.
Next the same will be deallocated
by the finalizer.
This process is called as
"Garbage Collection".

In Java,the Object class is the
default super class for all the
classes.
The Object class defines a
"finalize()" method.
The same is inherited by all
the sub classes.

For an unreferenced object that 
is eligible for deallocation
the "finalizer" thread first 
invokes the "finalize()" and 
then clears the object from 
heap.

The sub classes may override
the finalize() to get their
specific code executed on
object deallocation.

*/

class SomeClass
{
  String name;
  int arr[];

  SomeClass(String n , int s)
  {
   name = n;
   arr = new int[s];
  }

  void display()
  {
   System.out.println("name : " + name);
   System.out.println("array is of size : " + arr.length);
  }

  protected void finalize() //override
  {
   System.out.println("In finalize for : " + name);
   System.out.println("Method executed by : " + Thread.currentThread());
   System.out.println("Please clear this object and its array of size : " + arr.length);
  }
}//SomeClass

class GCDemo
{
 public static void main(String args[])
 {
  SomeClass o1 = new SomeClass("A", 1000); 
  SomeClass o2 = new SomeClass("B", 10000);
  SomeClass o3 = new SomeClass("C", 100000);
  //SomeClass ref = o1;
 
  System.out.println("------------");
  o1.display();
  o2.display();
  o3.display();
  System.out.println("------------");
  //drop the references
  o1 = null;
  o2 = null;
  o3 = null;
  //force garbage collection
  System.gc();
 
  //delay of 5 seconds
  try
  {
    Thread.sleep(5 * 1000);
  }
  catch(InterruptedException ex)
  {} 
       
  System.out.println("end of main");
 }//main
}