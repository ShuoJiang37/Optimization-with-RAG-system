#include<stdio.h>

#define MAX 100

int main(){
  int i,j,minj,count,n,A[MAX+1];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  count = 0;

  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(A[j] < A[minj])minj = j;
    }
    A[n] = A[i];
    A[i] = A[minj];
    A[minj] = A[n];
    if(i != minj)count++;
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}