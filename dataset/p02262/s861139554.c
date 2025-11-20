#include <stdio.h>
#include <stdbool.h>

int A[1000010], G[100], cnt = 0;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(int *A, int n) {
	for (int i = 0; i < n/2; ++i) swap(&A[i], &A[n - 1 - i]);
}

void insertionSort(int *A, int n, int g) {
	for (int i = g; i < n; ++i) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j+g] = A[j];
			j -= g;
			cnt++;
		}
		A[j+g] = v;
	}
}

void shellSort(int *A, int n) {
	int m = 0;
	G[m] = 1;
	while (true) {
		m++;
		G[m] = 3*G[m - 1] + 1;
		if (G[m] > n) break;
	}
	reverse(G, m);
	printf("%d\n", m);
	for (int i = 0; i < m; ++i) {
		if (i != m-1) printf("%d ", G[i]);
		else printf("%d\n", G[i]);
	}
	for (int i = 0; i < m; ++i) {
		insertionSort(A, n, G[i]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	shellSort(A, n);

	printf("%d\n", cnt);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", A[i]);
	}
}

