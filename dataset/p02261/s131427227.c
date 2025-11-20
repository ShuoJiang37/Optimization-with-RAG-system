#include <stdio.h>

struct Card {
	char suit, value;
};

void bubbleSort(struct Card C[],int N);
void selectionSort(struct Card C[],int N);
int isStable(struct Card C1[], struct Card C2[], int N);



int main(void)
{
	int i,n;
	scanf("%d", &n);
	struct Card a1[n],a2[n];
	
	for(i=0; i<n; i++){
		scanf(" %c %c", &a1[i].suit,&a1[i].value);
	}
	
	for(i = 0; i<n; i++){
		a2[i]=a1[i];
	}
	
	bubbleSort(a1,n);
	selectionSort(a2,n);
	
	for(i=0; i<n; i++){
		if(i < n-1){
			printf("%c%c ",a1[i].suit,a1[i].value);
		}
		else{
			printf("%c%c\n",a1[i].suit,a1[i].value);
		}
	}
	printf("Stable\n");
	
	for(i=0; i<n; i++){
		if(i < n-1){
			printf("%c%c ",a2[i].suit,a2[i].value);
		}
		else{
			printf("%c%c\n",a2[i].suit,a2[i].value);
		}
	}
	
	if(isStable(a1,a2,n) == 1){
		printf("Not stable\n");
	}
	else{
		printf("Stable\n");
	}
	return 0;
}

void bubbleSort(struct Card C[],int N)
{
	int i,j;
	struct Card tmp;
	for(i=0; i<=N-1; i++){
		for(j=N-1; j>=1; j--){
			if(C[j].value < C[j-1].value){
				tmp=C[j];
				C[j]=C[j-1];
				C[j-1]=tmp;
			}
		}
	}
}


void selectionSort(struct Card C[],int N)
{
	int i,j,minj;
	struct Card tmp;
	for(i=0; i<=N-1; i++){
		minj=i;
		for(j=i; j<=N-1; j++){
			if(C[j].value < C[minj].value){
				minj=j;
			}
		}
		tmp=C[i];
		C[i]=C[minj];
		C[minj]=tmp;
	}
}

int isStable(struct Card C1[], struct Card C2[], int N)
{
	int i;
	for(i=0; i<N; i++){
		if(C1[i].suit != C2[i].suit){
			return 1;
		}
	}
	return 0;
}

