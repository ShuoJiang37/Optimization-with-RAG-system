#include<stdio.h>

struct Card{
	char suit;
	int value;
};

void BubbleSort(struct Card c[], int n)
{
	int i, j;
	struct Card temp;
	
	for(i = 0; i < n; i++)
	{
		for(j = n - 1; j >= i + 1; j--)
		{
			if(c[j].value < c[j-1].value)
			{
				temp = c[j];
				c[j] = c[j - 1];
				c[j - 1] = temp;
			}
		}
	}
}
	
void SelectionSort(struct Card c[], int n)
{
	int i, j, min;
	struct Card temp;
	
	for(i = 0; i < n; i++)
	{
		min = i;
		for(j = i; j < n; j++)
		{
			if(c[j].value < c[min].value)
			{
				min = j;
			}
		}
		temp = c[i];
		c[i] = c[min];
		c[min] = temp;
	}
}

int main(void)
{
	int n, i;
	
	scanf("%d", &n);
	
	struct Card c1[n], c2[n];
	
	for(i = 0; i < n; i++)
	{
		scanf(" %c%d",&c1[i].suit, &c1[i].value);
	}
	
	for(i = 0; i < n; i++)
	{
		c2[i] = c1[i];
	}
	
	BubbleSort(c1, n);
	SelectionSort(c2, n);
	
	for(i = 0; i < n; i++)
	{
		if(i != n-1)
		{
			printf("%c%d ", c1[i].suit, c1[i].value);
		}
		else
		{
			printf("%c%d\n", c1[i].suit, c1[i].value);
		}
	}
	
	printf("Stable\n");
	
	for(i = 0; i < n; i++)
	{
		if(i != n-1)
		{
			printf("%c%d ", c2[i].suit, c2[i].value);
		}
		else
		{
			printf("%c%d\n", c2[i].suit, c2[i].value);
		}
	}
	
	for(i = 0; i < n; i++)
	{
		if(c1[i].suit != c2[i].suit)
		{
			printf("Not stable\n");
			return 0;
		}
	}
	printf("Stable\n");
	return 0;
}
	
