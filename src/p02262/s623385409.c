#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int);
void shellSort(int *, int);

int cnt, m, G[100];

int main(){
  int i, n, *A;

  scanf("%d",&n);

  A = malloc(sizeof(int)*n);

  for(i = 0; i < n; i++) scanf("%d",&A[i]);

  shellSort(A,n);

  printf("%d\n",m);
  for(i = m-1; i >= 0; i--){
    printf("%d",G[i]);
    if(i != 0) printf(" ");
  }
  printf("\n%d\n",cnt);
  for(i = 0; i < n; i++) printf("%d\n",A[i]);

  free(A);

  return 0;
}

void insertionSort(int *A, int n, int g){
  int i, j, v;
  for(i = g; i < n; i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(int *A, int n){
  int i = 0;
 
  cnt = 0;
  G[i] = 1;
  
  while(i < 100){
    if(G[i] > n){
      m = i;
      break;
    }
    if(i < 99){
      G[i+1] = G[i] * 3 + 1;
      i++;
    }
  }
  
  for(i = m-1; i >= 0 ; i--){
    insertionSort(A, n, G[i]);
  }
}
