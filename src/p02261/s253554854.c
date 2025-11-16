#include<stdio.h>

typedef struct {
	char suit;
	char value;
} Card;

Card C1[101], C2[101];
static int n;

void trace(Card *c) {
	int i;

	for (i = 1; i <= n; i++) {
		if (i > 1) {
			printf(" ");
		}
		printf("%c%c", c[i].suit, c[i].value);
	}
	printf("\n");

}

void sortingJudge(Card *c) {
	int i, cnt = 0;

	for (i = 0; i < n; i++) {
		if (C1[i].value == c[i].value && C1[i].suit == c[i].suit) {
			cnt++;
		}
	}

	if (cnt == n) {
		printf("Stable\n");
	} else {
		printf("Not stable\n");
	}

}

void swap(Card *x, Card *y) {
	Card tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort() {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = n; j > i + 1; j--) {
			if (C1[j].value < C1[j - 1].value) {
				swap(&C1[j], &C1[j - 1]);
			}
		}
	}

}

void SelectionSort() {
	int i, j, mini;

	for (i = 0; i < n; i++) {
		mini = i;
		for (j = i; j <= n; j++) {
			if (C2[j].value < C2[mini].value) {
				mini = j;
			}
		}
		if (C2[i].value > C2[mini].value) {
			swap(&C2[i], &C2[mini]);
		}
	}

}

int main() {
	int i;
	char ch;

	scanf("%d%c", &n, &ch);
	for (i = 1; i <= n; i++) {
		scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
		C2[i] = C1[i];
	}

	BubbleSort();
	trace(C1);
	sortingJudge(C1);

	SelectionSort();
	trace(C2);
	sortingJudge(C2);

	return 0;
}