#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NUM 9
#define MAX_SIZE MAX_NUM * 4

typedef struct _Card {
	uint8_t suit;
	uint8_t number;
} Card;
#define MAX_CARDS_SIZE MAX_SIZE * sizeof(Card)

typedef struct _Checker {
	uint8_t suits[5];
	uint8_t count;
} Checker;

void DispCards(Card arr[], int32_t len) {
	printf("%c%c", arr[0].suit, arr[0].number);
	for (int32_t i = 1; i < len; i++) {
		printf(" %c%c", arr[i].suit, arr[i].number);
	}
	putchar('\n');
}

void DispStable(Card arr1[], Card arr2[], int32_t len, int32_t cardNumCnt[]) {
	for (int32_t i = 1; i <= MAX_NUM; i++) {
		if (cardNumCnt[i] < 2) continue;

		Checker chk1 = {0};
		Checker chk2 = {0};
		for (int32_t j = 0; j < len; j++) {
			if (arr1[j].number == i + 0x30) chk1.suits[chk1.count++] = arr1[j].suit;
			if (arr2[j].number == i + 0x30) chk2.suits[chk2.count++] = arr2[j].suit;
		}
		if (memcmp(chk1.suits, chk2.suits, 4)) {
			puts("Not stable");
			return;
		}
	}
	puts("Stable");
}

void Swap(Card *a, Card *b) {
	Card tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(Card arr[], int32_t len) {
	bool needLoop = true;
	for (int32_t i = 0; needLoop; i++) {
		needLoop = false;
		for (int32_t j = len-1; j > i; j--) {
			if (arr[j-1].number > arr[j].number) {
				Swap(&arr[j-1], &arr[j]);
				needLoop = true;
			}
		}
	}
}

void SelectionSort(Card arr[], int32_t len) {
	int32_t last = len - 1;
	for (int32_t i = 0; i < last; i++) {
		int32_t minPos = i;
		for (int32_t j = i+1; j < len; j++) {
			minPos = (arr[minPos].number > arr[j].number) ? j : minPos;
		}
		if (minPos != i) {
			Swap(&arr[i], &arr[minPos]);
		}
	}
}

int main() {
	int32_t dataNum;
	scanf("%d", &dataNum);
	getchar();

	Card cards[MAX_SIZE] = {0};
	int32_t cardNumCnt[MAX_NUM+1] = {0};
	for (int32_t i = 0; i < dataNum; i++) {
		uint8_t buf[3] = {0};
		scanf("%2s", buf);
		cards[i].suit = buf[0];
		cards[i].number = buf[1];
		cardNumCnt[buf[1] - 0x30]++;
	}

	Card tmp[MAX_SIZE];
	memcpy(tmp, &cards, MAX_CARDS_SIZE);

	BubbleSort(tmp, dataNum);
	DispCards(tmp, dataNum);
	DispStable(cards, tmp, dataNum, cardNumCnt);

	memcpy(tmp, &cards, MAX_CARDS_SIZE);

	SelectionSort(tmp, dataNum);
	DispCards(tmp, dataNum);
	DispStable(cards, tmp, dataNum, cardNumCnt);

	return 0;
}

