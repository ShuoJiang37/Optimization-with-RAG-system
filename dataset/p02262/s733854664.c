#include <stdio.h>
#include <stdio.h>

void insertionSort(int *A, int n, int g);
void shellSort(int *A, int n);

unsigned long long cnt = 0ULL;

int main(void) {
	
	int n;
	int *A;
	int i;
	
	scanf("%d", &n);
	
	A = (int*)malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++) {
		scanf("%d", A + i);
	}
	
	shellSort(A, n);
	
	for (i = 0; i < n; i++) {
		printf("%d\n", A[i]);
	}
	
	free(A);
	
	return 0;
}

void insertionSort(int *A, int n, int g) {
	int i, j, v;
	for (i = g; i < n; i++) {
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(int *A, int n) {
	int m = 1, g;
	int i;
	int *G = (int*)malloc(101 * sizeof(int));
	G[0] = 1;
	for (i = 0; i < 100 && G[i] < n; i++) {
		G[i + 1] = 3 * G[i] + 1;
	}
	if (i > 0) {
		m = i;
	}
	cnt = 0ULL;
	printf("%d\n", m);
	for (i = 0; i < m; i++) {
		g = G[(m - 1) - i];
		if (i > 0) {
			putchar(' ');
		}
		printf("%d", g);
		insertionSort(A, n, g);
	}
	putchar('\n');
	printf("%llu\n", cnt);
	free(G);
}