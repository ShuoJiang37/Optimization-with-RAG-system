#include <stdio.h>          // printf(), scanf()
#include <stdlib.h>         // qsort()
#include <stdbool.h>

#define MAX_N 1000
#define MAX_V 10000
#define min(a, b) ((a) < (b) ? a : b)

int a[MAX_N];
int n;

int
cmp_func(const void *l_, const void *r_)
{
	const int* l = (const int*) l_;
	const int* r = (const int*) r_;

	if (*l < *r)
		return -1;

	if (*l > *r)
		return 1;

	return 0;
}

int
solve()
{
	int b[MAX_N];
	int t[MAX_V + 1];
	bool v[MAX_N];
	int i;

	int ans = 0;
	for (i = 0; i < n; ++i)
	{
		b[i] = a[i];
		v[i] = false;
	}

	qsort(b, n, sizeof(int), cmp_func);
	for (i = 0; i < n; ++i)
		t[b[i]] = i;

	for (i = 0; i < n; ++i)
	{
		if (v[i])
			continue;

		int cur = i;
		int s = 0;
		int m = MAX_V;
		int an = 0;
		while (true)
		{
			v[cur] = true;
			an++;
			int u = a[cur];
			if (u < m)
				m = u;

			s += u;
			cur = t[u];
			if (v[cur])
				break;
		}

		ans += min(s + (an - 2) * m, s + m + (an + 1) * b[0]);
	}

	return ans;
}

int
main(int argc, char** argv)
{
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	printf("%d\n", solve());
	return 0;
}