// 일차원 배열의 동등함을 검사하여 결과를 알아보는 프로그램 
//배열 a와 b1,b2,b3를 각각 검사하기 
#include <stdio.h>

int main()
{
   int a[5] = { 4,7,9,3,6 };
   int b1[5] = { 4,7,9,3,6 };
   int b2[5] = { 10,20,30,40,50 };
   int b3[5] = { 4,7,9,3,7 };
   int i;

   printf("배열 a의 원소는 다음과 같다.\n");
   for (i = 0; i < 5; i++)
   {
      printf("%d ", a[i]);
   }
   printf("\n");
   printf("배열 b1의 원소는 다음과 같다.\n");
   for (i = 0; i < 5; i++)
   {
      printf("%d ", b1[i]);
   }
   printf("\n");
   printf("배열 b2의 원소는 다음과 같다.\n");
   for (i = 0; i < 5; i++)
   {
      printf("%d ", b2[i]);
   }
   printf("\n");
   printf("배열 b3의 원소는 다음과 같다.\n");
   for (i = 0; i < 5; i++)
   {
      printf("%d ", b3[i]);
   }
   printf("\n");

   if (sizeof(a) / sizeof(a[0]) != sizeof(b1) / sizeof(b1[0])) {
      printf("배열 a와 배열 b1은 다른 배열이다. \n");
   }
   else {
      for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
         if (a[i] != b1[i]) {
            printf("배열 a와 배열 b1은 다른 배열이다.\n"); break;
         }
         else {
            i++; if (i == sizeof(a) / sizeof(a[0])) printf("배열 a와 배열 b1은 같은 배열이다.\n");
            continue;
         }
      }
   }
   if (sizeof(a) / sizeof(a[0]) != sizeof(b2) / sizeof(b2[0])) {
      printf("배열 a와 배열 b2은 다른 배열이다. \n");
   }
   else {
      for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
         if (a[i] != b2[i]) {
            printf("배열 a와 배열 b2은 다른 배열이다.\n"); break;
         }
         else {
            i++; if (i == sizeof(a) / sizeof(a[0])) printf("배열 a와 배열 b2은 같은 배열이다.\n");
            continue;
         }
      }
   }
   if (sizeof(a) / sizeof(a[0]) != sizeof(b3) / sizeof(b3[0])) {
      printf("배열 a와 배열 b3은 다른 배열이다. \n");
   }
   else {
      for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
         if (a[i] != b3[i]) {
            printf("배열 a와 배열 b3은 다른 배열이다.\n"); break;
         }
         else {
            i++; if (i == sizeof(a) / sizeof(a[0])) printf("배열 a와 배열 b3은 같은 배열이다.\n");
            continue;
         }
      }
   }

}
