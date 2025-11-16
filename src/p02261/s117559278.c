#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <stdlib.h>


typedef struct tag_card {
	char suit_;
	int num_;
}card_t;

void displayArray(card_t *c, int n);

void swap(card_t *x, card_t *y);

void selectionSort(card_t *C, int n);

void bubbleSort(card_t *C, int n);

int isStable(card_t cBubble[], card_t cSelection[], int n);

int main(void) {
	int n, i;
	scanf("%d%*c", &n);

	card_t C1[36] = {};
	card_t C2[36] = {};

	for (i = 0; i < n; i++) {
		scanf("%c%d%*c", &C1[i].suit_, &C1[i].num_);
		C2[i] = C1[i];
	}

	bubbleSort(C1, n);
	selectionSort(C2, n);

	displayArray(C1, n);
	printf("Stable\n");
	displayArray(C2, n);
	if (isStable(C1, C2, n))
		printf("Stable\n");
	else
		printf("Not stable\n");

	return 0;
}

void displayArray(card_t *c, int n) {
	int i = 0;

	for (i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%c%d", c[i].suit_, c[i].num_);
	}
	printf("\n");
}

void swap(card_t *x, card_t *y) {
	card_t tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void selectionSort(card_t *C, int n) {
	int i = 0;
	int j = 0;
	int minj = 0;

	card_t tmp;
	
	for (i = 0; i < n; i++) {
		minj = i;
		
		for (j = i; j < n; j++) {
			if (C[j].num_ < C[minj].num_)
				minj = j;
		}

		swap(&C[i], &C[minj]);
	}
}

void bubbleSort(card_t *C, int n) {
	int i = 0;
	int j = 0;

	for (i = 0; i < n; i++) {
		for (j = n - 1; j > i; j--) {
			if (C[j].num_ < C[j - 1].num_)
				swap(&C[j], &C[j - 1]);
		}
	}

}

int isStable(card_t cBubble[], card_t cSelection[], int n) {
	int i = 0;

	for (i = 0; i < n; i++) {
		if (cBubble[i].suit_ != cSelection[i].suit_)
			return FALSE;
	}

	return TRUE;
}