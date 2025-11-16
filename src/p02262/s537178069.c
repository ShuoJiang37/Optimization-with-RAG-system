#include <stdio.h>

int data[1000000];

int insert_sort(int *a, int n, int g)
{
	int swap_count = 0;
	for(int i = g; i < n; ++i)
	{
		int v = a[i];
		int j = i - g;
		while((0 <= j) && (v < a[j]))
		{
			a[j+g] = a[j];
			j -= g;
			++swap_count;
		}
		a[j+g] = v;
	}
	return swap_count;
}

int main()
{
	int n, m, g;
	int swap_count = 0;
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &data[i]);
	}
	
	for(m = 0, g = 1; g <= n; ++m)
	{
		g = 3 * g + 1;
	}
	
	printf("%d\n", m);
	while(1)
	{
		g = (g - 1) / 3;
		printf("%d", g);
		swap_count += insert_sort(data, n, g);
		
		if(g == 1)
		{
			break;
		}
		printf(" ");
	}
	printf("\n%d\n", swap_count);
	
	for(int i = 0; i < n; ++i)
	{
		printf("%d\n", data[i]);
	}
}

