class AboutObjects
{
 int x, y; //member variables


//a non static initializer block
 {
   System.out.println("in non static initializer block1");
   x = 10;
   y = 20;
   
 }

//a non static initializer block
 {
   System.out.println("in non static initializer block2");
   x++;
   y++;
 }

 //constructors
 AboutObjects()//default constructor
 {
  System.out.println("AboutObjects()");
  x = 1; 
  y = 2;
 }

 AboutObjects(int q, int w)//parameterized constructor
 {
  System.out.println("AboutObjects(int,int)");
  x = q;
  y = w;
 }

 //member methods

 void AboutObjects()
 {
  System.out.println("Java allows member methods to have same name as of the class");
 }

 void display()
 {
  System.out.println(x + "  " + y);

 }

 public static void main(String args[])
 {
  System.out.println("===============");
  //AboutObjects ao = new AboutObjects();
  AboutObjects ao = new AboutObjects(51,52);
  System.out.println("===============");
  ao.display();  
  ao.AboutObjects();//compiler will bind this call with a method that has same name as of the class.
 }
}//AboutObjects

/*
To use a class, it must be instantiated,
i.e. its objects must be created.

Object creation is a 3 step process in Java
1) Memory Allocation.
2) Execution of non static initialzer blocks.
3) Execution of constructor.

-------------------------------------------
Non-static Initializer Block

A non static initiailizer is a
block of code that belongs to
the class.

It has no signature.

It is automatically invoked as
object of the class is created.

It cannot be explicitly called.

If a class has multiple non static
initializer blocks then all get
executed on object creation.

They execute in a sequence same
as the order of their definition
from top to bottom.

It is used to assign some initial
value to the instance variables.


-------------------------------------------
Constructor
A constructor is a special member method.
* It has the same name as of the class
* It has no return type specification.
* It is automatically invoked as object of the class is created.
* It cannot be explicitly called.
* It is used to assign some initial
  value to the instance variables.
* If a class has multiple constructors
  still only one will get executed on 
  object creation.
  The one for which the actual and 
  formal parameters match.

Constructors of a class may be
classified as 
1) Default Constructor
2) Parameterized Constructor.

Default Constructor
Is a constructor of the class
that doesnt accept any formal
parameters (user input).
It uses preset data (default
values) to initialize the member
variables of the object. 

Parameterized Constructor
Is a constructor of the class
that accepts formal parameters
(user input).
It applies the same to the 
member variables of the object. 


Constructor Overloading
----------------------
Is defining multiple constructors
for a class with different set
of formal parameters.

It allows object intialization
in multiple ways.
Hence it is implementation of
OOP concept "Polymorphism".

Polymorphism allows a class
to implement a task in multiple
ways.
*/