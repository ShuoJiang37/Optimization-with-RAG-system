#include <stdio.h>

void quicksort(int *A, int len) {
  if (len < 2) return;

  int pivot = A[len / 2];

  int i, j;
  for (i = 0, j = len - 1; ; i++, j--) {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;

    if (i >= j) break;

    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }

  quicksort(A, i);
  quicksort(A + i, len - i);
}

int main(void) {
    int A[1000000];
    int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++ ){
		scanf("%d", &A[i]);
	}
    for (int i = 0; i < n; i++) {
        printf("%d%s", A[i], i == n - 1 ? "\n" : " ");
    }
    quicksort(A, n);
    for (int i = 0; i < n; i++) {
        printf("%d%s", A[i], i == n - 1 ? "\n" : " ");
    }
    return 0;
}
