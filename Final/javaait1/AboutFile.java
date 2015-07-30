/*
Operations on File and Directory Metadata.
--------------------------------------
For operations on file and directory
metadata, java provides the File class.
Learn by example.

*/
import java.io.*;
import java.util.Date;

class AboutFile
{
 static char getChar() throws IOException
 {
  System.in.skip(System.in.available());
  return (char) System.in.read();
 }

 static void showContent(File f)
 {
  String arr[] = f.list(); //fetch names of all files and directories inside f
  int i;
  
  for(i =0; i< arr.length; i++)
  {
   System.out.println(arr[i]);
  } 
 
  System.out.println("Total : " + arr.length);
 }

 static void showDetails(File f)
 {
  System.out.println("Absolute Path : " + f.getAbsolutePath());
  System.out.println("Size in bytes : " + f.length());
  System.out.println("Is Readable : " + f.canRead());
  System.out.println("Is Writable : " + f.canWrite());
  System.out.println("Is Executable : " + f.canExecute());
  System.out.println("Is Hidden : " + f.isHidden());

  //f.lastModified() returns milliseconds between 1/1/1970 00:00 and file's last modification time
  
  Date d=  new Date(f.lastModified());  
  System.out.println("last modified : " + d);

  //f.delete();//deletes a file or an empty directory
  //f.renameTo(f1); //where f1 is a File object holding new name
}

 public static void main(String args[])
 {
  try
  {
    File f = new File(args[0]);

    if(f.exists())//To check whether a file/directory exists or not
    {
     System.out.println(args[0] + " exists");   
     if(f.isDirectory()) // check whether it is a directory or not
     {
      System.out.println(args[0] + " is a directory");
      showContent(f);
     } 
     else if(f.isFile()) // check whether it is a file or not
     {
      System.out.println(args[0] + " is a file");
      showDetails(f);
     }
     else
     {
      System.out.println(args[0] + " is neither a file not a directory");
     }

    }
   else
   {
     System.out.println(args[0] + " does not exist");
     System.out.println("Do you want to create it (y/n) ? ");
     char ch;
     ch = getChar();
     if(ch == 'y' || ch == 'Y')
     {
       System.out.println("F : create as a file ");
       System.out.println("D : create as a directory ");
       System.out.println("enter choice ");
       ch = getChar();

       switch(ch)
       {
         case 'f':
         case 'F':
           f.createNewFile(); //creates a new empty file
           break;
         case 'd':
         case 'D':
           f.mkdirs();//creates a hierarchy of directories
           break;
         default:
           System.out.println("Illegal Choice ");
           break;
       }//switch
     }
   }//else
  }//try
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java AboutFile <file/dir name>");
  }
  catch(IOException ex)
  {
   System.out.println("Err : " + ex);
  }
 }//main
}//AboutFile