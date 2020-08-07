#define _CRT_SECURE_NO_WRNINGS
#include "stdio.h"
#include "stdlib.h"
#define MAX_ELEMENT 100
// ������ ���� 1���� �迭�� ���� ������ ������ ����ü�� ��� ����
typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
} heapType;
// ���� ������ �����ϴ� ����
heapType* createHeap()
{
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}
// ������ item�� �����ϴ� ����
void insertHeapmax(heapType* h, int item)
{
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;
	while ((i != 1) && (item > h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
void insertHeapmin(heapType* h, int item)
{
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;
	while ((i != 1) && (item < h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
int deleteHeap(heapType* h)
{
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1])
			child++;
		if (temp >= h->heap[child])
			break;
		else
		{
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}
void printHeap(heapType* h)
{
	int i;
	printf("Heap : ");
	for (i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
}
void main()
{
	int i, n, item;
	int size, value;
	heapType* heap = createHeap();
	heapType* heap1 = createHeap();
	printf("input size of heap : ");
	scanf_s("%d", &size);
	
	for (i = 0; i < size; i++)
	{
		printf("input %dst value : ", i + 1);
		scanf_s("%d", &value);
		insertHeapmax(heap, value);
		insertHeapmin(heap1, value);
	}

	printf("Max heap's values are ");
	n = heap->heap_size;
	for (i = 0; i < n; i++)
	{
		printf(" %d ", deleteHeap(heap));
	}
	puts("");
	printf("Min heap's values are ");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", deleteHeap(heap1));
	}
	return 0;
}
