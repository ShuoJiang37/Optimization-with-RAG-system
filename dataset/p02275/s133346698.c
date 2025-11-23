#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 20000001
#define VMAX 10000

void CountingSoat(int *, int *, int, int);

int *A, *B;

int main(){
  int i, j, max=0;
  
  int n;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  for(i=0; i<n; i++){
    scanf("%hd", &A[i+1]);
    if(A[i+1] > max) max = A[i+1];
  }
  
  CountingSoat(A, B, max, n);
  for(i=1; i<n; i++){
    printf("%d ", B[i]);
  } printf("%d\n", B[i]);

  free(A);
  free(B);
  return 0;
}

void CountingSoat(int *A,int *B, int max, int n){
  int i, j;
  int *C;

  C = malloc(sizeof(int)*max+1);
  for(i=0; i<=max; i++){
    C[i] = 0;
  }

  for(j=0; j<n; j++){
    C[A[j+1]]++;
  }
  
  for(i=1; i<=max; i++){
    C[i] = C[i] + C[i-1];
  }

  for(j=1; j<=n; j++){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  free(C);
}

