#include <stdio.h>          // printf(), getc()
#include <ctype.h>          // isdigit()

// #define CASE1 1
#define MAX_N 1000000
#define MAX_G 15

const char NUL = '\0';
int count;
#ifdef CASE1
int G[MAX_G];
#else
const int G[11] = {1, 8, 23, 77, 281, 1073, 4193, 16577, 65921, 262913, 1050113};
#endif
int ix;

void
insertionSort(int a[MAX_N], int n, int g)
{
	int i, j;

	for (i = g; i < n; ++i)
	{
		int v = a[i];
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
	int i;


#ifdef CASE1
	ix = 0;
	int h;
	for (h = 1; h <= n;)
	{
		G[ix++] = h;
		h = 3 * h + 1;
	}
#else
	for (ix = 0; ix < MAX_G && G[ix] <= n; ++ix)
		;
#endif

	for (i = ix - 1; i >= 0; --i)
		insertionSort(a, n, G[i]);
}

void
print_number(int n)
{
	char text[12];
	char* s = &text[11];
	*s = NUL;
	do
	{
		int m = n % 10;
		*--s = m + '0';
		n /= 10;
	} while (n != 0);

	printf("%s", s);
}

int
main(int argc, char** argv)
{
	int a[MAX_N];
	int n, m;
	int i;
	int c;

	c = getc(stdin);
	n = 0;
	while (isdigit(c))
	{
		n = n * 10 + c - '0';
		c = getc(stdin);
	}

	for (i = 0; i < n; ++i)
	{
		while (c == ' ' || c == '\n')
			c = getc(stdin);

		m = 0;
		while (isdigit(c))
		{
			m = m * 10 + c - '0';
			c = getc(stdin);
		}

		a[i] = m;
	}

	count = 0;
	shellsort(a, n);

	printf("%d\n", ix);
	for (i = ix - 1; i >= 0; --i)
		printf("%d%c", G[i], (i != 0) ? ' ' : '\n');

	printf("%d\n", count);
	for (i = 0; i < n; ++i)
	{
		print_number(a[i]);
		putchar('\n');
	}

	return 0;
}