#include<stdio.h>

int SelectSort(int a[], int n)
{
	int i, j, t, minj, tot = 0;
	for (i = 0; i < n - 1; i++)
	{
		minj = i;
		for (j = i; j < n; j++)
		{
			if (a[minj] > a[j])
				minj = j;
		}
		t = a[i]; a[i] = a[minj];a[minj] = t;
		if (i != minj)
			tot++;
	}
	return tot;
}

int main()
{
	int a[105];
	int n, i, tot;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	tot = SelectSort(a, n);
	for (i = 0; i < n; i++)
		printf("%d%c", a[i], n - 1 == i ? '\n' : ' ');
	printf("%d\n", tot);
	return 0;
}