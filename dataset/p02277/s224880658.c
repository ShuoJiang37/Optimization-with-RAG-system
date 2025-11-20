#include <stdio.h>          // printf(), scanf()

#define MAX_N 100000
#define swap(x, y) { card_t t = x; x = y; y = t; }

typedef struct card_tbl
{
	char mark;
	int val;
	int seq;
} card_t;

card_t l[MAX_N / 2 + 2], r[MAX_N / 2 + 2];

int
partition(card_t a[], int p, int r)
{
	int j;

	int x = a[r].val;
	int i = p - 1;
	for (j = p; j < r; ++j)
	{
		if (a[j].val <= x)
		{
			i++;
			swap(a[i], a[j]);
		}
	}

	swap(a[i + 1], a[r]);
	return i + 1;
}

void
quicksort(card_t a[], int p, int r)
{
	if (p < r)
	{
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

int
main(int argc, char** argv)
{
	card_t a[MAX_N];
	int n, i;

	scanf("%d\n", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%c %d\n", &a[i].mark, &a[i].val);
		a[i].seq = i;
	}

	quicksort(a, 0, n - 1);

	for (i = 0; i < n - 1; ++i)
	{
		if (a[i].val == a[i + 1].val && a[i].seq > a[i + 1].seq)
			break;
	}

	if (i >= n - 1)
		printf("Stable\n");
	else
		printf("Not stable\n");

	for (i = 0; i < n; ++i)
		printf("%c %d\n", a[i].mark, a[i].val);

	return 0;
}