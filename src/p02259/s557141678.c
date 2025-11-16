#include <stdio.h>

#define N_MAX 100

int bubbleSort(int A[], int N) {
  int cnt = 0, i, j, flag;

  flag = 1;
  i = 0;
  while (flag) {
    flag = 0;
    for (j = N - 1; j >= i + 1; j--) {
      if (A[j] < A[j - 1]) {
        int tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        cnt++;
        flag = 1;
      }
    }
    i++;
  }

  return cnt;
}

int main(void) {
  int N, i, cnt;
  int A[N_MAX];

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  cnt = bubbleSort(A, N);

  printf("%d", A[0]);
  for (i = 1; i < N; i++) {
    printf(" %d", A[i]);
  }
  printf("\n%d\n", cnt);

  return 0;
}