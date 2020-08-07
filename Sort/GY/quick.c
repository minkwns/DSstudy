#include <stdio.h>

void quick_sort(int list[],int left, int right)
{
if(left<right)
{
int q=partition(list, left, right);
quick_sort(list, left, q-1);
quick_sort(list, q+1, right);
}
}
int partition(int list[], int left, int right)
{

int pivot, temp;
int low, high;

low=left+1;
high=right;
pivot=list[left];
do{
while(low<=right && list[low]<pivot) low++;
while(high>=left && list[high]>pivot) high--;
if(low<high) SWAP(list[low],list[high],temp);
}while(low<high);

SWAP(list[left], list[high], temp);
return high;
}
