#include <stdio.h>          // printf(), scanf()
#include <stdbool.h>

#define MAX_N 36
#define swap(x, y) {char t = x[0]; x[0] = y[0]; y[0] = t; t = x[1]; x[1] = y[1]; y[1] = t;}

void
bubblesort(char c[MAX_N][2], int n)
{
	int i, j;

	bool b = true;
	for (i = 0; b; ++i)
	{
		b = false;
		for (j = n - 1; j >= i + 1; --j)
		{
			if (c[j - 1][1] > c[j][1])
			{
				swap(c[j - 1], c[j]);
				b = true;
			}
		}
	}
}

void
selectionsort(char c[MAX_N][2], int n)
{
	int i, j;

	for (i = 0; i < n; ++i)
	{
		int minj = i;
		for (j = i; j < n; ++j)
		{
			if (c[j][1] < c[minj][1])
				minj = j;
		}

		if (i != minj)
			swap(c[i], c[minj]);
	}
}

int
main(int argc, char** argv)
{
	char c1[MAX_N][2];
	char c2[MAX_N][2];
	int n;
	int i;

	scanf("%d\n", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%c%c ", &c1[i][0], &c1[i][1]);
		c2[i][0] = c1[i][0];
		c2[i][1] = c1[i][1];
	}

	bubblesort(c1, n);
	for (i = 0; i < n; ++i)
		printf("%c%c%c", c1[i][0], c1[i][1], (i != n - 1) ? ' ' : '\n');

	printf("Stable\n");

	selectionsort(c2, n);
	for (i = 0; i < n; ++i)
		printf("%c%c%c", c2[i][0], c2[i][1], (i != n - 1) ? ' ' : '\n');

	for (i = 0; i < n; ++i)
	{
		if (c1[i][0] != c2[i][0] || c1[i][1] != c2[i][1])
			break;
	}

	if (i >= n)
		printf("Stable\n");
	else
		printf("Not stable\n");

	return 0;
}