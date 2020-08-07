#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int key;
} element;
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType *create() //생성 함수 
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType*h) //초기화 함수 
{
    h->heap_size =0; 
    //현재 요소의 개수가  heap_size인 힙 h에 item을 삽입한다
}
//삽입 함수 
void insert_max_heap(HeapType*h, element item)
{
    int i;
    i = ++(h->heap_size);
//트리를 거슬러 올라가며 부모 노드와 비교
while ((i !=1 )&& (item.key > h->heap[i /2].key)){
    h->heap[i]=h->heap[i/2];
    i /=2;
}
h->heap[i]=item; //새로운 노드 삽입 
}
//삭제 함수 
element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent =1;
    child=2;
    while (child <= h->heap_size) {
        //현재 노드의 자식노드 중 더 작은 자식노드를 가짐 
        if((child<h->heap_size)&&
        (h->heap[child].key)<h->heap[child+1].key)
        child++;
        if(temp.key >= h->heap[child].key) break;
        //한 단계 아래로 이동 
        h->heap[parent]=h->heap[child];
        parent =child;
        child*=2;
    }
    h->heap[parent] = h->heap[child];
    return item;
}
    void heap_sort(element a[],int n)
    {
        int i;
        HeapType* h;

        h=create();
        init(h);
        for(i=0; i<n; i++){
            insert_max_heap(h,a[i]);
        }
        for (i=(n-1); i>=0; i--) {
            a[i] =delete_max_heap(h);
        }
        free(h);
    } 

