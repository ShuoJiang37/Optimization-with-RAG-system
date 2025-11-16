//2016/11/3
//stable sort


#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
				char suit;
				int  num;
}card;

int n;

void bubble_sort(card*, int);
void selection_sort(card*, int);


int main(void)
{
	int i;
	card c[36], bubble[36], selection[36];

	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		scanf(" %c%d", &c[i].suit, &c[i].num);
	}

	for(i = 0; i < n; i++)
	{
		bubble[i] = c[i];
		selection[i] = c[i];

	}

	bubble_sort(bubble,n);

	for(i = 0; i < n; i++)
	{
		if (i == n-1)
		{
			printf("%c%d\n", bubble[i].suit, bubble[i].num);
		}else
		{
			printf("%c%d ", bubble[i].suit, bubble[i].num);
		}
	}

	printf("Stable\n");

	selection_sort(selection, n);

	for(i = 0; i < n; i++)
	{
		if (i == n-1)
		{
			printf("%c%d\n", selection[i].suit, selection[i].num);
		}else
		{
			printf("%c%d ", selection[i].suit, selection[i].num);
		}
	}

	for(i = 0; i < n; i++)
	{
		if (selection[i].suit != bubble[i].suit && selection[i].num == bubble[i].num)
		{
			printf("Not stable\n");
			return 0;
		}
	}

	printf("Stable\n");

	return 0;
}



void bubble_sort(card *a,int n)
{
	int i;
	int tempnum, flag = 1;
	char tempsuit;

	while(flag)
	{
		flag = 0;

		for(i = n-1; i > 0; i--)
		{
			if (a[i].num < a[i-1].num)
			{
				tempnum = a[i].num;
				tempsuit = a[i].suit;

				a[i].num = a[i-1].num;
				a[i].suit = a[i-1].suit;

				a[i-1].num = tempnum;
				a[i-1].suit = tempsuit;

				flag = 1;
			}
		}
	}
}


void selection_sort(card *a, int n)
{
	int i,j;
	int min, tempnum;
	char tempsuit;

	for(i = 0; i < n; i++)
	{
		min = i;

		for(j = i; j < n; j++)
		{
			if (a[min].num > a[j].num)
			{
				min = j;
			}
		}

		if (i != min)
		{
			tempnum = a[i].num;
			tempsuit = a[i].suit;

			a[i].num = a[min].num;
			a[i].suit = a[min].suit;

			a[min].num = tempnum;
			a[min].suit = tempsuit;
		}

	}
}