#include <stdio.h>

int cnt = 0;

void insertionSort(int A[], int n, int g) {
  int i, j, v;

  for(i = g;i < n;i++) {
    v = A[i];
    j = i - g;

    while(j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }

    A[j + g] = v;
  }
}

void shellSort(int A[], int n) {
  int i, j, G[n], H[n];
  G[0] = 1;

  for(i = 1;G[i - 1] * 3 + 1 < n / 2;i++)
    G[i] = G[i - 1] * 3 + 1;

  for(j = 0;j < i;j++)
    H[j] = G[i - j - 1];

  for(j = 0;j < i;j++) {
    insertionSort(A, n, H[j]);
  }

  printf("%d\n", i);
  for(j = 0;j < i - 1;j++)
    printf("%d ", H[j]);
  printf("%d\n", H[j]);
  printf("%d\n", cnt);
  for(j = 0;j < n;j++)
    printf("%d\n", A[j]);
}

int main() {
  int n, i, A[1000000];

  scanf("%d", &n);
  for(i = 0;i < n;i++)
    scanf("%d", &A[i]);

  shellSort(A, n);
}

