#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct _card {
	char mark;
	int value;
} card ;

void isstable(card *targetc, card *c, int N) {
	int sw = TRUE;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int a = 0; a < N; a++) {
				for (int b = a + 1; b < N; b++) {
					if (c[i].value == c[j].value && c[i].value == targetc[a].value && c[i].value == targetc[b].value
						&& c[i].mark == targetc[b].mark && c[j].mark == targetc[a].mark) {
						sw = FALSE;
					}
				}
			}
		}
	}
	if (sw) {
		printf("\nStable\n");
	}
	else {
		printf("\nNot stable\n");
	}
}

void babblesort(card *c, int N) {
	card babblec[36];
	for (int i = 0; i < N; i++) {
		babblec[i] = c[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j > i; j--) {
			if (babblec[j].value < babblec[j-1].value) {
				card tmp = babblec[j];
				babblec[j] = babblec[j-1];
				babblec[j - 1] = tmp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (i) {
			printf(" ");
		}
		printf("%c%d", babblec[i].mark, babblec[i].value);
	}
	isstable(babblec, c, N);
}

void selectsort(card *c, int N) {
	card selectc[36];
	for (int i = 0; i < N; i++) {
		selectc[i] = c[i];
	}
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i + 1; j < N; j++) {
			if (selectc[minj].value > selectc[j].value) {
				minj = j;
			}
		}
		card tmp = selectc[i];
		selectc[i] = selectc[minj];
		selectc[minj] = tmp;
	}
	for (int i = 0; i < N; i++) {
		if (i) {
			printf(" ");
		}
		printf("%c%d", selectc[i].mark, selectc[i].value);
	}
	isstable(selectc, c, N);
}

int main(void) {
	int N;
	card c[36];
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		if (i) {
			scanf(" ");
		}
		scanf("%c%d", &(c[i].mark), &(c[i].value));
	}
	babblesort(c, N);
	selectsort(c, N);
	return 0;
}
