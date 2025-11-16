#include <stdio.h>

#define CARD_MAX (36)

typedef struct _card {
	char suit;
	int number;
} CARD;

void CheckStable(CARD org[], CARD srt[], int len);
void Swap(CARD c[], int a, int b);
void BubbleSort(CARD c[], int len);
void SelectionSort(CARD c[], int len);
void PrintCards(CARD c[], int len);

int main(void) {
	int N, i;
	CARD input[CARD_MAX + 1];
	CARD bub[CARD_MAX + 1];
	CARD sel[CARD_MAX + 1];
	
	scanf("%d\n", &N);
	for (i = 1; i <= N; ++i) {
		scanf("%c%d ", &input[i].suit, &input[i].number);
		bub[i] = sel[i] = input[i];
	}
	
	BubbleSort(bub, N);
	PrintCards(bub, N);
	CheckStable(input, bub, N);
	
	SelectionSort(sel, N);
	PrintCards(sel, N);
	CheckStable(input, sel, N);
	
	return 0;
}

void CheckStable(CARD org[], CARD srt[], int len) {
	int chk[CARD_MAX + 1] = {0};
	int i, j, t;
	for (i = 1; i <= len; ++i) {
		t = ++chk[srt[i].number];
		for (j = 1; j <= len; ++j) {
			if (org[j].number == srt[i].number) {
				if (--t == 0) {
					if (org[j].suit != srt[i].suit) {
						printf("Not stable\n");
						return;
					}
				}
			}
		}
	}
	printf("Stable\n");
}

void PrintCards(CARD c[], int len) {
	int i;
	for (i = 1; i <= len; ++i) {
		if (i > 1) {
			putchar(' ');
		}
		printf("%c%d", c[i].suit, c[i].number);
	}
	putchar('\n');
}

void Swap(CARD c[], int a, int b) {
	CARD t = c[a];
	c[a] = c[b];
	c[b] = t;
}

void BubbleSort(CARD c[], int len) {
	int i, j;
	for (i = 1; i <= len; ++i) {
		for (j = len; j >= i + 1; --j) {
			if (c[j].number < c[j - 1].number) {
				Swap(c, j, j - 1);
			}
		}
	}
}

void SelectionSort(CARD c[], int len) {
	int i, j, mini;
	for (i = 1; i <= len; ++i) {
		mini = i;
		for (j = i; j <= len; ++j) {
			if (c[j].number < c[mini].number) {
				mini = j;
			}
		}
		Swap(c, i, mini);
	}
}