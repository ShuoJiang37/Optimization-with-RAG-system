#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int insertionSort(int *, int, int);
void shellSort(int *, int);

int main() {
	int n;
	scanf("%d", &n);
	int *A = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);

	shellSort(A, n);
	return 0;
}

int insertionSort(int *a, int max, int g) {
	int i, j;
	int count = 0;
	for (i = g; i < max; i++) {
		int key = a[i];
		for (j = i - g; j >= 0 && a[j] > key; count++) {
			a[j + g] = a[j];
			j -= g;
		}
		a[j + g] = key;
	}
	return count;
}

void shellSort(int *a, int max) {
	int count = 0, m = 0;
	int i;
	int *g = (int *)malloc(max * sizeof(int));

	int denom = 2;
	if (max == 1) {
		g[m] = max;
		m++;
	}
	else {
		while (max / denom > 0) {
			g[m] = max / denom;
			denom *= 2;
			m++;
		}
	}

	for (i = 0; i < m; i++) {
		count += insertionSort(a, max, g[i]);
	}

	printf("%d\n", m);
	
	for (i = 0; i < m - 1; i++) printf("%d ", g[i]);
	printf("%d\n", g[i]);
	
	printf("%d\n", count);
	
	for (i = 0; i < max - 1; i++) printf("%d ", a[i]);
	printf("%d\n", a[i]);
}

