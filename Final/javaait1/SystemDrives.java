import java.io.*;

class SystemDrives
{
 public static void main(String args[])
 {
  File allDrives[];
  allDrives = File.listRoots(); //fetchs system root drives information

  int i;
  for(i =0; i< allDrives.length; i++)
  {
   System.out.println(allDrives[i].getAbsolutePath());
  }
 }//main
}