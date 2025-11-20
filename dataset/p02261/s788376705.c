#include<stdio.h>

typedef struct {
	char suit;
	int num;
}card;

void swap (int *x, int *y,char *a, char *b) {
	int temps;
	char tempn;  
 	temps = *x;
	*x = *y;
	*y = temps;
	tempn = *a;
	*a = *b;
	*b = tempn;
}

int bubble_sort (card A[], int n) {
	int i,j = 0;
	for (i = 0; i < n - 1; i++){
    	for (j = n - 1; j >= i + 1; j--){ 
			if (A[j].num < A[j-1].num){
				swap(&A[j].num, &A[j-1].num, &A[j].suit, &A[j-1].suit);
      		}
    	}
	}
}

int selectionSort(card A[], int n){
	int i,j,minj;
	for(i = 0; i < n; i++){
		minj = i;
		for(j = i; j < n; j++){
			if(A[j].num < A[minj].num){
				minj = j;
			}
		}
		swap(&A[i].num, &A[minj].num, &A[i].suit, &A[minj].suit);
	}
}

int main(void){
	int n,i,f2 = 0;
	scanf("%d" ,&n);
	card A[n],B[n];
	for(i = 0; i < n; i++){
		scanf(" %c%d",&A[i].suit,&A[i].num);
		B[i] = A[i];
	}
	bubble_sort (A, n);
	for(i = 0; i < n; i++){
		if(i < n - 1){
			printf("%c%d ",A[i].suit,A[i].num);
		}
		else{
			printf("%c%d\n",A[i].suit,A[i].num);
		}
	}
	printf("Stable\n");
	selectionSort(B, n);
	for(i = 0; i < n; i++){
		if(i < n - 1){
			printf("%c%d ",B[i].suit,B[i].num);
		}
		else{
			printf("%c%d\n",B[i].suit,B[i].num);
		}
	}
	for(i = 0; i < n; i++){
		if(B[i].num == A[i].num && B[i].suit != A[i].suit){
			printf("Not stable\n");
			return 0;
		}
	}
	printf("Stable\n");
	return 0;
}
