#include <stdio.h>          // printf(), scanf()
#define MAX_N 1000000
#define MAX_G 15

int count;
const int G[11] = {1, 8, 23, 77, 281, 1073, 4193, 16577, 65921, 262913, 1050113};
int ix = 0;

void
insertionSort(int a[MAX_N], int n, int g)
{
	int v;
	int i, j;

	for (i = g; i < n; ++i)
	{
		v = a[i];
		for (j = i - g; j >= 0 && v < a[j]; j -= g)
		{
			a[j + g] = a[j];
			count++;
		}

		a[j + g] = v;
	}
}

void
shellsort(int a[MAX_N], int n)
{
//	int h;
	int i;

	for (ix = 0; ix < MAX_G && G[ix] <= n; ++ix)
		;

#if 0
	ix = 0;
	for (h = 1; h <= n;)
	{
		G[ix++] = h;
		h = 3 * h + 1;
	}
#endif

	for (i = ix - 1; i >= 0; --i)
		insertionSort(a, n, G[i]);
}

int
main(int argc, char** argv)
{
	int a[MAX_N];
	int n;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	count = 0;
	shellsort(a, n);

	printf("%d\n", ix);
	for (i = ix - 1; i >= 0; --i)
		printf("%d%c", G[i], (i != 0) ? ' ' : '\n');

	printf("%d\n", count);
	for (i = 0; i < n; ++i)
		printf("%d\n", a[i]);

	return 0;
}