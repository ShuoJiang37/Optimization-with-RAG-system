#include<stdio.h>

typedef struct {char suit, value;}Card;

void bubble(Card A[], int N){
	int i, j;
	Card t;
	for(i = 0; i < N; i++){
		for(j = N - 1; j >= i; j--){
			if(A[j].value < A[j - 1].value){
				t = A[j]; A[j] = A[j - 1]; A[j - 1] = t;
			}
		}
	}
}

void selection(Card A[], int N){
	int i, j, minj;
	Card t;
	for(i = 0; i < N; i++){
		minj = i;
		for(j = i; j < N; j++){
			if(A[j].value < A[minj].value)minj = j;
		}
		t = A[i]; A[i] = A[minj]; A[minj] = t;
	}
}

void print(Card A[], int N){
	int i;
	for(i = 0; i < N; i++){
		if(i > 0)printf(" ");
		printf("%c%d", A[i].suit, A[i].value);
	}
	printf("\n");
}

int isStable(Card C1[], Card C2[], int N){
	int i;
	for(i = 0; i< N; i++){
		if(C1[i].suit != C2[i].suit)return 0;
	}
	return 1;
}

void str2Card(Card *t, char str[]){
	t -> suit = str[0];
	t -> value = str[1] - '0';
}

int main(void){
	Card C1[100],C2[100];
	int N, i;
	char str[3];
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%s", str);
		str2Card(&C1[i], str);
	}
	
	for(i = 0; i < N; i++)C2[i]= C1[i];
	
	bubble(C1, N);
	selection(C2,N);
	
	print(C1, N);
	printf("Stable\n");
	print(C2, N);
	if(isStable(C1, C2, N)){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
	
	return 0;
}
