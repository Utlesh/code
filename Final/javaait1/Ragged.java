/*
Ragged Array
A ragged array is a two dimensional
array with different number of cols
for its rows.

To define a ragged array
1) Define a two dimensional array
with value of last dimension "unset". 
2) Explicitly define n single dimensional
arrays of different sizes.
3) Connect each array with row element
of the two dimensional array.
*/
class Ragged
{
 public static void main(String []args)
 {
  //Java
  int ragged[][] = new int[3][];
  ragged[0] = new int[3];
  ragged[1] = new int[4];
  ragged[2] = new int[2];

  int i,j;
  
  //set data
  for(i =0; i< ragged.length; i++)
  {
   for(j =0; j< ragged[i].length; j++)
   {
     ragged[i][j] = i+j+100;
   }//for(j...
  }//for(i...

  //display data
  for(i =0; i< ragged.length; i++)
  {
   System.out.println();//line change
   for(j =0; j< ragged[i].length; j++)
   {
     System.out.print(ragged[i][j] + "  ");
   }//for(j...
  }//for(i...
 
  int temp[];//int array reference
  
  //interchanging row 1 and row 2
  temp = ragged[1];
  ragged[1] = ragged[2];
  ragged[2] = temp;

  System.out.println();//line change

  //display data
  for(i =0; i< ragged.length; i++)
  {
   System.out.println();//line change
   for(j =0; j< ragged[i].length; j++)
   {
     System.out.print(ragged[i][j] + "  ");
   }//for(j...
  }//for(i...
   
 }//main
}//class

/*

*/