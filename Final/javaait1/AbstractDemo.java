/*
Certain applications require
creation of a family of classes.
Example:
--------
Vehicle
 Car
 Bike
 Train

Animal
 Snake
 Fish
 Sparrow

Shape
 Rectangle
 Square
 Circle

In such cases the role of the
super class is
1) To host common code and data
2) To act as a generic reference for the sub classes
3) To enforce some method definitions on the sub classes
 
There may be case that super 
class predicts the need of an
operation but is able to define it.
Further seeking the same to be
defined by the sub classes.

Example
--------
start(), generatePower(), accelerate() ,... for a Vehicle
eat(), move(), ... for class Animal
area(), circumf(), ... for class Shape

Java supports implementation of
such cases through abstract methods 
and abstract classes.

abstract methods
----------------
An abstract method 
* is a method with declaration only and no definition.
* is a method that makes the class an abstract class.
* is a non static method that must be compulsorily overridden by the sub class.

 
abstract class
-------------
An abstract class is a class that 
* contains zero to many abstract methods.
* cannot be instantiated.

Known that a class is used through its objects.
And an abstract class cannot be instantiated.
So what it its use?

An abstract class can be inherited and used.

Inheritance of abstract classes
------------------------------
Known that inheritance allows a sub-class
to get code and data from the super-class.

When a class inherits an abstract class
then along with code and data, the sub
class also gets the abstract methods from 
the super class.

Now the sub-class has some abstract
methods due to inheritance.
Hence the sub-class also becomes an
abstract class.

If the sub-class "overrides" the inherited
abstract methods then it can become
a normal class again.

*/


abstract class A
{
 void f1()
 {
  System.out.println("Some common code for all the sub classes");
 }   

 abstract void f2();

}

class B extends A
{
 void f2()//override
 {
  System.out.println("This is how B implements f2()");
 }
}

class C extends A
{
 void f2()//override
 {
  System.out.println("This is how C implements f2()");
 }
}

class AbstractDemo
{
 public static void main(String args[])
 {
   A arr[] = new A[2];
   arr[0] = new B();
   arr[1] = new C();   

   int i;
   for(i =0; i< arr.length; i++)
   {
     arr[i].f1();
     arr[i].f2();
   }
 }
}