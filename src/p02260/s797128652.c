#include <stdio.h>

#define MAX_N 100

int selectionSort(int*,int);
void print(int*,int,int);

int main(){
  int N,A[MAX_N],i,cnt;
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }
  cnt = selectionSort(A,N);
  print(A,N,cnt);
  return 0;
}

int selectionSort(int *A,int N){
  int i,j,temp,res = 0,min,idx;
  for(i = 0 ; i < N ; i++){
    min = A[i]; idx = i;
    for(j = i+1 ; j < N ; j++){
      if(A[j] < min){
        min = A[j];
        idx = j;
      }
    }
    if(A[idx] < A[i]){
      temp = A[i];
      A[i] = A[idx];
      A[idx] = temp;
      ++res;
    }
  }
  return res;
}

void print(int *A,int N,int cnt){
  int i;
  for(i = 0 ; i < N ; i++){
    printf("%d%c",A[i],(i < N-1 ? ' ' : '\n'));
  }
  printf("%d\n",cnt);
}