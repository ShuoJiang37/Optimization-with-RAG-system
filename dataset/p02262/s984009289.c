#include<stdio.h>
#include<stdlib.h>
 
int insertionSort(int *A, int n, int g) {
  int i, j, v;
  int cnt = 0;
 
  for(i = g; i < n; i++) {
    v = A[i];
    j = i-g;
    while(j >=0 && A[j] > v) {
      A[j+g] = A[j];
      j = j-g;
      cnt++;
    }
    A[j+g] = v;
  }
  return cnt;
}
 
int shellSort(int *A, int n, int m, int *G) {
  int i;
  int cnt = 0;
 
  for(i = 0; i < m; i++) {
    cnt += insertionSort(A, n, G[i]);
  }
  return cnt;
}
 
int main() {
  int n, m, i;
  int cnt = 0;
  int *A;
  int G[100], *H;
 
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
 
  H = malloc(m*sizeof(int));
  for(i = m; i >= 0; i--) {
    H[m-i] = G[i-1];
  }
 
  cnt = shellSort(A, n, m, H);
 
  printf("%d\n", m);
  for(i = 0; i < m; i++) {
    printf("%d", H[i]);
    if(i != m-1) {
      printf(" ");
    }
  }
  printf("\n");
 
  printf("%d\n", cnt);
 
  for(i = 0; i < n; i++) {
    printf("%d\n", A[i]);
  }
 
  return 0;
}