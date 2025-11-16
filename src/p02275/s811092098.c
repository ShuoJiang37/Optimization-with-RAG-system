#include <stdio.h>          // printf(), scanf()
#define MAX_N 2000000
#define MAX_V 10001

int a[MAX_N];
int c[MAX_V] = { 0 };

int
main(int argc, char** argv)
{
	int t;
	int n;
	int i, j;

	scanf("%d", &n);
	int max = 0;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &t);
		a[i] = t;
		c[t]++;
		if (t > max)
			max = t;
	}

	const char* sep = "";
	for (i = 0; i <= max; ++i)
	{
		for (j = 0; j < c[i]; ++j)
		{
			printf("%s%d", sep, i);
			sep = " ";
		}
	}

	printf("\n");
	return 0;
}