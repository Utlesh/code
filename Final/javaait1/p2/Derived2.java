package p2;

import p1.Base;
public class Derived2 extends Base
{
 //attempt to access members of the
 //super class of different package

 public Derived2()
 {
  System.out.println("p2 Derived2 Derived2()");
  //i++;
  //j++;
  k++;
  l++;
 }
 
 public void display() //override
 {
  System.out.println("p2 Derived2 display()");
  System.out.println("i : not accessible");
  System.out.println("j : not accessible");
  System.out.println("k : "+ k);
  System.out.println("l : "+ l);
  System.out.println("=============");
  super.display(); 

 }
}//Derived