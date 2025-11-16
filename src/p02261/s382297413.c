#include <stdio.h>
#include <stdbool.h>

typedef struct {
	char mark;
	int value;
} card;

card C[40], D[40];

void swap(card *a, card *b) {
	card tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(card *C, int N) {
	for (int i = 0; i < N; ++i) {
		for (int j = N-1; j > i; --j) {
			if (C[j].value < C[j-1].value) swap(&C[j], &C[j-1]);
		}
	}
}

void selectionSort(card *C, int N) {
	for (int i = 0; i < N; ++i) {
		int minj = i;
		for (int j = i; j < N; ++j) {
			if (C[j].value < C[minj].value) minj = j;
		}
		swap(&C[i], &C[minj]);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	char s[N][3];
	for (int i = 0; i < N; ++i) {
		scanf("%s", s[i]);
		C[i].mark = s[i][0];
		C[i].value = s[i][1] - '0';
		D[i] = C[i];
	}
	bubbleSort(C, N);
	for (int i = 0; i < N; ++i) {
		if (i != N-1) printf("%c%d ", C[i].mark, C[i].value);
		else printf("%c%d\n", C[i].mark, C[i].value);
	}
	printf("Stable\n");

	selectionSort(D, N);
	bool flag = true;
	for (int i = 0; i < N; ++i) {
		if (C[i].mark != D[i].mark) flag = false;
		if (i != N-1) printf("%c%d ", D[i].mark, D[i].value);
		else printf("%c%d\n", D[i].mark, D[i].value);
	}
	if (flag) printf("Stable\n");
	else printf("Not stable\n");
}

