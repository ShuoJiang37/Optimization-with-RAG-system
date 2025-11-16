#include<stdio.h>

typedef struct Card{
	char suit;
	char value;
} Card;

void bubbleSort(int n, Card* C){
	int i, j;
	Card tmp;

	for(i = 0; i < n ; i++){
		for(j = n-1; j > i; j--){
			if(C[j].value < C[j-1].value){
				tmp = C[j];
				C[j] = C[j-1];
				C[j-1] = tmp;
			}
		}
	}
}
void selectionSort(int n, Card* C){
	int i, j, min;
	Card tmp;

	for(i = 0; i < n; i++){
		min = i;
		for(j = i; j < n; j++){
			if(C[j].value < C[min].value)
				min = j;
		}
		if(min != i){
			tmp = C[i];
			C[i] = C[min];
			C[min] = tmp;
		}
	}

}

void print(int n, Card* C){
	int i;
	for(i = 0; i < n; i++){
		printf("%c%c", C[i].suit, C[i].value);
		(i != n-1) ? printf(" ") : printf("\n");
	}

}
//stable check
int check(int n, Card* C1, Card* C2){
	int i;
	for(i = 0; i < n; i++)
		if(C1[i].suit != C2[i].suit)
			return 0;

	return 1;
}

void copy(int n, Card* C1, Card* C2){
	int i;

	for(i = 0; i < n; i++){
		C2[i].suit = C1[i].suit;
		C2[i].value = C1[i].value;
	}
	

}

int main(){
	Card C1[101], C2[101];
	int n, i;
	char ch;

	scanf("%d%c", &n, &ch);
	for(i = 0; i < n; i++)
		scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);

	copy(n, C1, C2);
	bubbleSort(n, C1);
	print(n, C1);
	printf("Stable\n");
	selectionSort(n, C2);
	print(n, C2);
	(check(n, C1, C2)) ? printf("Stable\n") : printf("Not stable\n");


	return 0;
}