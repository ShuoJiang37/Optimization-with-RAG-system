#include <stdio.h>

int main()
{
  int n, i, j, k;
  int *A;
  int cnt, m, G[12], v;
  
  scanf("%d", &n);
  
  A = (int *)malloc(sizeof(int) * n);
  
  for (i = 0; i < n; i++) scanf("%d", &A[i]);
  
  cnt = 0;
  m = 1;
  G[0] = 1;
  while (3 * G[m-1] + 1 < n) {
    G[m] = 3 * G[m-1] + 1;
    m++;
  }
  
  for (i = 0; i < m / 2; i++) {
    v = G[i];
    G[i] = G[m-1-i];
    G[m-1-i] = v;
  }
  
  printf("%d\n", m);
  for (i = 0; i < m; i++) {
    if (i != m - 1) printf("%d ", G[i]);
    else printf("%d\n", G[i]);
  }
  
  for (i = 0; i < m; i++) {
    for (j = G[i]; j < n; j++) {
      v = A[j];
      k = j - G[i];
      while (k >= 0 && A[k] > v) {
    A[k+G[i]] = A[k];
    k -= G[i];
    cnt++;
      }
      A[k+G[i]] = v;
    }
  }
  
  printf("%d\n", cnt);
  for (i = 0; i < n; i++) printf("%d\n", A[i]);
  
  return 0;
}