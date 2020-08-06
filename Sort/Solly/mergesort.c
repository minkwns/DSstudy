#include <stdio.h>

#define MAX 30

typedef int Data;

int size;
Data sort[MAX];

void merge(Data a[], int m, int middle, int n) {
    int i, j, k, t;
    i = m;   // 첫번째 부분집합의 시작 위치 설정
    j = middle + 1;   // 두번째 부분집합의 시작 위치 설정
    k = m;   // 배열 sort에 정렬된 data를 저장할 위치 설정

    while(i <= middle && j <= n) {
        if(a[i] <= a[j]) {
            sort[k] = a[i];
            i++;
        }
        else {
            sort[k] = a[j];
            j++;
        }
        k++;
    }

    // 두번째 부분집합의 원소들만 남은 경우
    if(i > middle) {
        for(t = j; t <= n; t++, k++)
            sort[k] = a[t];
    }
    // 첫번째 부분집합의 원소들만 남은 경우
    else {
        for(t = i; t <= middle; t++, k++)
            sort[k] = a[t];
    }

    for(t = m; t <= n; t++)
        a[t] = sort[t];

    printf("\n병합정렬 : ");
    for(t = 0; t < size; t++)
        printf("%d ", a[t]);
}

void mergesort(Data a[], int m, int n) {
    int middle;

    if(m < n) {
        middle = (m + n) / 2;
        mergesort(a, m, middle);
        mergesort(a, middle + 1, n);
        merge(a, m, middle, n);
    }   
}

void main()
{
    int t;

    Data list[8] = {69, 10, 30, 2, 16, 8, 31, 22};
    size = 8;

    printf("정렬 전 원소 : ");
    for(t = 0; t < size; t++) 
        printf("%d ", list[t]);

    mergesort(list, 0, size - 1);
}