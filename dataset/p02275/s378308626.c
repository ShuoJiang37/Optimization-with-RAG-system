#include <stdio.h>
#include <stdlib.h>
int A[2000000],k,*B,C[10000],n;
void CountingSort(int [],int *,int);
int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(k<=A[i])k=A[i];
  }
  B=malloc(sizeof(int)*n+1);

  CountingSort(A,B,k);


  for(i=1;i<=n;i++){
    if(i==n) printf("%d\n",B[i]);
    else  printf("%d ",B[i]);
  }


  return 0;
}

void CountingSort(int A[],int *B,int k){
  int i,j;
  for(i=0;i<=k;i++){
    C[i]=0;
  }

  for(j=0;j<n;j++){
    C[A[j]]++;
  }


  for(i=0;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }

  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}