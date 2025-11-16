#include<stdio.h>
struct Card {
	char suit;
	int value;
};

void swap(struct Card C[], int a, int b)
{
	struct Card tmp;
	tmp = C[a];
	C[a] = C[b];
	C[b] = tmp;

	return;
}

void bubbleSort(struct Card C[], int N)
{
	int i, j;
	for(i = 0; i < N; ++i) {
		for(j = N - 1; j > i; --j) {
			if(C[j].value < C[j-1].value)
				swap(C, j, j-1);
		}
	}
	return;
}

void selectionSort(struct Card C[], int N)
{
	int i, j;
	for(i = 0; i < N; ++i) {
		int minj = i;
		for(j = i; j < N; ++j) {
			if(C[j].value < C[minj].value)
				minj = j;
		}
		swap(C, i, minj);
	}
}

void showResult(struct Card C[], int N)
{
	int i;
	for(i = 0; i < N; ++i) {
		if(i == N-1)
			printf("%c%d\n", C[i].suit, C[i].value);
		else
			printf("%c%d ", C[i].suit, C[i].value);
	}
}

int isStable(struct Card C1[], struct Card C2[], int N)
{
	int i;
	for(i = 0; i < N; ++i) {
		if(C1[i].suit != C2[i].suit)
			return 0;
	}

	return 1;
}

int main()
{
	int i;
	int N;
	scanf("%d\n", &N);

	struct Card C1[N], C2[N];
	for(i = 0; i < N; ++i) {
		scanf(" %c%d", &C1[i].suit, &C1[i].value);
		C2[i].suit = C1[i].suit;
		C2[i].value = C1[i].value;
	}
	bubbleSort(C1, N);
	showResult(C1, N);
	if(isStable(C1, C1, N))
		printf("%s\n", "Stable");
	else
		printf("%s\n", "Not stable");
	selectionSort(C2, N);
	showResult(C2, N);
	if(isStable(C1, C2, N))
		printf("%s\n", "Stable");
	else
		printf("%s\n", "Not stable");
    return 0;
}