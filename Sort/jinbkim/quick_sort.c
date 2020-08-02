#include <stdio.h>
#include <stdlib.h>



void	show_arr(int *arr, int size)
{
	int i ;
	
	i = -1;
	while(++i < size)
		printf("%d ", arr[i]);
	printf("\n");
}

int		partition(int *arr, int left, int right)
{
	
}

void	quick_sort(int *arr, int left, int right)
{
	int pivot;

	if (left <= right)
	{
		pivot = partition(arr, left, right);

	}

}


int		main(void)
{
	int arr[] = {6, 3, 1, 7, 4, 2, 5};

	show_arr(arr, sizeof(arr) / sizeof(int));
	quick_sort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	show_arr(arr, sizeof(arr) / sizeof(int));
}