#include <stdio.h>
#include <string.h>

void BubbleSort(char A[],int B[], int N){
	int flag = 1;
	char change1;
	int change2;
	int count = 0;
	while(flag){
		flag = 0;
		
		for(int j = N-1;j > 0;j--){
			if(B[j] < B[j-1]){
				change1 = A[j];
				change2 = B[j];
				A[j] = A[j-1];
				B[j] = B[j-1];
				A[j-1] = change1;
				B[j-1] = change2;
				flag = 1;
			}
		}
	}
	for(int i = 0;i < N;i++){
	printf("%c%d",A[i],B[i]);
		if(i != N-1)printf(" ");
	}
	printf("\n");
	printf("Stable\n");
}


void selectionSort(char A[],int B[], int N){
	int count = 0;
	int min;
	char change1;
	int change2;
	for(int i = 0;i <N-1;i++){
		min = i;
		for(int j = i;j < N;j++){
			if(B[j] < B[min]){
			min = j;
			}
		}
			change1 = A[i];
			change2 = B[i];
			A[i] = A[min];
			B[i] = B[min];
			A[min] = change1;
			B[min] = change2;
			
			
		
	}
	for(int i = 0;i < N;i++){
	printf("%c%d",A[i],B[i]);
		if(i != N-1)printf(" ");
	}
	printf("\n");
}


int main(void){
	int n;
	scanf("%d",&n);
	char card1[n];
	char card2[n];
	int card1int[n];
	int card2int[n];
	for(int i = 0;i < n;i++)
	{
		scanf(" %c %d",&card1[i],&card1int[i]);
		card2int[i] = card1int[i];
	}
	
	strcpy(card2,card1);
	
	BubbleSort(card1, card1int, n);
	selectionSort(card2, card2int, n);
	
	if(strcmp(card1,card2)==0){printf("Stable\n");}
	else{printf("Not stable\n");}
	
}
