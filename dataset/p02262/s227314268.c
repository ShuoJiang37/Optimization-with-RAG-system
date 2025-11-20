// Written by	: by_sknight
// Date			: 2018-11-14

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getnumberOfArray();
long* creatArrayWithNumberOfArray(int nubmerOfArray);
int* getStepOrder(int numberOfNeedSortArray, int* pLen);
void ShellSort(long* array, int len, int *pCount);
void shellSortWithOneStep(long *array, int len, int step,int *pCount);
void printArray(long* array, int len);


int main(void)
{
	int nubmerOfArray = getnumberOfArray();
	long *array = creatArrayWithNumberOfArray(nubmerOfArray);
	int count;
	ShellSort(array, nubmerOfArray, &count);
	// printArray(array, nubmerOfArray);
	printf("%d\n", count);
	int i;
	for (i = 0; i < nubmerOfArray; i++)
	{
		printf("%ld\n", *(array + i));
	}
}

int getnumberOfArray()
{
	int input;
	scanf("%d", &input);
	return input;
}

long* creatArrayWithNumberOfArray(int nubmerOfArray)
{
	int i;
	long* array = (long*) malloc(nubmerOfArray * sizeof(long));
	for (i = 0; i < nubmerOfArray; i++)
		scanf("%ld", array + i);
	return array;
}

int* getStepOrder(int numberOfNeedSortArray, int* pLen)
{
	// printf("getStepSort\n");
	int i;
	int *tempArray = (int*) malloc(numberOfNeedSortArray * sizeof(int));
	for (i = 0; i < numberOfNeedSortArray; i++)
	{
		if (numberOfNeedSortArray / (pow(2, i + 1)) < 1)
			break;
		*(tempArray + i) = numberOfNeedSortArray / (pow(2, i + 1));
		// printf("tempArray %d : %d\n", i, *(tempArray + i));
	}
	*pLen = i;
	int *array = (int *) malloc(*pLen * sizeof(int));
	for (i = 0; i < *pLen; i++)
	{
		*(array + i) = *(tempArray + i);
	}
	return array;
}

void ShellSort(long* array, int len, int *pCount)
{
	if (len != 1)
	{
		*pCount = 0;
		int i;
		int numberOfOrder;
		int* order = getStepOrder(len, &numberOfOrder);
		printf("%d\n", numberOfOrder);
		//*****
		for (i = 0; i < numberOfOrder - 1; i++)
		{
			printf("%d ", *(order + i));
		}
		printf("%d\n", *(order + i));
		//*****

		for (i = 0; i < numberOfOrder; i++)
		{
			shellSortWithOneStep(array, len, *(order + i), pCount);
		}
	}
	else
	{
		*pCount = 0;
		printf("1\n");
		printf("1\n");
		shellSortWithOneStep(array, len, 1, pCount);
	}
}

void shellSortWithOneStep(long *array, int len, int step,int *pCount)
{
	int i, j;
	long temp;
	for (i = step; i < len; i++)
	{
		// printf("i = %d\n", i);
		temp = *(array + i);
		j = i - step;
		// printf("j = %d\n", j);
		while (j >= 0 && *(array + j) > temp)
		{
			// printf("i = %d && j = %d\n", i, j);
			*(array + j + step) = *(array + j);
			j -= step;
			(*pCount)++;
		}
		*(array + j + step) = temp;
	}
}

void printArray(long* array, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%ld ", *(array + i));
	printf("\n");
}
