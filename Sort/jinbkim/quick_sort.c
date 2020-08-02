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

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		median_pivot(int *arr, int left, int right)
{
	int	ex[] = {left, (left + right) / 2, right};

	if (arr[ex[1]] < arr[ex[0]])
		ft_swap(&ex[0], &ex[1]);
	if (arr[ex[2] < arr[ex[1]]])
		ft_swap(&ex[1], &ex[2]);
	if (arr[ex[1]] < arr[ex[0]])
		ft_swap(&ex[0], &ex[1]);
	return (ex[1]);
}

int		partition(int *arr, int left, int right)
{
	int pivot_i;
	int	pivot;
	int low;
	int high;
	
	pivot_i = median_pivot(arr, left, right);
	pivot = arr[pivot_i];
	low = left + 1;
	high = right;

	ft_swap(&arr[pivot_i], &arr[left]);
	while (low <= high)
	{
		while (low <= high && arr[low] <= pivot)
			low++;
		while (low <= high && pivot <= arr[high])
			high--;
		if (low <= high)
			ft_swap(&arr[low], &arr[high]);
	}
	ft_swap(&arr[left], &arr[high]);
	return (high);
}

void	quick_sort(int *arr, int left, int right)
{
	int pivot;

	if (left <= right)
	{
		pivot = partition(arr, left, right);
		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot + 1, right);
	}

}



int		main(void)
{
	int arr[] = {6, 3, 1, 7, 4, 2, 5};
	// int arr[] = {3, 3, 3, 3};

	show_arr(arr, sizeof(arr) / sizeof(int));
	quick_sort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	show_arr(arr, sizeof(arr) / sizeof(int));
}