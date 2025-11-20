#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y) {char *z; z = x; x = y; y = z;}

void dispIsStable(char **cards1, char **cards2, int card_num) 
{
	int i;

	for(i = 0; i < card_num; i++) {
		if(strcmp(cards1[i], cards2[i]) != 0) {
			printf("Not stable\n");
			return;
		}
	}
	printf("Stable\n");
}

int cardtoi(char *card)
{
	return atoi(card + 1);
}

void dispCards(char **cards, int card_num) 
{
	int i;

	printf("%s", cards[0]);
	
	for(i = 1; i < card_num; i++) {
		printf(" %s", cards[i]);
	}
	printf("\n");
}

void bubbleSort(char **cards, int card_num)
{
	int i, j;

	for(i = 0; i < card_num - 1; i++) {
		for(j = card_num - 1; j > i; j--) {
			if(cardtoi(cards[j]) < cardtoi(cards[j - 1]))
				SWAP(cards[j], cards[j - 1]);
		}
	}

}

void selectionSort(char **cards, int card_num) 
{
	int i, j, min_index;

	for(i = 0; i < card_num; i++) {
		min_index = i;
		for(j = i; j < card_num; j++) {
			if(cardtoi(cards[j]) < cardtoi(cards[min_index]))
				min_index = j;
		}
		if(min_index != i)
			SWAP(cards[i], cards[min_index]);
	}

}

int main(void) 
{
	int n, i;
	char **cards4bubble, **cards4selection;

	scanf("%d", &n);
	cards4bubble = malloc(sizeof(char *) * n);	
	cards4selection = malloc(sizeof(char *) * n);
	for(i = 0; i < n; i++) {
		cards4bubble[i] = malloc(sizeof(char) * 2);
		scanf("%s", cards4bubble[i]);
		cards4selection[i] = strdup(cards4bubble[i]);
	}
	bubbleSort(cards4bubble, n);
	selectionSort(cards4selection, n);
	dispCards(cards4bubble, n);
	printf("Stable\n");
	dispCards(cards4selection, n);
	dispIsStable(cards4bubble, cards4selection, n);
	return 0;
}