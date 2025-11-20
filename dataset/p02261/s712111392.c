#include <stdio.h>
#include <stdio.h>

typedef struct {
	char suit;
	int value;
} card;

void output(card C[], int N);
void swap(card *C1, card *C2);
void bubbleSort(card C[], int N9);
void selectionSort(card C[], int N);
int isStable(card cBubble[],card cSelection[], int N);


int main(void) {
	int N;
	int i;
	
	card cBubble[36], cSelection[36];
	
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf(" %c%d", &cBubble[i].suit, &cBubble[i].value);
		cSelection[i] = cBubble[i];
	}
	
	bubbleSort(cBubble, N);
	printf("Stable\n");

	selectionSort(cSelection, N);
	if (isStable(cBubble, cSelection, N)) {
		printf("Stable\n");
	}else {
		printf("Not stable\n");
	}
	
	return 0;
}


void output(card C[], int N) {
	int i;
	for (i = 0; i < N; i++) {
		if (i > 0) printf(" ");
		printf("%c%d",C[i].suit, C[i].value);
	}
	printf("\n");
}


void swap(card *C1, card *C2) {
	card tmp = *C1;
	*C1 = *C2;
	*C2 = tmp;
}

void bubbleSort(card C[], int N) {
	int i, j;
	
	for (i = 0; i < N - 1; i++) {
		for (j = N - 1;j >= i + 1 ; j--) {
			if (C[j - 1].value > C[j].value) {
				swap(&C[j - 1], &C[j]);
			}
		}
	}
	output(C, N);

}

void selectionSort(card C[], int N) {
	int i, j, minj;

	for (i = 0; i < N - 1; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (C[j].value < C[minj].value) {
				minj = j;
			}
		}
		swap(&C[i], &C[minj]);
	}
	output(C, N);
}


int isStable(card cBubble[],card cSelection[], int N) {
	int i;
	
	for (i = 0; i < N; i++) {
		if (cBubble[i].suit != cSelection[i].suit) {
			return 0;
		}
	}

	return 1;
}