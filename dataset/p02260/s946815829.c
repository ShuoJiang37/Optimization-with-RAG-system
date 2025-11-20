#include <stdio.h>
int main(void){

  int i,j,n = 0,count;
  int A[100];

  scanf("%d",&n);

  for(i = 0; i < n;i++){
    scanf("%d",&A[i]);
  }

  count = selectionSort(A,n);

  for(j = 0; j< n;j++){
    printf("%d",A[j]);
    if(j != n-1) printf(" ");

  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

int selectionSort(int A[],int N){
  int i,j,minj= 0,temp = 0,count=0;
  for(i =0; i < N;i++){
    minj = i;
    for(j =i;j < N; j++){
      if(A[j] < A[minj]) minj=j;
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    if(A[i]!=A[minj]){
      count++;
    }
  }
  return count;
}