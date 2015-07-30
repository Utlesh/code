/*
It is possible to pass parameters
from DOS/LINUX shell to the
main method of a java application.
Such parameters are called as
command line arguments.

System gathers the command line
arguments and forms a string array
of the same.

On java application startup, the
reference to the command line
argument String array, is passed
as a parameter to the main method.

The java application may utilize
or process the command line
arguments.
*/
class CmdLine
{
 public static void main(String args[])
 {
  System.out.println("Number of command line arguements : "+ args.length);

  int i;
  for(i =0; i< args.length; i++)
  {
   System.out.println("args[" + i  + "]  : " + args[i]); 
  }

 }//main
}//CmdLine