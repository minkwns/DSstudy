#include <stdio.h>
#include <stdlib.h>

void heap(int* arr, int n);
void swap(int* arr, int x, int y);

int main()
{
    int* arr = (int*)malloc(sizeof(int)*100);
    if (arr == NULL)
        return 1;

    // 배열 갯수 입력
    int n;
    scanf("%d", &n);

    if (n < 1 || n > 100)
        return 1;

    // 배열값 입력
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // 힙정렬 수행
    heap(arr, n);

    // 결과 출력
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}


void heap(int* arr, int n)
{
    int count = n;

    /* 최초 (max)힙트리 생성 */
    int p, c;	// parent Node, Child Node
    for (int i = 1; i < count; i++) {
        c = i;
        while (c > 0) {
            p = (c - 1) / 2;
            if (arr[p] < arr[c]) {
                swap(arr, p, c);
                c = p;
            }
            else break;
        }
    }

    /* 힙정렬 수행 */
    while(count > 1) {

        p = 0;
        // 자식 노드 있는 곳까지만 보면 됨
        while (p <= (count/2) - 1){
            // 첫번 째 자식 노드
            c = p * 2 + 1;
            // 자식 노드 중 큰 노드 선택
            if (c + 1 < count && arr[c] < arr[c + 1])
                c++;
            // 부모 노드가 자식 노드보다 작으면 교체
            if (arr[p] < arr[c]) {
                swap(arr, p, c);
                p = c;
            }
            else break;
        }
        // 마지막과 교체 후 사이즈 줄여줌
        swap(arr, 0, count - 1);
        count--;
    }
}

/* Swap */
void swap(int* arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

