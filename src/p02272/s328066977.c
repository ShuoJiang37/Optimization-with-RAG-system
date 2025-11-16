#include <stdio.h>          // printf(), scanf()
#include <string.h>         // memcpy()

#define MAX_N 500000
#define SENTINEL 2000000000

int l[MAX_N / 2 + 2], r[MAX_N / 2 + 2];
int count;

void
merge(int a[], int left, int mid, int right)
{
	int i, j, k;

	const int n1 = mid - left;
	const int n2 = right - mid;
	memcpy(l, &a[left], sizeof(int) * n1);
	memcpy(r, &a[mid], sizeof(int) * n2);

	l[n1] = SENTINEL;
	r[n2] = SENTINEL;

	i = 0, j = 0;
	for (k = left; k < right; ++k)
	{
		count++;
		if (l[i] <= r[j])
			a[k] = l[i++];
		else
			a[k] = r[j++];
	}
}

void
mergesort(int a[], int left, int right)
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
	int a[MAX_N];
	int n;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	count = 0;
	mergesort(a, 0, n);

	for (i = 0; i < n; ++i)
		printf("%d%c", a[i], (i != n - 1) ? ' ' : '\n');

	printf("%d\n", count);
	return 0;
}