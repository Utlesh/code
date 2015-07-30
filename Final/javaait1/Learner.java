import prglang.*;

class Learner
{
 public static void main(String args[])
 {
  C objC = new C(); 
  Cpp objCpp = new Cpp();
  Java objJava = new Java();
  Html objHtml = new Html();

  objC.aboutC();
  objCpp.aboutCpp();
  objJava.aboutJava();
  objHtml.aboutHtml();
 }//main

}//Learner