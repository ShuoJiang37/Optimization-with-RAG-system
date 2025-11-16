#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int m, cnt, G[MAX];

void insertionSort(int *A, int n, int g){
  int i, j, v;
  
  for(i = g; i < n; i++){
    v = A[i];
    j = i - g;
    while((j >= 0) && (A[j] > v)){
      A[j + g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void shellSort(int *A, int n){
  int i;
  G[0] = 1;

  //        3    9     27     81
  // G = {1   4    13     40}     x121
  i = 0;
  while((++i) <= MAX){
    if(G[i - 1] > n){
      m = i - 1;
      break;
    }
    else{
      G[i] = G[i - 1] * 3 + 1;
    }
  }

  // 40 13 4 1 (reverse)
  for(i = m - 1; i >= 0; i--){
    insertionSort(A, n, G[i]);
  }
}


int main(){
  int i,n,*A;

  scanf("%d",&n);
  A = malloc(sizeof(int) *n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  shellSort(A, n);
  
  printf("%d\n",m);
  for(i = m - 1; i > 0; i--)
    printf("%d ",G[i]);
  printf("%d\n%d\n",G[i],cnt);
  for(i = 0; i < n; i++)
    printf("%d\n",A[i]);
  
  free(A);
  
  return 0;
}


