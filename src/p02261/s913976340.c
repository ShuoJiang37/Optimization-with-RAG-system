#include<stdio.h>
#include <string.h>

typedef struct 
{
	char name;
	int number;
}Card;

void bubble_sort(Card *a, int n);
void selection_sort(Card *a, int n);
int isstable(Card *a, Card *b, int n);

int main(void)
{
	
	
int n, i, j, flag, result, min;
	
scanf("%d", &n);

Card card1[100];
Card card2[100];
Card card3[100];
Card temp;


for(i=0; i<n ; i++)
{
	scanf(" %c%d", &card1[i].name, &card1[i].number);
}
	
for(i=0; i<n ; i++)
{
	card2[i] = card1[i];
	
}
	
bubble_sort(card1, n);
	

printf("Stable\n");
	
	
selection_sort(card2,n);
	
	result = isstable(card1, card2, n); //0の時not stable , 1の時stable
	
	if(result==0)
	{
		printf("Not stable\n");
	}
	else if(result==1)
	{
		printf("Stable\n");
	}
	

	return 0;
	
	
}
void bubble_sort(Card *a, int n)
{
	int j, i;
	Card temp;
	
	for(int i=0; i<n ; i++) //バブルソート
	{
		for(j=n-1; j>=i+1; j--)
		{
			if(a[j].number < a[j-1].number)
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
	
	
	for(i=0; i<n-1; i++)
	{
		printf("%c%d ", a[i].name, a[i].number);
	}
	
	printf("%c%d\n", a[n-1].name, a[n-1].number);
	
}
void selection_sort(Card *a, int n)
{
	int i, j, min;
	Card temp;

	for( i=0; i<n ; i++) //選択ソート
	{
		min = i;
		
		for(j=i; j<n; j++)
		{
			if(a[j].number < a[min].number)
			{
				min = j;
				
			}
		}
		
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		
	}
	
	for(i=0; i<n-1; i++)
	{
		printf("%c%d ", a[i].name, a[i].number);
	
	}
	
	printf("%c%d\n", a[n-1].name, a[n-1].number);
	
}


int isstable(Card *a, Card *b, int n)
{
	int i, j, k, l;
	
	for(i=0; i<n; i++)
	{
		if(a[i].name != b[i].name)
		{
			return 0;
		}
	
	}
	
	return 1;

}

