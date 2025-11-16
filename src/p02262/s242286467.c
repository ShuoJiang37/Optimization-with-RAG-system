#include <stdio.h>

int i,j;
int n, cnt, a[1000000] = {0}, g[1000000] = {0};

void insertion_sort(int*, int, int);

int main(void)
{
	int k;
	int m;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	cnt = 0;
	g[0] = 1;
	m = 1;
	i = 0;

	while(3 * g[i] + 1 < n)
	{
		g[i+1] = 3 * g[i] + 1;
		m++;
		i++;
	}

	for(k = m-1; k >= 0; k--)
	{
		insertion_sort(a, n, g[k]);
	}

	printf("%d\n", m);

	for(i = m-1; i >=0; i--)
	{
		if (i != 0)
		{
			printf("%d ", g[i]);
		}else
		{
			printf("%d\n", g[i]);
		}
	}

	printf("%d\n", cnt);

	for(i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}

	return 0;
}


void insertion_sort(int *a, int n, int g)
{
	int v;

	for(i = g; i < n; i++)
	{
		v = a[i];
		j = i - g;

		while(j >= 0 && a[j] > v)
		{
			a[j + g] = a[j];
			j = j - g;
			cnt++;
		}

		a[j + g] = v;
	}
}