#include<stdio.h>
#include<stdlib.h>
int c=0;

int* Bubble(int N, int *A){
  int flag=1, j, num;
  while(flag){
    flag=0;
    for(j=N-1 ; j>0 ; j--){
      if(A[j]<A[j-1]){
        num=A[j];
        A[j]=A[j-1];
        A[j-1]=num;
        flag=1;
        c++;
      }
    }
  }
  return A;
}

int main(void){
  int N,i;
  int *A;
  while(1){
  scanf("%d",&N);
  if(N>=1 && N<=100)break;
}
  A = (int*)malloc(sizeof(int)*N);
  for(i=0 ; i<N ; i++){
    while(1){
    scanf("%d",&A[i]);
    if(0<=A[i] && A[i]<=100)break;
  }
  }
  A=Bubble(N,A);
  printf("%d",A[0]);
  for(i=1 ; i<N ; i++){
    printf(" %d",A[i]);
  }
  printf("\n%d\n",c);
  return 0;
}
