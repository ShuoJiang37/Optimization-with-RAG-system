#include <stdio.h>          // printf(), scanf()
#include <string.h>         // memcpy()

#define MAX_N 100000
#define SENTINEL 2000000000
#define swap(x, y) { card_t t = x; x = y; y = t; }

typedef struct card_tbl
{
	char mark;
	int val;
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

void
merge(card_t a[], int left, int mid, int right)
{
	int k;

	const int n1 = mid - left;
	const int n2 = right - mid;
	memcpy(l, &a[left], sizeof(card_t) * n1);
	memcpy(r, &a[mid], sizeof(card_t) * n2);
	l[n1].val = SENTINEL, r[n2].val = SENTINEL;

	int i = 0, j = 0;
	for (k = left; k < right; ++k)
	{
		if (l[i].val <= r[j].val)
			a[k] = l[i++];
		else
			a[k] = r[j++];
	}
}

void
mergesort(card_t a[], int left, int right)
{
	if (left + 1 < right)
	{
		int mid = (left + right) / 2;
		mergesort(a, left, mid);
		mergesort(a, mid, right);
		merge(a, left, mid, right);
	}	
}

int
main(int argc, char** argv)
{
	card_t a[MAX_N];
	card_t b[MAX_N];
	int n, i;

	scanf("%d\n", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%c %d\n", &a[i].mark, &a[i].val);
		b[i].mark = a[i].mark;
		b[i].val = a[i].val;
	}

	quicksort(a, 0, n - 1);
	mergesort(b, 0, n);

	for (i = 0; i < n; ++i)
	{
		if (a[i].mark != b[i].mark)
			break;
	}

	if (i >= n)
		printf("Stable\n");
	else
		printf("Not stable\n");

	for (i = 0; i < n; ++i)
		printf("%c %d\n", a[i].mark, a[i].val);

	return 0;
}