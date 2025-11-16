#include<stdio.h>
#include<string.h>
#define N 100
void bubbleSort(int [],int);
void printArray(int [],int);
int count;
int main(){
  int n,A[N],i;
  count = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A,n);
  printArray(A,n);
  return 0;
}
void bubbleSort(int A[],int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if( A[j-1] > A[j] ){
	int tmp = A[j-1];
	A[j-1] = A[j];
	A[j] = tmp;
	count++;
      }
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