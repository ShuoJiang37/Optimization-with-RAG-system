#include<stdio.h>

#define MAX 100

void print(int A[],int);

int main(){
  int i,j,n,key,A[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  print(A,n);

  for(i=1;i<n;i++){
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
    print(A,n);
  }
  return 0;
}

void print(int A[],int n){
  int i;

  for(i=0;i<n;i++){
    if(i < n - 1)printf("%d ",A[i]);
    else printf("%d\n",A[i]);
  }
}