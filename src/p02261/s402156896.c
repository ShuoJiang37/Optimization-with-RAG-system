#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define CARDS 1024

void swap(char *p,char *q){
	char tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
void swap_int(int *p,int *q){
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

void Bubblesort(char Bubblecards[][3],const int n){
	int i,j;
	int Stablechecker[CARDS][2];
	for(i=0;i<n;i++){
		Stablechecker[i][0]=Bubblecards[i][1]-'0';
		Stablechecker[i][1]=i;
	}
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(Bubblecards[j][1]-'0'<Bubblecards[j-1][1]-'0'){
				swap_int(&Stablechecker[j][0],&Stablechecker[j-1][0]);
				swap_int(&Stablechecker[j][1],&Stablechecker[j-1][1]);
				swap(&Bubblecards[j][0],&Bubblecards[j-1][0]);
				swap(&Bubblecards[j][1],&Bubblecards[j-1][1]);
			}
		}
	}
	for(i=0;i<(n-1);i++){
	printf("%s ",Bubblecards[i]);
	}
	printf("%s\n",Bubblecards[n-1]);
	
	int check=0;
	for(i=0;i<(n-1);i++){
		if(Stablechecker[i][0]==Stablechecker[i+1][0]){
			if(Stablechecker[i][1]>Stablechecker[i+1][1]) check=-1;
		}
	}
	if(check==0) printf("Stable\n");
	else printf("Not stable\n");
}



void Selectionsort(char Selectioncards[][3],const int n){
	int i,j,minj;
	int Stablechecker[CARDS][2];
	for(i=0;i<n;i++){
		Stablechecker[i][0]=Selectioncards[i][1]-'0';
		Stablechecker[i][1]=i;
	}
	for(i=0;i<(n-1);i++){
		minj=i;
		for(j=i+1;j<n;j++){
			if(Stablechecker[j][0]<Stablechecker[minj][0]){
			minj = j;
			}
		}

				swap_int(&Stablechecker[i][0],&Stablechecker[minj][0]);
				swap_int(&Stablechecker[i][1],&Stablechecker[minj][1]);
				swap(&Selectioncards[i][0],&Selectioncards[minj][0]);
				swap(&Selectioncards[i][1],&Selectioncards[minj][1]);

	}
	for(i=0;i<(n-1);i++){
	printf("%s ",Selectioncards[i]);
	}
	printf("%s\n",Selectioncards[n-1]);
	int check=0;
	for(i=0;i<(n-1);i++){
		if(Stablechecker[i][0]==Stablechecker[i+1][0]){
			if(Stablechecker[i][1]>Stablechecker[i+1][1]) check=-1;
		}
	}
	if(check==0) printf("Stable\n");
	else printf("Not stable\n");
}

int main(void){
	int i,j,n;
	char cards[CARDS][3];
	char Bubblecards[CARDS][3];
	char Selectioncards[CARDS][3];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%s",cards[i]);
	}
	memcpy(Bubblecards,cards,CARDS);
	memcpy(Selectioncards,cards,CARDS);
	
	Bubblesort(Bubblecards,n);
	Selectionsort(Selectioncards,n);
	
	return 0;
}