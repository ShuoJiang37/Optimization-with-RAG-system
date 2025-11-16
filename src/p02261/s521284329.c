#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap(int* x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

void insertSort(int p[], int n)
{
	int i, j,k;

	for (i = 1; i < n; i++)
	{
		j = i;
		while (j >= 1 && (p[j] < p[j - 1]))
		{
			swap(&p[j], &p[j - 1]);
			j--;
		}

		for (k = 0; k < n-1; k++)
			printf("%d ", p[k]);

		printf("%d\n",p[n-1]);
	}
}

int GCD(int x, int y)
{
	if (x < y)
		swap(&x, &y);

	if (y == 0)
		return x;

	return GCD(y, x % y);
}

int not_prime_count(int p[], int n)
{
	int count = 0;
	int i, j;
	int num;

	for (i = 0; i < n; i++)
	{
		for (j = 2; j < (int)(sqrt(p[i])+1); j++)
		{
			if (p[i] % j == 0)
			{
				count++;
				break;
			}
		}
	}
	return count;
}

typedef struct T
{
	char mark;
	int num;
}T;

int bubble_sort(T p[], int n)
{
	int i, j;
	int count = 0;
	char temp;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (p[j].num > p[j + 1].num)
			{
				swap(&p[j].num, &p[j + 1].num);
				temp = p[j].mark;
				p[j].mark = p[j + 1].mark;
				p[j + 1].mark = temp;

				count++;
			}
		}
	}
	for (i = 0; i < n - 1; i++)
		printf("%c%d ", p[i].mark,p[i].num);
	printf("%c%d\n", p[n-1].mark,p[n - 1].num);

	return count;
}

int selection_sort(T p[],int n)
{
	int i, j, min;
	int count = 0;
	char temp;

	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i; j < n; j++)
		{
			if (p[j].num < p[min].num)
				min = j;
		}

		if (i != min)
		{
			swap(&p[i].num, &p[min].num);
			temp = p[i].mark;
			p[i].mark = p[min].mark;
			p[min].mark = temp;
			count++;
		}
	}

	for (i = 0; i < n - 1; i++)
		printf("%c%d ", p[i].mark, p[i].num);
	printf("%c%d\n", p[n - 1].mark, p[n - 1].num);

	return count;
}

T card[100];
T card2[100];

int main()
{
	int n;
	int temp;


	scanf("%d", &n);

	int i;
	char t;

	scanf("%c", &t);

	for (i = 0; i < n; i++)
	{
		scanf("%c%d", &card[i].mark, &card[i].num);
		//printf("%c%d\n", card[i].mark, card[i].num);

		scanf("%c", &t);
	}

	memcpy(card2, card, sizeof(T) * n);

	bubble_sort(card, n);
	printf("Stable\n");
	selection_sort(card2,n);

	for (i = 0; i < n; i++)
	{
		if ((card[i].num == card2[i].num) && (card[i].mark != card2[i].mark))
		{
			printf("Not stable\n");
			return 0;
		}
	}
	printf("Stable\n");
}
