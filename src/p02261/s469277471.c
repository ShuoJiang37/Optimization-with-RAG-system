#include<stdio.h>

typedef struct {
	char suit;
	int value;
}Card;

void bubble(Card A[], int N) {
	int i, j;
	Card n;

	for (i = 0; i < N; i++) {
		for (j = N - 1; j >= i + 1; j--) {
			if (A[j].value < A[j - 1].value) {
				n = A[j];
				A[j] = A[j - 1];
				A[j - 1] = n;
			}
		}
	}
}

void selection(Card A[], int N) {
	int i, j, minj;
	Card n;

	for (i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (A[j].value < A[minj].value) {
				minj = j;
			}
		}
		n = A[i];
		A[i] = A[minj];
		A[minj] = n;
	}
}

int isStable(Card C1[], Card C2[], int N) {
	int i;

	for (i = 0; i < N; i++) {
		if (C1[i].suit != C2[i].suit) {
			return 0;
		}
	}
	return 1;
}

void print(Card A[], int N) {
	int i;

	for (i = 0; i < N; i++) {
		if (i > 0)printf(" ");
		printf("%c%d", A[i].suit, A[i].value);

	}

	printf("\n");

}

int main() {
	int n, i;
	Card C1[36], C2[36];
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf(" %c%d", &C1[i].suit, &C1[i].value);

	}

	for (i = 0; i < n; i++) C2[i] = C1[i];

	bubble(C1, n);
	selection(C2, n);

	print(C1, n);
	printf("Stable\n");
	print(C2, n);

	if (isStable(C1, C2, n) == 1) {
		printf("Stable\n");
	}
	else {
		printf("Not stable\n");
	}
	return 0;

}

