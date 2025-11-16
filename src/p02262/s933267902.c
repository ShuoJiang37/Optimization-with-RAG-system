#include<stdio.h>

int cnt, h, c;
int g[1000000];

void insertionSort(int a[], int n, int g)
{
	int i, v, j;

	for(i = g; i < n; i++)
	{
		v = a[i];
		j = i - g;
		while(j >= 0 && a[j] > v)
		{
			a[j+ g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j + g] = v;
	}
}

void shellSort(int a[], int n)
{
	int i;
	
	for(h = 1;;)
	{
		if(h > n){
			break;
		}
		h = 3 * h + 1;
		c++;
	}
	
	g[0] = 1;
	
	for(i = 1; i < c; i++)
	{
		g[i] = 3 * g[i - 1] + 1;
	}
	
	
	for(i = c - 1; i >= 0; i--)
	{
		insertionSort(a, n, g[i]);
	}
}

int main(void)
{
	int n, i;
	
	scanf("%d", &n);
	
	int a[n];
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	cnt = 0;
	c = 0;
	
	shellSort(a,n);
	
	
	printf("%d\n", c);
	
	for(i = c - 1; i >= 0; i--)
	{
		if(i != 0)
		{
			printf("%d ", g[i]);
		}
		else
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
