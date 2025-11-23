#include <stdio.h>

void print(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d", a[i]);
		if (i != N - 1)
		{
			printf(" ");
		}
		
	}
	printf("\n");
}
int main()
{
	int a[100];
	int key;
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		
	}


	print(a, N);


	int j;
	for (int i = 1; i < N; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
			a[j + 1] = key;
		}
		print(a, N);
	}

	return 0;
}
