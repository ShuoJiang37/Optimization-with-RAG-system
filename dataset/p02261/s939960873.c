#include <stdio.h>
#include <string.h>

#define N 36

void BubbleSort(char card[N][3], int n) {
	int i, j;
	char tmp[3];
	for (i = 0; i < n; i++) {
		for (j = n - 1; j >= i + 1; j--) {
			if (card[j][1] < card[j - 1][1]) {
				strcpy(tmp, card[j]);
				strcpy(card[j], card[j - 1]);
				strcpy(card[j - 1], tmp);
			}
		}
	}
}

void SelectionSort(char card[N][3], int n) {
	int i, j, minj;
	char tmp[3];
	for (i = 0; i < n; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (card[j][1] < card[minj][1]) {
				minj = j;
			}
		}
		strcpy(tmp, card[i]);
		strcpy(card[i], card[minj]);
		strcpy(card[minj], tmp);
	}
}

int judge(char card[N][3], char rule[N][3], int n) {
	int i, j;
	int a, b;
	int flag = 1;
	for (i = 0; i < n - 1; i++) {
		if (card[i][1] == card[i + 1][1]) {
			for (j = 0; j < n; j++) {
				if (rule[j][1] == card[i][1]) {
					if (rule[j][0] == card[i][0]) {
						a = j;
					}
					else if (rule[j][0] == card[i + 1][0]) {
						b = j;
					}
				}
			}
			if (a > b) {
				flag = 0;
				break;
			}
		}
	}
	if (flag) {
		printf("Stable\n");
	}
	else {
		printf("Not stable\n");
	}
}

int main() {
	int n;
	int i;
	char card[N][3];
	char Bcard[N][3];
	char Scard[N][3];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", card[i]);
		strcpy(Bcard[i], card[i]);
		strcpy(Scard[i], card[i]);
	}

	BubbleSort(Bcard, n);
	SelectionSort(Scard, n);

	for (i = 0; i < n - 1; i++) {
		printf("%s ", Bcard[i]);
	}
	printf("%s\n", Bcard[n - 1]);
	judge(Bcard, card, n);
	for (i = 0; i < n - 1; i++) {
		printf("%s ", Scard[i]);
	}
	printf("%s\n", Scard[n - 1]);
	judge(Scard, card, n);

	return 0;
}
