#include <stdio.h>
#include <string.h>

#define Max 1000

struct card {
	char mark;
	int value;
}; typedef struct card card;

void  swap(card *x, card *y)
{
    card  buff;
	
	buff = *x;
	*x = *y;  
	*y = buff;
}

void printA(card A[Max], int N) {
	int i;

	for (i = 0; i < N - 1; i++)
		printf("%c%d ", A[i].mark, A[i].value);
	printf("%c%d\n", A[i].mark, A[i].value);
}

void bubbleSort(card A[Max], int N) {
	int j;
	int flag = 1;

	while (flag) {
		flag = 0;
		for (j = N - 1; j > 0; j--) {
			if (A[j].value < A[j - 1].value) {
				swap(&A[j], &A[j - 1]);
				flag = 1;
			}
		}
	}
}

void selectionSort(card A[Max], int N) {
	int i, j, minj;

	for (i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (A[j].value < A[minj].value)
				minj = j;
		}
		if (i != minj) {
			swap(&A[i], &A[minj]);
		}
	}
}

int main( ) {
	int N, i;
	int true = 1;
	card A[Max];
	card B[Max];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf(" %c%d", &A[i].mark, &A[i].value);
		B[i] = A[i];
	}

	bubbleSort(A, N);

	printA(A, N);

	printf("Stable\n");

	selectionSort(B, N);

	printA(B, N);

	for (i = 0; i < N; i++)
		if (A[i].mark != B[i].mark) true = 0;

	if (true)	printf("Stable\n");
	else		printf("Not stable\n");

	return 0;
}