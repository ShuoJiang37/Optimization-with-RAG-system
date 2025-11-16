#include <stdio.h>
#include <math.h>
#define MAX 1000000

int cnt = 0, G[20], m;

void insertionSort(int A[],int n,int g) {
  int v, j;
  for (int i = g; i < n; i++) {
    v = A[i];
    j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(int A[], int n) {
  int n2 = n;
  m = floor(log2(n));
  if (m == 0) m = 1;
  for (int i = 0; i < m; i++) {
    if (m == 1) {G[0] = 1; break;}
    n2 /= 2;
    G[i] = n2;
  }
  for (int i = 0; i < m; i++) {
    insertionSort(A, n, G[i]);
  }
}

int main(void) {
  int n, A[MAX];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  shellSort(A, n);

  printf("%d\n", m);
  for (int i = 0; i < m; i++) {
    if (i) {
      printf(" %d", G[i]);
    } else {
      printf("%d", G[i]);
    }
  }
  printf("\n");
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++) {
    printf("%d\n", A[i]);
  }

  return 0;
}
