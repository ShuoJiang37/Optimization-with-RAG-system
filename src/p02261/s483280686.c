#include <stdio.h>
#include <stdlib.h>

struct card {
	char color;
	int value;
};

int getNumberOfCards();
struct card* creatDeckThroughNumberOfCards(int numberOfCards);
void printCard(struct card* deck, int numberOfCards);
void copyDeck(struct card* source, struct card* target, int numberOfCards);
void swapCard(struct card* card1, struct card* card2);
void isStability(struct card* d1, struct card* d2, int numberOfCards);
void BubbleSort(struct card* deck, int numberOfCards);
void SelectionSort(struct card* deck, int numberOfCards);


int main(void)
{
	int numberOfCards = getNumberOfCards();
	struct card* deck = creatDeckThroughNumberOfCards(numberOfCards);
	// printCard(deck, numberOfCards);
	struct card* tempDeck = (struct card*) malloc(numberOfCards * sizeof(struct card));
	copyDeck(deck, tempDeck, numberOfCards);
	BubbleSort(tempDeck, numberOfCards);
	printCard(tempDeck, numberOfCards);
	isStability(deck, tempDeck, numberOfCards);
	copyDeck(deck, tempDeck, numberOfCards);
	SelectionSort(tempDeck, numberOfCards);
	printCard(tempDeck, numberOfCards);
	isStability(deck, tempDeck, numberOfCards);
	return 0;
}

int getNumberOfCards()
{
	int input;
	scanf("%d", &input);
	return input;
}

struct card* creatDeckThroughNumberOfCards(int numberOfCards)
{
	struct card *deck = (struct card*) malloc(numberOfCards * sizeof(struct card));
	int i;
	char ch;
	for (i = 0; i < numberOfCards; i++)
	{
		ch = getchar();
		while (ch == ' ' || ch == '\n')
			ch = getchar();
		(*(deck + i)).color = ch;
		scanf("%d", &((*(deck + i)).value));
	}
	return deck;
}

void printCard(struct card* deck, int numberOfCards)
{
	int i;
	for (i = 0; i < numberOfCards - 1; i++)
		printf("%c%d ", (*(deck + i)).color, (*(deck + i)).value);
	printf("%c%d\n", (*(deck + i)).color, (*(deck + i)).value);
}

void copyDeck(struct card* source, struct card* target, int numberOfCards)
{
	int i;
	for (i = 0; i < numberOfCards; i++)
	{
		(target + i)->color = (source + i)->color;
		(target + i)->value = (source + i)->value;
	}
}

void swapCard(struct card* card1, struct card* card2)
{
	struct card ca;
	ca.color = card1->color;
	ca.value = card1->value;
	card1->color = card2->color;
	card1->value = card2->value;
	card2->color = ca.color;
	card2->value = ca.value;
}

void isStability(struct card* d1, struct card* d2, int numberOfCards)
{
	int i, j, k;
	for (i = 0; i < numberOfCards - 1; i++)
	{
		if ((d2 + i)->value == (d2 + i + 1)->value)
		{
			for (j = 0; j < numberOfCards; j++)
			{
				if ((d1 + j)->value == (d2 + i)->value)
				{
					if ((d1 + j)->color == (d2 + i)->color)
						break;
					if ((d1 + j)->color == (d2 + i + 1)->color)
					{
						printf("Not stable\n");
						return;
					}
					else
						continue;
				}
			}
		}
	}
	printf("Stable\n");
}

void BubbleSort(struct card* deck, int numberOfCards)
{
	int i, j;
	for (i = 0; i < numberOfCards - 1; i++)
	{
		for (j = numberOfCards - 1; j > i; j--)
		{
			if ((deck + j)->value < (deck + j - 1)->value)
			{
				swapCard(deck + j, deck + j - 1);
			}
		}
	}
}

void SelectionSort(struct card* deck, int numberOfCards)
{
	int i, j;
	int subOfMin;
	for (i = 0; i < numberOfCards - 1; i++)
	{
		subOfMin = i;
		for (j = i + 1; j < numberOfCards; j++)
		{
			if ((deck + j)->value < (deck + subOfMin)->value)
				subOfMin = j;
		}
		if (subOfMin != i)
			swapCard(deck + i, deck + subOfMin);
	}
}
