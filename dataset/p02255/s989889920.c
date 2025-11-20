
#include<stdio.h>

void clear(int *A, int N) {
	int i;
	for (i = 0; i < N - 1; i++)
		printf("%d ", A[i]);
	printf("%d", A[N - 1]);
	printf("\n");
}

void insertionSort(int *A, int N) {
	int i, v, j;
	for (i = 1; i < N; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		clear(A, N);
	}
}

int main() {
	int N = 0;
	int A[1024];
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	clear(A, N);
	insertionSort(A, N);
	return 0;
}