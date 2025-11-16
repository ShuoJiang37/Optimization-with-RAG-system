#include <stdio.h>
#include <string.h>

struct card{
	char suit;
	int value;
};

int main(void)
{
	int n , i , j , minj , count = 0;
	scanf("%d",&n);
	struct card  c[n];
	struct card  b[n];
	struct card  tmp;
	
	for( i = 0; i < n; i++)
	{
		scanf(" %c%d",&c[i].suit,&c[i].value);
		b[i] = c[i];
	}
	for( i = 0; i < n; i++)//Bubblesort
	{
		for( j = n-1; j >= i+1; j--)
		{
			if(c[j].value < c[j-1].value)
			{
				tmp = c[j];
				c[j] = c[j-1];
				c[j-1] = tmp;
			}
		}
	}
	
	
	for(i = 0; i < n; i++)
	{
		if(i != n-1)
		{
			printf("%c%d ",c[i].suit,c[i].value);
		}
			else{printf("%c%d\n",c[i].suit,c[i].value);}
	}
	
	printf("Stable\n");

	for( i = 0; i <= n-1; i++)//SelectionSort
	{
		minj = i;
		for( j = i; j <= n-1; j++)
		{
			if(b[j].value < b[minj].value)
			{
				minj = j;
			}
		}
		tmp = b[i];
		b[i] = b[minj];
		b[minj] = tmp;
	}
	
	for(i = 0; i < n; i++)
	{
		if(i != n-1)
		{
			printf("%c%d ",b[i].suit,b[i].value);
		}
			else{printf("%c%d\n",b[i].suit,b[i].value);}
	}
	
	for( i = 0; i < n; i++)
	{
		if(b[i].suit!=c[i].suit)
		{
			count++;
		}
	}
	
	if(count == 0)printf("Stable\n");
		else{printf("Not stable\n");}
}
