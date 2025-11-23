#include <stdio.h>

int main(void) {
  int count = 0,pool,n,A[100];

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  int flag = 1;
  while (flag) {
    flag = 0;
    for (int j = n-1; j > 0; j--) {
      if (A[j] < A[j-1]) {
        pool = A[j];
        A[j] = A[j-1];
        A[j-1] = pool;
        count++;
        flag = 1;
      }
    }
  }

  for (int i = 0; i < n - 1; i++) {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[n-1]);
  printf("%d\n", count);
  return 0;
}

