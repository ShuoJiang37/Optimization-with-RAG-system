#include <stdio.h>

#define N_MAX 100

void trace(int A[], int N) {
  int i;
  printf("%d", A[0]);
  for (i = 1; i < N; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");

}

void InsertionSort(int A[], int N) {
  int i, j, v;

  for(i = 1; i < N; i++) {
    v = A[i];
    j = i - 1;
    while(j >= 0 && v < A[j]) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;

    trace(A, N);
  }
}


int main(void) {
  int N, i;
  int A[N_MAX];

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  trace(A, N);
  InsertionSort(A, N);

  return 0;
}