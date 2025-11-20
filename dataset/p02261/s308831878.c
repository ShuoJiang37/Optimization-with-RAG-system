#include<stdio.h>

struct Card{
	char suit;
	char value;
};

typedef struct Card Card;

void swap(Card *a, Card *b){
	Card t;
	t = *b;
	*b = *a;
	*a = t;
}

void BubbleSort(Card *C, int n){
	int i, j;
	for (i = 0; i <= n - 1; i++){
		for (j = n - 1; j >= i + 1; j--){
			if (C[j].value < C[j - 1].value){
				swap(&C[j], &C[j - 1]);
			}
		}
	}
}

void SelectionSort(Card *C, int n){
	int i, j, mini;
	for (i = 0; i<n - 1; i++){
		mini = i;
		for (j = i; j <= n - 1; j++){
			if (C[j].value < C[mini].value){
				mini = j;
			}
		}
		swap(&C[i], &C[mini]);
	}
}

int check(Card *C1, Card *C2, int n){
	int i, j, k;
	for (i = 0; i < n; i++){
		if (C2[i].suit != C1[i].suit){ return 0; }
	}
	return 1;
}

int main(){
	struct Card C1[101], C2[101];
	int n, i;
	char ch;

	scanf("%d%c", &n, &ch);
	for (i = 0; i < n; i++){
		scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
	}

	for (i = 0; i < n; i++){
		C2[i] = C1[i];
	}
	BubbleSort(C2, n);
	for (i = 0; i < n; i++){
		printf("%c%c", C2[i].suit, C2[i].value);
		if (i < n - 1){ printf(" "); }
	}
	printf("\n");
	printf("Stable\n");


	SelectionSort(C1, n);
	for (i = 0; i < n; i++){
		printf("%c%c", C1[i].suit, C1[i].value);
		if (i < n - 1){ printf(" "); }
	}
	printf("\n");
	printf("%s", check(C1, C2, n) ? "Stable\n" : "Not stable\n");
	return 0;
}