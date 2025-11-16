#include <stdio.h>
#include <stdlib.h>

void display(int *A, int n, int m, int *G, int cnt) {
	int i;
	printf("%d\n", m);
	for (i = 0; i < m - 1; i++) {
		printf("%d ", G[i]);
	}
	printf("%d\n", G[m - 1]);
	printf("%d\n", cnt);
	for (i = 0; i < n; i++) {
		printf("%d\n", A[i]);
	}
}

int insertionSort(int *A, int n, int g) {
	int i, j, v;
	int cnt = 0;
	for (i = g; i < n; i++) {
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
	return cnt;
}

void shellSort(int *A, int n) {
	int cnt, m, i;
	int *G;

	cnt = 0;
	m = n / 2;
	if (m < 1) m = 1;
	if (m > 100) m = 100;
	G = (int *)malloc(sizeof(int)*m);
	G[0] = n - 1;
	for (i = 1; i < m - 1; i++) {
		G[i] = G[i - 1] / 2;
	}
	G[m - 1] = 1;

	for (i = 0; i < m; i++) {
		cnt += insertionSort(A, n, G[i]);
	}

	display(A, n, m, G, cnt);
}

int main() {
	int n;
	int *A;
	int i;

	scanf("%d", &n);
	A = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	shellSort(A, n);

	return 0;
}
