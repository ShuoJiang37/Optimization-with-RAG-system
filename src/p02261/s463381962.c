#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char value[3];
	int key;
} card;

void bubbleSort(card *, int);
void selectionSort(card *, int);
void swap(char *, char *);
int isStable(card *, int);

int main() {
	int n, i;
	scanf("%d", &n);
	card *a = (card *)malloc(n * sizeof(card));
	card *b = (card *)malloc(n * sizeof(card));

	for (i = 0; i < n; i++) {
		scanf("%s", a[i].value);
		strcpy(b[i].value, a[i].value);
		a[i].key = i;
		b[i].key = i;
	}
	bubbleSort(a, n);
	for (i = 0; i < n - 1; i++) printf("%s ", a[i].value);
	printf("%s\n", a[i].value);
	(isStable(a, n)) ? printf("Stable\n") : printf("Not stable\n");

	selectionSort(b, n);
	for (i = 0; i < n - 1; i++) printf("%s ", b[i].value);
	printf("%s\n", b[i].value);
	(isStable(b, n)) ? printf("Stable\n") : printf("Not stable\n");

}

void bubbleSort(card *a, int max) {
	int i, j;
	for (i = 0; i < max; i++) {
		for (j = max - 1; j > i; j--) {
			if (a[j].value[1] < a[j - 1].value[1]) {
				swap(a[j].value, a[j - 1].value);
			}
		}
	}
}

void selectionSort(card *a, int max) {
	int needSwap = 0, minIx = 0;
	int i, j;
	for (i = 0; i < max; i++) {
		minIx = i;
		for (j = i; j < max; j++) {
			if (a[j].value[1] < a[minIx].value[1]) {
				minIx = j;
				needSwap = 1;
			}
		}
		if (needSwap) {
			swap(a[i].value, a[minIx].value);
			needSwap = 0;
		}
	}
}

void swap(char *p1st, char *p2nd) {
	for (int curByte = 0; curByte < sizeof(card); curByte++) {
		char byteCopy = p1st[curByte];
		p1st[curByte] = p2nd[curByte];
		p2nd[curByte] = byteCopy;
	}
}

int isStable(card *check, int max) {
	int i;
	for (i = 1; i < max; i++) {
		if (check[i-1].value[1] == check[i].value[1] && check[i - 1].key > check[i].key) return 0;
	}
	return 1;
}
