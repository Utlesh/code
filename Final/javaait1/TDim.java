//Two Dimensional Array

class TDim
{
 public static void main(String []args)
 {
  //C : int mat[3][4];
  //Java
  int mat[][] = new int[3][4];

  int i,j;
  
  //set data
  for(i =0; i< mat.length; i++)
  {
   for(j =0; j< mat[i].length; j++)
   {
     mat[i][j] = i+j+100;
   }//for(j...
  }//for(i...

  //display data
  for(i =0; i< mat.length; i++)
  {
   System.out.println();//line change
   for(j =0; j< mat[i].length; j++)
   {
     System.out.print(mat[i][j] + "  ");
   }//for(j...
  }//for(i...
 
  int temp[];//int array reference
  
  //interchanging row 1 and row 2
  temp = mat[1];
  mat[1] = mat[2];
  mat[2] = temp;

  System.out.println();//line change

  //display data
  for(i =0; i< mat.length; i++)
  {
   System.out.println();//line change
   for(j =0; j< mat[i].length; j++)
   {
     System.out.print(mat[i][j] + "  ");
   }//for(j...
  }//for(i...

  
 }//main
}//class

/*
Consider the statement
  int mat[][] = new int[3][4];

int mat[][] : Declares a reference to an array of int array references
new int[3][4] : Declares a two dimensional int array of 3 rows with 4 cols each
= : Assigns the address of two dimensional array to the reference

*/