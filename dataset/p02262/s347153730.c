#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 1000000
#define M_MAX 100

int count = 0;

int
insertion_sort(int *a, int n, int g)
{
	int i, j, v;

	if (g == 0)
		return 1;

	for (i = g; i < n; i++) {
		v = a[i];
		j = i - g;
		while (0 <= j && v < a[j]) {
			a[j + g] = a[j];
			j -= g;
			count++;
		}
		a[j + g] = v;
	}
	return 0;
}

int
shell_sort(int *a, int n, int m, int *g)
{
	int i;
	count = 0;

	for (i = m - 1; i >= 0; i--)
		insertion_sort(a, n, g[i]);
}

int
main(int argc, char **argv)
{
	int p0, n = 0, m, i;
	int *a;
	int g[M_MAX];

	scanf("%d", &p0);

	if (p0 < 1 || N_MAX < p0)
		return 1;

	a = (int *)malloc(sizeof(int) * p0);
	if (a == NULL)
		return 1;

	for (n = 0; n < p0; n++)
		scanf("%d", a + n);

	m = 1;
	g[0] = 1;
	while ((1 << (m * 2)) < (n / 2)) {
		g[m] = (1 << (m * 2)) - 1;
		m++;
	}

	printf("%d\n%d", m, g[m - 1]);
	for (i = m - 2; i >= 0; i--)
		printf(" %d", g[i]);
	printf("\n");

	shell_sort(a, n, m, g);
	printf("%d\n", count);
	if (argc < 2) {
		for (i = 0; i < n; i++)
			printf("%d\n", a[i]);
	}

	return 0;
}

