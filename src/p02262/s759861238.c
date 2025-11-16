#include <stdio.h>

#define ASIZE 1048576
#define GSIZE 524288

int m, cnt = 0;
int insertionSort(int *A, int n, int g){
  int i, j, v;
  for (i = g; i < n; i++) {
    v = A[i];
    j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }
    A[j + g] = v;
  }
  return cnt;
}

int shellSort(int *A, int n){
  int i, j, g, tmp;
  int G[GSIZE] = {0};
  for (m = 0, g = 1; g <= n; m++, g = g * 3 + 1)
    G[m] = g;
  
  // descending sort
  for (i = 0, j = m - 1; i < j; i++, j--) {
    tmp = G[i];
    G[i] = G[j];
    G[j] = tmp;
  }

  printf("%d\n", m);
  for (i = 0; i < m; i++) {
    if (i)
      printf(" ");
    printf("%d", G[i]);
  }
  puts("");

  for (i = 0; i < m; i++)
    insertionSort(A, n, G[i]);
  return cnt;
}

int main(void){
  int i, n, A[ASIZE] = {0};
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &A[i]);
  shellSort(A, n);

  printf("%d\n", cnt);
  for (i = 0; i < n; i++)
    printf("%d\n", A[i]);

  return 0;
}