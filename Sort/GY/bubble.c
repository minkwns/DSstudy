#include <stdio.h>

int main(void)
{
int i,j;
int N;
int arr[100];
int temp;

scanf("%d", &N);

for(i=0; i<N; i++){
scanf("%d", &arr[i]);
}

for(i=0; i<N ; i++){
for(j=0; i<N-i-1; j++){
if(arr[j] > arr[j+1]) {
temp =arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}

for(i=0; i<N; i++) {
printf("%d", arr[i]);
}

puts("");

return 0;


}
