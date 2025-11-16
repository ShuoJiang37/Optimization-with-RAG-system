#include<stdio.h>
int main() {
	int n, i, j, m = 0, f = 0;
	int A[10001] = {};
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &i);
		A[i]++;
		if (i > m) m = i;
	}
	for (i = 0; i <= m; i++)
		for (j = 0; j < A[i]; j++) {
			if (f) printf(" ");
			printf("%d",i),f=1;
		}
	puts("");
	return 0;
}