#include<stdio.h>
#define MAX 100


void trace(int A[],int n){
  int i;

  for(i=0;i<n;i++){
    if(i>=1)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

void ins(int A[],int n){
  int i,j;
  int v;

  for(i=1;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;

    trace(A,n);
  }
}

int main(){
  int A[MAX];
  int i,j;
  int n;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  trace(A,n);
  ins(A,n);

  return 0;
}

