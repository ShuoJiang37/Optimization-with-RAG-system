#include <stdio.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

typedef struct {
	int id;
	char pat;
	int num;
} Card;

void BubbleSort(Card *c, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j >= i + 1; j--)
		{
			if ((c + j)->num < (c + j - 1)->num)
			{
				swap(Card, *(c + j), *(c + j - 1));
			}
		}
	}
}

void SelectionSort(Card *c, int n)
{
	int i, j, m;
	for (i = 0; i < n - 1; i++)
	{
		m = i;
		for (j = i; j < n; j++)
		{
			if ((c+j)->num < (c+m)->num) m = j;
		}
		swap(Card, *(c + i), *(c + m));
	}
}

void copy(Card *c1, Card *c, int n)
{
	int i;
	Card *cp, *cp1;
	for (i = 0; i < n; i++)
	{
		cp = c + i;
		cp1 = c1 + i;

		cp1->id = cp->id;
		cp1->pat = cp->pat;
		cp1->num = cp->num;
	}
}

void dump(const Card *c, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%c%d", (c + i)->pat, (c + i)->num);
		if (i < n - 1) printf(" ");
	}
	printf("\n");
}

int isStable(Card *c, int n)
{
	Card w = { -1,' ',-1 };
	Card *cp;
	int i = 0;
	int f = 1;

	while (i < n && f)
	{
		cp = (c + i);
		if (cp->num == w.num && cp->id < w.id) f = 0;
		w.num = cp->num;
		w.id = cp->id;
		i++;
	}

	return f;
}

void checkStable(Card *c, int n)
{
	if (isStable(c, n)) printf("Stable\n");
	else printf("Not stable\n");
}

int main()
{
	int n, i;
	char w[3];
	Card c[36], c1[36];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%2s", w);
		c[i].id = i;
		c[i].pat = w[0];
		c[i].num = w[1] & 0x0F;
	}

	copy(c1, c, n);
	BubbleSort(c1, n);
	dump(c1, n);
	checkStable(c1, n);
	
	copy(c1, c, n);
	SelectionSort(c1, n);
	dump(c1, n);
	checkStable(c1, n);

	return 0;
}