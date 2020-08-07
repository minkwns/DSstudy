#include <stdio.h>
#define MAX_SIZE 8

void merse_sort(int list[], int left, int right)
{
    int middle;
    if(left<right)
    {
        middle = (left+right) /2;
        merge_sort(list, left, middle);
        merge_sort(list, middle+1, right);
        merge(list, left, middle, right);
    }
}

int sorted[MAX_SIZE];
void Merge(int list[], int left,int middle, int right){
int i,j,k,l;
i=left;
j=middle+1;
k=left;

while(i<=middle && j<=right){
 if(list[i]<=list[j]) sorted[k++]=list[i++];
 else sorted[k++]=list[j++];

 }
  if(i>middle)
  for(l=j; l<=right; l++)
  sorted[k++]=list[l];
  else
  {
      for(l=i;l<=middle;l++)
    sorted[k++]=list[l];
    for(l=left; l<=right; l++)
    list[l]=sorted[l];
  }
    
}

