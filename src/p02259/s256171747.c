#include <stdio.h>

#define MAX_N 100

int bubbleSort(int*,int);
void print(int*,int,int);

int main(){
  int N,A[MAX_N],i,cnt;
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }
  cnt = bubbleSort(A,N);
  print(A,N,cnt);
  return 0;
}

int bubbleSort(int *A,int N){
  int i,j,temp,res = 0;
  for(i = 0 ; i < N ; i++){
    for(j = N-1 ; j > i ; j--){
      if(A[j-1] > A[j]){
        ++res;
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
      }
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