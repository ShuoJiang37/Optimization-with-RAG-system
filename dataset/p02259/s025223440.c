#include <stdio.h>
#include <stdlib.h>

static int cnt = 0;
int *a, temp, n;

void trace(int a[], int n) {
	int i;

	for (i = 1; i <= n; i++) {
		if (i > 1) {
			printf(" ");
		}
		printf("%d", a[i]);
	}
	printf("\n%d\n", cnt);

}

void BubbleSort() {
	int i, j;

	for (i = 1; i < n; i++) {
		for (j = n; j > i; j--) {
			if (a[j] < a[j - 1]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				cnt++;
			}
		}
	}

}

int main(void) {
	int i;

	scanf("%d", &n);
	a = (int *) malloc(sizeof(int) * (n + 1));

	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	BubbleSort();

	trace(a, n);

	return 0;
}