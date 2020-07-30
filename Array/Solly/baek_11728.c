#include <stdio.h>

int n, m;   // 배열a, b의 크기
    
long int a[1000000];
long int b[1000000];

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);

    // 배열a, b의 원소를 입력받음
    for(i = 0; i < n; i++) 
        scanf("%ld", &a[i]);

    for(i = 0; i < m; i++) 
        scanf("%ld", &b[i]);

    int a_ind = 0;
    int b_ind = 0;

    while(1) {
        if(a_ind == n || b_ind == m)    break;

        if(a[a_ind] == b[b_ind]) {
            printf("%ld %ld ", a[a_ind], b[b_ind]);
            a_ind++;
            b_ind++;
        }
        else if(a[a_ind] > b[b_ind]) {
            printf("%ld ", b[b_ind]);
            b_ind++;
        }
        else {
            printf("%ld ", a[a_ind]);
            a_ind++;
        }
    }

    int temp = 0;   // 오름차순 정렬을 위한 임시 변수

    if(a_ind != n) {
        for(i = a_ind; i < n; i++) {
            for(j = a_ind; j < (n-1); j++) {
                if(a[j] > a[j+1]) {
                    // 위치 변경
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
            printf("%ld ", a[i]);
        }
    }

    if(b_ind != m) {
        for(i = b_ind; i < m; i++) {
            for(j = b_ind; j < (m-1); j++) {
                if(b[j] > b[j+1]) {
                    // 위치 변경
                    temp = b[j];
                    b[j] = b[j+1];
                    b[j+1] = temp;
                }
            }
            printf("%ld ", b[i]);
        }
    }

    printf("\n");
}