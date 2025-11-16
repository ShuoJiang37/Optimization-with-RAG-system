#include <stdio.h>
void printArray(int *A, int n){
  int i;
  for(i=0; i<n; ++i){
	printf("%d", A[i]);
	if(i!=n-1)
	  printf(" ");
  }
  printf("\n");
}
void insertionSort(int *A, int N){
  int i, j;
  int tmp;
  for(i=1; i<N; ++i){
	tmp=A[i];
	j=i-1;
	while((j>=0)&&(A[j]>tmp)){
	  A[j+1]=A[j];
	  --j;
	}
	A[j+1]=tmp;
	printArray(A, N);
  }
}
int main(){
  int length;
  int A[105];
  int i;
  scanf("%d", &length);
  for(i=0; i<length; ++i){
	scanf("%d", &A[i]);
  }
  printArray(A, length);
  insertionSort(A, length); 
  
}

