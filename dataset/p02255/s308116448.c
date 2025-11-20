
#include <stdio.h>

int main() {
	int i, j, k, n, v;
	int a[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++) {
		v = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > v) {
			a[j+1] = a[j];
			a[j] = v;
			j--;
		}
		a[j+1] = v;

		for (j = 0; j < n - 1; j++) {
			printf("%d ", a[j]);
		}

		printf("%d\n", a[n - 1]);
	}

	return 0;
}

