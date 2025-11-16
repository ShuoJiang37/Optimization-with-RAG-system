#include <stdio.h>

void insertionSort(int*, int, int);
void shellSort(int*, int);
void print(int, int*, int*, int);

int cnt;

int main(void){
  int n, i;
  int A[1000000];
  scanf("%d", &n);
  for(i = 0; i < n; i ++){
    scanf("%d", &A[i]);
  }
  shellSort(A, n);
  return 0;
}

void insertionSort(int *A, int n, int g){
  int i, j, v;
  for(i = g; i < n; i++){
    v = A[i];
    j = i - g;
    while((j >= 0)&&(A[j] > v)){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
  return;
}

void shellSort(int *A, int n){
  int m, i, j, G[100];
  cnt = 0;
  for(i = 0; i < n; i++){
    G[i] = n/2;
    for(j = 0; j < i; j++){
      G[i] /= 2;
    }
    m++;
    if(G[i] == 0) G[i] = 1;
    if(G[i] == 1) break;
  }
  for(i = 0; i < m; i++){
    insertionSort(A, n, G[i]);
  }
  print(m, G, A, n);
  return;
}

void print(int m, int *G, int *A, int n){
  int i;
  printf("%d\n", m);
  for(i = 0; i < m; i++){
    printf("%d", G[i]);
    if(i+1 != m) printf(" ");
  }
  printf("\n%d\n", cnt);
  for(i = 0; i < n; i++){
    printf("%d\n", A[i]);
  }
  return;
}