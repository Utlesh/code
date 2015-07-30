#include<iostream>
using namespace std;
#include<limits.h>
#define num 4

struct node{
 int element;
 int i;
 int j;
};

void swap(node *root1,node *root2)
{
 node root3 = *root1;
 *root1 = *root2;
 *root2 = root3; 
}

void minHeapify(int i,node root[],int k)
{
 int l = 2*i + 1;
 int r = 2*i + 2;
 int smallest = i;
 if(l<k && root[i].element>root[l].element)
  smallest = l;
 if(r<k && root[smallest].element>root[r].element)
  smallest = r;
 
 if(smallest!=i)
  {
   swap(&root[i],&root[smallest]);
   minHeapify(smallest,root,k);
  }
}

void sortUtil(node root[],int k)
{
 int mid = (k-1)/2;
 while(mid>=0)
  {
  minHeapify(mid,root,k);
  --mid;
  }
}

 
int *sortArray(int arr[][num],int k)
{
 
 struct node *root = new node[k];
 for(int i=0;i<k;++i)
  {
   root[i].element = arr[i][0];
   root[i].i = i;
   root[i].j = 1; 
  }

 sortUtil(root,k);
 int *output = new int[num*k];
 for(int i=0;i<num*k;++i)
  {
    node temp = root[0];
    output[i] = temp.element;
    cout<<output[i]<<" ";
    if(temp.j<num)
     {
      temp.element = arr[temp.i][temp.j];
      temp.j = temp.j + 1 ; 
     }
     else
      temp.element = INT_MAX;

     root[0] = temp;
     minHeapify(0,root,k);
  }
  cout<<"\n";
 return output;
}

int main()
{
 int arr[][num] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
 
 int *output = sortArray(arr,3);
 for(int i=0;i<num*3;++i)
  cout<<output[i]<<" ";
  cout<<"\n";
 return 0;
}
