#include <stdio.h>

typedef struct { char s; int v; } Card;

void card_swap(Card *a, Card *b)
{
	Card t = *a; *a = *b; *b = t;
}

void card_print(Card *cards, int n)
{
	for(int i = 0; i < n - 1; ++i)
	{
		printf("%c%d ", cards[i].s, cards[i].v);
	}
	printf("%c%d\n", cards[n-1].s, cards[n-1].v);
}

void bubble_sort(Card *cards, int n)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = n - 1; j > i; --j)
		{
			if(cards[j].v < cards[j-1].v)
			{
				card_swap(&cards[j], &cards[j-1]);
			}
		}
	}
}

void select_sort(Card *cards, int n)
{
	for(int i = 0; i < n; ++i)
	{
		int minj = i;
		for(int j = i + 1; j < n; ++j)
		{
			if(cards[j].v < cards[minj].v)
			{
				minj = j;
			}
		}
		card_swap(&cards[i], &cards[minj]);
	}
}

int main()
{
	int n, match;
	Card b[36], s[36];
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		char input[4];
		scanf("%s", input);

		b[i].s = s[i].s = input[0];
		b[i].v = s[i].v = input[1] - '0';
	}
	
	bubble_sort(b, n);
	select_sort(s, n);
	
	match = 1;
	for(int i = 0; i < n; ++i)
	{
		if(b[i].s != s[i].s)
		{
			match = 0;
			break;
		}
	}
	
	card_print(b, n);
	printf("Stable\n");
	card_print(s, n);
	printf(match ? "Stable\n" : "Not stable\n");
}

