class General
{
 public static void main(String args[]) //prg starts here
 {
  int i;//local variable
  i = 0;
  while(i < 11)
  {
   if(i %2 == 0)
   {
    //printf("Hello Java\n");
    System.out.println("Hello Java");
   }
   else
   {    
    System.err.println("Hello Student");
   }
   i++;
  }//while
 }//main
}

/*
To compile a java prg:
 c:\>javac Program.java

Compilation generates bytecode
file that has name same as the
name of the class and extension 
".class".

Every class of the java program
will have a corresponding bytecode
file.

To execute a java program
c:\>java ByteCodeFileNameWithoutExtension

If the class is a public class
then it must be saved in a file
that has same name as of the
class.
-----------------------------
In Java, do variables contian garbage?
In Java, variables may be
1) member variables
2) local variables

Member variables are auto initialized
by the system hence are garbage free.
It is a rule to intialize the local variable
first and to use it later.

Conclusion garbage data is never
encountered.

*/