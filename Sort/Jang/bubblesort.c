#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void bubble(int*, int);

int main(void)
{
    int* a;
    int num;
    int i;
    printf("input length of arrary : ");
    scanf("%d", &num);
    a = (int*)malloc(sizeof(int) * num);
    for (i = 0; i < num; i++)
    {
        printf("input %dst num : ", i + 1);
        scanf("%d", &a[i]);
    }
    bubble(a, num);
    printf("result : ");
    for (i = 0; i < num; i++)
    {
        printf(" %d ", a[i]);
    }
    return 0;
}

void bubble(int* my, int num)
{
    int i, j;
    int temp;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num - (i + 1); j++)
        {
            if (my[j] > my[j + 1])
            {
                temp = my[j + 1];
                my[j + 1] = my[j];
                my[j] = temp;
            }
        }
    }
}