#include<stdio.h>
#define MAX 100

void inputData(int *R, int *N)
{
	scanf("%d", N);
	for (int i = 0; i < *N; i++)
	{
		scanf("%d", &R[i]);
	}
}

void traceData(int *R, int N)
{
	int i;
	for (i = 0; i < (N - 1); i++)
	{
		printf("%d ", R[i]);
	}
	printf("%d\n", R[i]);
}

int bubbleSort(int *R, int N)
{
	int isSwapping = 1;
	int swappingCount = 0;
	while (isSwapping)
	{
		isSwapping = 0;
		for (int i = N - 1; i > 0; i--)
		{
			if (R[i - 1] > R[i])
			{
				int temp = R[i];
				R[i] = R[i - 1];
				R[i - 1] = temp;
				isSwapping = 1;
				swappingCount++;
			}
		}

	}
	return swappingCount;
}

int main(void)
{
	int R[MAX], N;
	inputData(R, &N);
	int t = bubbleSort(R, N);
	traceData(R, N);
	printf("%d\n", t);
	return 0;
}