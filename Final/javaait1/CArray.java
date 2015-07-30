/*
Arrays of a Class
(Object Arrays)

As we define array of some
primary datatype similarly we
can define array of a class.

Syntax:
 datatype arr[] = new datatype[SIZE];

Example
 int arr[] = new int[3];
 Student arr[] = new Student[3];

When an array some primitive
type is defined, then the array
elements are "variables" of that
primitive type.

But for an array of class type
the array elements are "references"
(not objects) of the class type.

The class array elements (that 
are references of the the class)
are "null" by default.

Hence the array is not usable
by default.

Inorder to use the array
1) Objects of the class must be
created explicitly
2) The object references must
be given to the array elements.


*/

class CArray
{
 int x, y;

 CArray()
 {
  System.out.println("CArray()");
  x = 10;
  y = 20;
 }

 CArray(int q, int w)
 {
  System.out.println("CArray(int,int)");
  x = q;
  y = w;
 }

 void display()
 {
  System.out.println(x + " " + y);
 }

 public static void main(String args[])
 {
  System.out.println("---About to create array----");
  CArray arr[] = new CArray[3];  
  System.out.println("---About to create objects----");
  arr[0] = new CArray();
  arr[1] = new CArray(1,2);
  arr[2] = new CArray(5,50);
  System.out.println("---Array Usage----");

  int i;
  for(i =0; i< arr.length; i++)
    arr[i].display();  
 }
}
