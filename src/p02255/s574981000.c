#include <stdio.h>

int main(void) {
  int A[100], n, j, key;

  scanf("%d\n", &n);

  for ( int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  for ( int k = 0; k < n; k++) {
      if (k != n-1) {
        printf("%d ", A[k]);
      } else {
        printf("%d\n", A[k]);
      }
    }

  for ( int i = 1; i < n; i++) {
    key = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    for ( int k = 0; k < n; k++) {
      if (k != n-1) {
        printf("%d ", A[k]);
      } else {
        printf("%d\n", A[k]);
      }
    }
  }

  return 0;
}

