#include<stdio.h>
#include<stdlib.h>
#define N 1000000
int count=0, n, l, A[N], *S;

void insertionSort(int A[], int n, int m){
int i, j, k;
  for(i=m; i<n; i++){
    k = A[i];
    j = i-m;
    while(j >= 0 && A[j] > k){
      A[j+m] = A[j];
      j -= m;
      count++;
    }
    A[j+m] = k;
  }
}

void Sort(int A[],int n){
  int i = 0, s;

S=(int *)malloc(n * sizeof(int));

for(s = 1; ; ){
if(s > n) break;
S[i] = s;
i++;
  s = 3 * s + 1;
}
l = i;
  for(i=l-1; i>=0; i--){
    insertionSort(A,n,S[i]);
  }
}

int main(){
int i;
scanf("%d",&n);
for(i=0; i<n; i++) scanf("%d",&A[i]);
count=0;

Sort(A,n);

printf("%d\n",l);
for(i = l-1; i>=0; i--){
printf("%d", S[i]);
if(i) printf(" ");
}
printf("\n");
printf("%d\n", count);
for(i=0; i<n; i++)   printf("%d\n", A[i]);
 free(S);
  return 0;
}

