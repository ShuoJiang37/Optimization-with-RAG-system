#include<stdio.h>
#include<stdlib.h>
#define N 2000002

int A[2000002],B[2000002];
int C[10001];
int n;

int main(){

  int i,j;

  scanf("%d",&n);
  /*
  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  */
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=10000;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=10000;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
  if(i!=n)
    printf(" ");
    }
  printf("\n");
  return 0;
}