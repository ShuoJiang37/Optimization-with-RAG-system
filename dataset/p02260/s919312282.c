#include<stdio.h>
#define N 100
void selectionSort(int [],int);
void printArray(int [],int);
int count;
int main(){
  int i,n,A[N];
  count = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,n);
  printArray(A,n);
  return 0;
}
void selectionSort(int A[],int n){
  int i,j,tmp,key;
  for(i=0;i<n-1;i++){
    key = i;
    for(j=i+1;j<n;j++){
      if( A[j] < A[key] ){
	key = j;
      }
    }
    tmp = A[key];
    A[key] = A[i];
    A[i] = tmp;
    if( key != i ) {
      count++;
    }
  }
  return ;
}
void printArray(int A[],int n){
  int i;
  for(i=0;i<n;i++){
    if( i!=0 ){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
} 