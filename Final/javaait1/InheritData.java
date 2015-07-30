/*
Inheritance is a mechanism by
which a class gets code and data
(members methods and variables)
from an existing class.

--------------------------
Inheritance of non static data
--------------------------
System implements inheritance
of non static member variables
as object of the sub-class is
created.
Every object of the sub-class
has a nested object of the 
super-class.

The object is a host to the 
non static member variables.
(see the daigram).

-----------------------
Inheritance of static data
-----------------------
A static member variable is
declared only once for a class
and its sub-classes.
If not private, then it is directly
accessible to the entire hierarchy
of classes.

-----------------------
Execution of static blocks
-----------------------
Known that a static block gets
executed on the first use of
the class.
If the first use of a super-class
is due to the first-use of the
sub-class then the static initializer
blocks of super-class and sub-class
both get executed in a sequence
super-class static initializer first
and sub-class static initializer next.


--------------------------
Execution of non-static blocks
--------------------------
1) Known that a non-static block 
gets executed on creation of
object of the class.
2) Also known that every object
of sub-class has a nested object
of the super-class.

Due to 1) and 2) we conclude
that on creation of object of
sub-class the non-static initializer
blocks of super-class and sub-class
both get executed in a sequence
super-class non-static initializer 
first and sub-class non-static 
initializer next.

-----------------------
Execution of constructors
-----------------------
1) Known that a constructor  
gets executed on creation of
object of the class.
2) Also known that every object
of sub-class has a nested object
of the super-class.

Due to 1) and 2) we conclude
that on creation of object of
sub-class the constructors of 
super-class and sub-class both 
get executed in a sequence
super-class constructor first 
and sub-class constructor next.

By default the parameter matching
constructor of the sub-class
and the default constructor of
the super-class, gets executed.

Inorder to execute the parameter
matching constructor of the 
super class, the sub-class constructor
must pass appropriate parameters
to the super-class constructor.

To do so, the sub-class constructor
must use "super(parameters)" 
as its first statement.
*/

class A
{
 int x;//non static member variable
 static int y;//static member variable

 static
 {
  System.out.println("A : static initializer block");
  A.y = 0;// or y = 0;
 }

 {
  System.out.println("A : non-static initializer block");
  x = 0;  
 }

 A()
 {
  System.out.println("A()");
  x=10;
 }

 A(int i)
 {
  System.out.println("A(int)");
  x=i;
 }

}//A

class B extends A
{
 int p;//non static member variable
 static int q; //static member variable

 static
 {
  System.out.println("B : static initializer block");
  A.y++;// or y++;
  B.q= 100; //or q = 100;
 }

 {
  System.out.println("B : non-static initializer block");
  p =1;  
 }

 B()
 {
  System.out.println("B()");
  p=20;
 }

 B(int i, int j)
 {
  super(i);//to invoke A(int)
  System.out.println("B(int,int)");
  p=j;
 }

 void display()
 {
  System.out.println("x : " + x);//super.x
  System.out.println("y : " + y);//A.y
  System.out.println("p : " + p);//this.p
  System.out.println("q : " + q);//B.q

 }
}


class InheritData
{
 public static void main(String args[])
 {
//  System.out.println("=============");
//  A objA = new A();
  System.out.println("=============");
  B objB1 = new B(); 
  objB1.display();
  System.out.println("=============");
  B objB2 = new B(50,60); 
  objB2.display();
  System.out.println("=============");

 }
}