#include <stdio.h>
#include <string.h>

typedef struct{
	int num;
	char suit;
	int id;
}Card;

void BubbleSort(Card card[], int n){
	int i, j;
	Card tmp;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(card[j].num<card[j-1].num){
				tmp=card[j];
				card[j]=card[j-1];
				card[j-1]=tmp;
			}
		}
	}
	for(i=0; i<n; i++){
		if(i<n-1){
			printf("%c%d ", card[i].suit, card[i].num);
		}else{
			printf("%c%d", card[i].suit, card[i].num);
		}
	}
	printf("\nStable\n");
}

void SelectionSort(Card card[], int n){
	int i, j, minj;//, sta=0;
	Card tmp;

	for(i=0; i<n-1; i++){
		minj=i;
		for(j=i; j<n; j++){
			if(card[j].num<card[minj].num){
				minj=j;
			}
		}
		tmp=card[minj];
		card[minj]=card[i];
		card[i]=tmp;
	}
	for(i=0; i<n; i++){
		if(i<n-1){
			printf("%c%d ",card[i].suit,card[i].num);
		}else{
			printf("%c%d",card[i].suit,card[i].num);
		}
	}
}

void isStable(const Card *bd,const Card *c, int n){
	int i, stai=0;
	for(i=0; i<n; i++){
		if(bd[i].suit!=c[i].suit){
			stai=1;
		}
	}
	if(stai==1){
		printf("\nNot stable\n");
	}else{
		printf("\nStable\n");
	}
}

int main(){

	int n, i;
	scanf("%d", &n);
	Card card[n], bcard[n];
	
	for(i=0; i<n; i++){
		scanf(" %c%d", &card[i].suit,&card[i].num);
		card[i].id=i;
		//strcpy(bcard[i].suit,card[i].suit);
		bcard[i].suit=card[i].suit;
		bcard[i].num=card[i].num;
	}
	
	/*for(i=0; i<n; i++){
		printf("%c%d %d \n", card[i].suit,card[i].num, card[i].id);
	}*/
	
	BubbleSort(bcard, n);
	SelectionSort(card, n);
	isStable(bcard,card, n);
	
	return 0;
}
