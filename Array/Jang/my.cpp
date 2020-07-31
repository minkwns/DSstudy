#include <iostream>
#include <stdio.h>

using namespace std;
double get_rate(int* my, int size);
int main(void)
{
   int num;
   cin.tie(0);
   cin.sync_with_stdio(false);
   cin >> num;

   while (num--)
   {
      int num2, num3;
      cin >> num2;
      num3 = num2;
      int* a = new int[num2];
      for (int i = 0; i < num2; i++)
      {
         cin >> a[i];
      }
      double rate=get_rate(a, num2);
      printf("%.3lf%%\n", rate);
   }
}
double get_rate(int* my, int size)
{
   int sum = 0;
   for (int i = 0; i < size; i++)
   {
      sum += my[i];
   }
   double rate = sum / size;
   double good = 0.0;
   for (int i = 0; i < size; i++)
   {
      if (my[i] > rate)
      {
         good++;
      }
   }
   rate = (good / (double)size) * 100;
   return rate;
}
