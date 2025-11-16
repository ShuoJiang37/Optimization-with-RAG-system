/* ALDS1_3_C: Stable Sort */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 36

typedef struct {
	char suit;
	int value;
} Card;

void bubbleSort(Card *A, int n);
void selectionSort(Card *A, int n);
void swap(Card *A, int x, int y);
void isStable(Card *A, Card* B, int n);
void print(Card *A, int n);

int main(void){
	int n, i = 0;
	Card c1[N], c2[N];

	scanf("%d", &n);
	getchar();
	while(i < n){

		scanf("%c%d", &(c1[i].suit), &(c1[i].value));
		getchar();
		/*c1[i].suit = getchar();
		c1[i].value = getchar();*/
		c2[i] = c1[i];
		i++;
	}

	bubbleSort(c1, n);
	print(c1, n);
	printf("Stable\n");
	selectionSort(c2, n);
	print(c2, n);
	isStable(c1, c2, n);

	return 0;
}

void bubbleSort(Card *A, int n){
	int sw = 0, i, j;

	for(i = 0; i < n-1; i++){
		for(j = n-1; j > i; j--){
			if(A[j].value < A[j - 1].value) swap(A, j, j-1);
		}
	}
}


void selectionSort(Card *A, int n){
	int min_id, i, j, sw = 0;

	for(i = 0; i < n - 1; i++){
		min_id = i;
		for(j = i+1; j < n; j++){
			if(A[j].value < A[min_id].value){
				min_id = j;
			}
		}

		if(min_id != i) 	swap(A, i, min_id);
	}

}

void swap(Card *A, int x, int y){
	Card temp = A[x];
	A[x] =  A[y];
	A[y] = temp;
}

void isStable(Card *A, Card* B, int n){
	int i = 0;
	while(i < n){
		if(A[i].suit != B[i].suit){
			printf("Not stable\n");
			return;
		}
		i++;
	}

	printf("Stable\n");
}

void print(Card *A, int n){
	int i = 0;
	while(i < n){
		if(i > 0)  printf(" ");
		printf("%c%d", A[i].suit, A[i].value);
		i++;
	}
	putchar('\n');
}
