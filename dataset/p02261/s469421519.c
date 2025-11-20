#include<stdio.h>
#include<string.h>

struct Card{
	char suit;
	int value;
};

 
void bubbleSort(struct Card A[],int n){
	struct Card t;
	for(int i=0;i<n;i++){
 		for(int j=n-1;j>=i+1;j--){
			if(A[j].value<A[j-1].value){
				 t =A[j]; 
				A[j]=A[j-1];
				A[j-1]=t;
 			}
		}
		
 	}
}

void selectionSort(struct Card A[], int n){
	struct Card t;
	for(int i=0;i<n;i++){
		int minj=i;
 		for(int j=i;j<n;j++){
			if(A[j].value<A[minj].value){
				minj=j;
			}
 		}		
 		 t = A[i];
 		A[i]=A[minj];
 		A[minj]=t;
 	}
}
	
void print(struct Card A[], int n){
	for(int i=0; i<n-1; i++){
		printf("%c%d ",A[i].suit,A[i].value);
	}
	for(int i=n-1; i<n; i++){
		printf("%c%d",A[i].suit,A[i].value);
	}
	printf("\n");
}

int isStable(struct Card C1[], struct Card C2[], int n){
	for(int i=0; i<n; i++){
		if(C1[i].suit!=C2[i].suit){
			return 0;
		}
	}
	return 1;
}
int main(){
	struct Card C1[100],C2[100];
	int n;
	char ch;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf(" %c%d",&C1[i].suit,&C1[i].value);
	}
	for(int i=0;i<n;i++){
		C2[i]=C1[i];
	}
	
	bubbleSort(C1,n);
	selectionSort(C2,n);

	print(C1,n);
	printf("Stable\n");
	
	print(C2,n);
	if(isStable(C1,C2,n)){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
	
	return 0;
}
