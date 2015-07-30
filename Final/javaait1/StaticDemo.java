/*
Java allows declaration of
* member variables
* member methods
* initializer blocks
* nested classes
as "static".
-----------------------
Member Variables

A member variable is a variable
that belongs to the class.
It may be
* non static (default)
* static

non static member variables
------------------------
* Member variables of a class
are by default non static.
* Being non static the member 
variable gets declared as a 
member inside every object of 
the class.
* Non static member variables
get declared as object of the
class is created. Their life
is equal to the life of the object.
* It is accessible through
object only.
* It is initialized using
 a) non static intializer block
 b) constructor.


static member variables
---------------------
* Member variables of a class
can be declared as "static".
* Being  static the member 
variable gets declared (in the
data seg.) only once for the 
class. It is not a member inside
the objects of the class.
* static member variables
get declared as class gets
initialized. 
Their life is equal to the 
life of the class.
* It is accessible through
object or through the class.
* It is initialized using
the static intializer block

static initializer block
---------------------

* It is used to initialize the
static member variables of 
the class.

* It gets auto invoked as class
gets initialized.
If there are multiple static
initializer blocks then all get
executed on class initialization
in sequence same as their order
of definition from top to bottom.

* It cannot be explicitly called.

-----------------------------
Member Methods
Member methods are methods
that belong to a class.
In Java, member methods may be
* non static (default)
* static

non static methods
----------------- 
* Methods of a class are by default
non static methods.
* Being non static, they require
a caller object for invokation.
* They have direct access to all
non static and static members of
the class.


static methods
--------------
* Methods of a class may be 
declared as "static".

* Being static, they can be
invoked without any caller object.

* They have direct access to all
static members of the class.
They cannot directly access the
non static members of the class
because non static members require
a caller object for accessiblity.

*/

class Another
{
 static
 {
  System.out.println("in static initializer block of Another"); 
 }

 Another()
 {
  System.out.println("Another()"); 
  
 }
}//Another

class StaticDemo
{
 int x; // a non static member variable
 static int y;// a static member variable

 StaticDemo()
 {
  System.out.println("StaticDemo()");
  x = 0;
 }

 static
 {
  System.out.println("In static block1 of class StaticDemo");
  y = 100;
 }

 void display()
 {
   System.out.println(x + " " + y);
 }

 static void increment(StaticDemo ref)
 {
  ref.x++;
  y++;
 }
 
 public static void main(String args[])
 {
  System.out.println("in main " + StaticDemo.y);
  StaticDemo o1 = new StaticDemo();
  StaticDemo o2 = new StaticDemo();
 
  o1.display();
  o2.display();

  increment(o1);//accessible without any object
  
  o1.display();
  o2.display();


/*
  System.out.println("===============");
  Another o1 = new Another();
  System.out.println("===============");
  Another o2 = new Another();
  System.out.println("===============");
*/
 }//main

 static
 {
  System.out.println("In static block2 of class StaticDemo");
  y++;
 }

}//StaticDemo


/*
why is main() static in Java?

* In Java, main is a member method.
* In Java, applications execution
begins with main.
* For system to invoke main :
main must be public : for global accessibility.
main must be static : for accessibility without any object.


*/