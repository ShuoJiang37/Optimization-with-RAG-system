#include<stdio.h>
#include<stdlib.h>
  
int insertionSort(int *A, int n, int g) {
  int i, j, k;
  int count = 0;
  
  for(i = g; i < n; i++) {
    k = A[i];
    j = i-g;
    while(j >= 0 && A[j] > k) {
      A[j+g] = A[j];
      j = j-g;
      count++;
    }
    A[j+g] = k;
  }
  return count;
}
  
int shellSort(int *A, int n, int m, int *G) {
  int i;
  int count = 0;
  
  for(i = 0; i < m; i++) {
    count += insertionSort(A, n, G[i]);
  }
  return count;
}
  
int main() {
  int n, m, i;
  int count = 0;
  int *A;
  int G[100], *L;
  
  scanf("%d", &n);
  A = malloc(n*sizeof(int));
  for(i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  
  G[0] = 1;
  for(i = 1; i < 100; i++) {
    G[i] = 3*G[i-1]+1;
  }
  
  m = 1;
  while(G[m] < n && m < 100) {
    m++;
  }
  
  L = malloc(m*sizeof(int));
  for(i = m; i >= 0; i--) {
    L[m-i] = G[i-1];
  }
  
  count = shellSort(A, n, m, L);
  
  printf("%d\n", m);
  for(i = 0; i < m; i++) {
    printf("%d", L[i]);
    if(i != m-1) {
      printf(" ");
    }
  }
  printf("\n");
  
  printf("%d\n", count);
  
  for(i = 0; i < n; i++) {
    printf("%d\n", A[i]);
  }
  
  return 0;
}