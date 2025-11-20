#include <stdio.h>

void insertionsort(int A[], int N);

int main(void){
  int i,N;
  int A[100];
  
  scanf("%d",&N);
  
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
    printf("%d",A[i]);
    if(i != N-1)printf(" ");
  }
  /*  for(i = 0;i < N; i++){
    printf("%d",A[i]);
    if(i =! N-1) printf(" ");
    }*/
  printf("\n");


  insertionsort(A,N);
  
  return 0;
}

void insertionsort(int A[], int N){
  int i ,a, j,v;
  
  for(i = 1; i < N; i++){
    
    v = A[i];
    j = i -1;
    while((j >= 0) && A[j]> v){
      A[j + 1] = A[j];
      j--;
      A[j + 1] = v;
    }
    for(a = 0; a < N;a++){
      printf("%d",A[a]);
      if(a != N-1) printf(" ");
    }
    printf("\n");
  }
}