#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof(int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? A[i++]
             : i == m      ? A[j++]
             : A[j] < A[i] ? A[j++]
             :               A[i++];
    }
    for (i = 0; i < n; i++) {
        A[i] = x[i];
    }
    free(x);
}

void mergesort(int *A, int n) {
    if (n < 2) return;
    int m = n / 2;
    mergesort(A, m);
    mergesort(A + m, n - m);
    merge(A, n, m);
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
    mergesort(A, n);
    for (int i = 0; i < n; i++) {
        printf("%d%s", A[i], i == n - 1 ? "\n" : " ");
    }
    return 0;
}
