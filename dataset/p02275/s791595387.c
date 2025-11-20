#include <stdio.h>          // printf(), scanf()
#include <stdlib.h>         // malloc(), free()
#include <string.h>         // memset()

#define MAX_N 2000000
#define MAX_V 10000


int
main(int argc, char** argv)
{
	unsigned short *a, *b;
	int c[MAX_V + 1];
	int n;
	int i;

	scanf("%d", &n);
	a = malloc(sizeof(short) * n + 1);
	b = malloc(sizeof(short) * n + 1);
	memset(c, 0, sizeof(int) * MAX_V + 1);

	for (i = 0; i < n; ++i)
	{
		scanf("%hu", &a[i + 1]);
		c[a[i + 1]]++;
	}

	for (i = 1; i <= MAX_V; ++i)
		c[i] = c[i] + c[i - 1];

	for (i = n; i >= 1; --i)
	{
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}

	for (i = 1; i <= n; ++i)
		printf("%d%c", b[i], (i != n) ? ' ' : '\n');

	free(a);
	free(b);
	return 0;
}