#include <stdio.h>
typedef struct {
	char mark;
	int num;
} Card;

void BubbleSort(Card C[], int N) {
	int i, j;
	Card tmp;
	for (i = 0; i < N; ++i) {
		for (j = N - 1; j >= i +1 ; --j) {
			if (C[j].num < C[j-1].num) {
				tmp = C[j];
				C[j] = C[j-1];
				C[j - 1] = tmp;
			}
		}
	}
	return;
}

int isStable(Card C1[], Card C2[], int N) {
	int i;
	for (i = 0; i < N; ++i) {
		if (C1[i].mark != C2[i].mark) return 0;
	}
	return 1;
}

void showQue(Card A[], int N)
{
	int i;
	for (i = 0; i < N; ++i) {
		if (i != N - 1) {
			printf("%c%d ", A[i].mark, A[i].num);
		} else {
			printf("%c%d\n", A[i].mark, A[i].num);
		}
	}
	
	return;
}


void SelectionSort(Card C[], int N) {
	int i, j, minj;
	Card tmp;

	for (i = 0; i < N; ++i) {
		minj = i;
		for (j = i; j < N; ++j) {
			if (C[j].num < C[minj].num) {
				minj = j;
			}
		}	
		tmp = C[i];
		C[i] = C[minj];
		C[minj] = tmp;
	}
	return;
}


int main(void) {
	Card C1[100] = {0};
	Card C2[100] = {0};
	int N, i;
	
	scanf("%d", &N);

	for (i = 0; i < N; ++i) {
		scanf(" %c%d", &C1[i].mark, &C1[i].num);
		C2[i] = C1[i];
	}
	BubbleSort(C1, N);
	SelectionSort(C2, N);

	showQue(C1, N);
	printf("Stable\n");
	showQue(C2, N);
	if (isStable(C1, C2, N)) {
		printf("Stable\n");
	} else {
		printf("Not stable\n");
	}
	return 0;
}