#include <stdio.h>

typedef int Data;

int size;
int i = 0;

int partition(Data a[], int begin, int end) {
    int pivot, L, R, t;

    Data temp;

    L = begin;   // 시작index
    R = end;   // 끝index

    pivot = begin;   // 첫째 원소를 pivot 원소로 선택

    printf("\n%d단계 : pivot = %d\n", ++i, a[pivot]);

    while(L < R) {
        while((a[L] < a[pivot]) && (L < R)) L++;   // pivot보다 크거나 같은 원소 찾기
        while((a[R] >= a[pivot]) && (L < R)) R--;   // pivot보다 작은 원소 찾기

        // L, R change
        if(L < R) {   
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;

            if(L == pivot)   // L이 pivot인 경우
                pivot = R;   // 변경된 pivot위치 저장
        }
    }

    // L >= R 된 경우
    // 더 이상 진행할 수 없으므로 R원소와 pivot원소의 자리 change
    temp = a[pivot];
    a[pivot] = a[R];
    a[R] = temp;

    for(t = 0; t < size; t++)
        printf("%d ", a[t]);
    putchar('\n');

    return R;   // pivot위치 반환
}

void quicksort(Data a[], int begin, int end) {
    int p;

    if(begin < end) {
        p = partition(a, begin, end);
        quicksort(a, begin, p-1);
        quicksort(a, p+1, end);
    }
}

void main()
{
    Data list[8] = {69, 10, 30, 2, 16, 8, 31,22};

    size = 8;

    printf("\n초기상태\n");
    for(int i = 0; i < size; i++) 
        printf("%d ", list[i]);
    putchar('\n');

    quicksort(list, 0, size-1);
}