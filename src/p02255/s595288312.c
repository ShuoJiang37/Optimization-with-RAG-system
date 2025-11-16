#include<stdlib.h>
#include<stdio.h>
#include<string.h>



void print_A(int *A,int n){
  int i; 
  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
}


int main(){
  int n,i,j,key;
  int *A;
  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  for(i=0;i<n;i++){
    key=A[i];
    j=i-1;
    while(key <A[j] && j>=0){
      A[j+1]=A[j];
      j+=-1;
    }
    A[j+1]=key;
    print_A(A,n);
  }
  return 0;
}