#include <stdio.h>

struct Card{char suit;int value;};

void bubble(struct Card  A[],int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=N-1;j>=i+1;j--){
			if(A[j].value < A[j-1].value){
				int t=A[j].value;
				A[j].value=A[j-1].value;
				A[j-1].value=t;
				
				char s=A[j].suit;
				A[j].suit=A[j-1].suit;
				A[j-1].suit=s;
			}
		}
	}
}

void selection(struct Card  A[],int N){
	int i,j,minj;
	for(i=0;i<N;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(A[j].value < A[minj].value){
				minj=j;
			}
		}
		int t = A[i].value;
		A[i].value=A[minj].value;
		A[minj].value=t;
		
		char s=A[i].suit;
		A[i].suit=A[minj].suit;
		A[minj].suit=s;
	}
}

int main(void){
	int N,i;
	struct Card C1[36],C2[36]; 
	
	scanf("%d ",&N);
	for(i=0;i<N;i++){
		scanf(" %c%d",&C1[i].suit,&C1[i].value);
	}
	
	for(i=0;i<N;i++){
		C2[i]=C1[i];
	}
	
	bubble(C1,N);
	selection(C2,N);
	
	for(i=0;i<N;i++){
		if(i>0){
			printf(" ");
		}
		printf("%c%d",C1[i].suit,C1[i].value);
		
	}
	
	printf("\n");
	
	printf("Stable\n");
	
	for(i=0;i<N;i++){
		if(i>0){
			printf(" ");
		}
		printf("%c%d",C2[i].suit,C2[i].value);
	}
	
	printf("\n");
	
	for(i=0;i<N;i++){
		if(C1[i].suit!=C2[i].suit){
			printf("Not stable\n");
			break;
		}
		if(i==N-1){
			printf("Stable\n");
		}
	}
	
	return 0;
}
