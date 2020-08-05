#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct {
    int heap[MAX_ELEMENT];
    int heap_size;
} heaptype;

heaptype *createheap() {
    heaptype* h = (heaptype *)malloc(sizeof(heaptype));
    h->heap_size = 0;
    return h;
}

void insertheap(heaptype *h, int d) {
    int i;

    h->heap_size++;   // 노드 확장
    i = h->heap_size;   // 확장한 노드가 임시 삽입 위치가 된다

    while((i != 1) && (d > h->heap[i/2])) {   // 삽일할 원소 d가 부모 노드보다 크면
        h->heap[i] = h->heap[i/2];   // 자리를 바꿔줌
        i /= 2;   // 계속해서 부모 노드와 비교
    }
    h->heap[i] = d;
}

int deleteheap(heaptype *h) {
    int parent, child;
    int data, temp;

    data = h->heap[1];   // 삭제할 노드
    temp = h->heap[h->heap_size];   // 마지막 원소를 임시 변수에 저장
    
    h->heap_size--;

    parent = 1;
    child = 2;

    // heap의 재구성 작업
    while(child <= h->heap_size) {
        // 왼쪽 자식 노드와 오른쪽 자식 노드 중 크기가 큰 자식 노드 찾기
        if((child < h->heap_size) && ((h->heap[child]) < h->heap[child+1]))
            child++;

        // 자식 노드와 temp의 크기를 비교하여 더 큰 것을 찾고,
        if(temp >= h->heap[child])  break; 
        else {
            h->heap[parent] = h->heap[child];
            parent = child;
            child *= 2;
        }
    }

    h->heap[parent] = temp;   // 삭제한 노드에 삽입

    return data;
}

void printheap(heaptype *h) {
    int i;

    printf("Heap : ");

    for(i = 1; i <= h->heap_size; i++) 
        printf("%d ", h->heap[i]);
    
    putchar('\n');
}

void main() {
    int data[8] = {69, 10, 30, 2, 16, 8, 31, 22};

    int i, sortdata[8];

    heaptype* heap = createheap();

    for (i = 0; i < 8; i++)
        insertheap(heap, data[i]);

    printf("Heap Sort : ");

    for (i = 0; i < 8; i++) {
        sortdata[i] = deleteheap(heap);
        printf("%d ", sortdata[i]);
    }

    putchar('\n');
}