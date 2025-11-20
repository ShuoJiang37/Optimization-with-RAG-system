#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char type;
	int num;
} CARD;

char before[9][4];
char after[9][4];

void swap(CARD *a, CARD *b)
{
	char tmp_c = a->type;
	int tmp_i = a->num;
	a->type = b->type;
	a->num = b->num;
	b->type = tmp_c;
	b->num = tmp_i;
}

int bubble_sort(CARD *A, int N)
{
	int i, j, cnt = 0;
	for (i = 0; i < N; i++) {
		for (j = N - 1; j >= i + 1; j--) {
			if (A[j].num < A[j - 1].num) {
				swap(&A[j], &A[j - 1]);
				cnt++;
			}
		}
	}
	return cnt;
}

int selection_sort(CARD *A, int N)
{
	int i, j, minj;
	int cnt = 0;
	for (i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (A[j].num < A[minj].num) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(&A[i], &A[minj]);
			cnt++;
		}
	}
	return  cnt;
}

void print(CARD *card, int num)
{
	int i, j, isStable = 1;

	memset(after, '\0', sizeof(after));

	for (i = 0; i < num; i++) {
		for (j = 0; j < 4; j++) {
			if (after[card[i].num - 1][j] == '\0') {
				after[card[i].num - 1][j] = card[i].type;
				break;
			}
		}
	}

	for (i = 0; i < num; i++) {
		int card_num = card[i].num;

		if (i == num - 1) {
			printf("%c%d\n", card[i].type, card_num);
		}
		else {
			printf("%c%d ", card[i].type, card_num);
		}

		if (isStable) {
			for (j = 0; before[card_num - 1][j] != '\0' && j < 4; j++) {
				if (before[card_num - 1][j] != after[card_num - 1][j]) {
					isStable = 0;
					break;
				}
			}
		}
	}
	if (isStable) {
		printf("Stable\n");
	}
	else {
		printf("Not stable\n");
	}
}

int main(int argc, char** argv)
{
	int i, j, num;
	CARD card1[36], card2[36];

	memset(before, '\0', sizeof(before));

	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		char str[4];
		memset(str, '\0', sizeof(str));
		scanf("%s", str);
		card1[i].type = str[0];
		card1[i].num = atoi(&str[1]);

		for (j = 0; j < 4; j++) {
			if (before[card1[i].num - 1][j] == '\0') {
				before[card1[i].num - 1][j] = card1[i].type;
				break;
			}
		}
	}

	memcpy(card2, card1, sizeof(card2));

	bubble_sort(card1, num);
	print(card1, num);

	selection_sort(card2, num);
	print(card2, num);

	return 0;
}