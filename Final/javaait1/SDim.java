//Single Dimensional Arrays

class SDim
{
 public static void main(String args[])
 {
   //C : int arr[4];  
   //Java
   int arr[] = new int[4];

//observe that the array is
//used through its reference

   int i;
   //set data
   for(i =0 ;i< arr.length; i++)
     arr[i] = i+10;

   int []q;//another int array reference
   q = arr;//gets the address of the same array   

   //display data
   for(i =0 ;i< q.length; i++)
     System.out.print(q[i] + "  ");
   
 }//main
}//SDim

/*
Consider the statement
   int arr[] = new int[4];

int arr[] : declares int array reference
new int[4] : declares an int array of size 4
= : assigns the initial address of the array to the reference
----------------------------
Java supports array reference
declaration in 2 ways
1) postfix usage of [] : int arr[]
2) prefix usage of [] : int []arr

The difference between the two is
as follows:

int arr[], x, y;
declares arr as int array reference, and x,y as int variables

int []arr, x, y;
declares arr,x and y as int array references

----------------------------
Reference is an entity that can
store address and is dereferencable.
*/