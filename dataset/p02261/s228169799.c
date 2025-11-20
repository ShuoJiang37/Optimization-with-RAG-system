#include <stdio.h>

typedef struct{
	char suit;
	char value;
} card;

void bubble(card *p,int N);

int main(){
	card p1[50];
	card p2[50];
	card key;
	int i,j,N,min,f=0,l=0;

	scanf("%d",&N);

	for(i=0;i<N;i++){
		scanf(" %c%c",&p1[i].suit,&p1[i].value);
	}

	for(i=0;i<N;i++){
		p2[i]=p1[i];
	}

	bubble(p1,N);

	for(i=0;i<N;i++){
		printf("%c%c",p1[i].suit,p1[i].value);
		if(i!=N-1) printf(" ");
	}
	printf("\nStable\n");	

	for(i=0;i<N;i++){
		min=i;
		f=0;
		for(j=i+1;j<N;j++){
			if(p2[j].value==p2[min].value) f=1;
			if(p2[j].value<p2[min].value){
				min=j;
				if(f==1) l=1;
			}
		}
		if(min!=i){
			key=p2[i];
			p2[i]=p2[min];
			p2[min]=key;
		}
	}

	for(i=0;i<N;i++){
		printf("%c%c",p2[i].suit,p2[i].value);
		if(i!=N-1) printf(" ");
	}
	printf("\n");
	if(l==1) printf("Not stable\n");
	else printf("Stable\n");

	return 0;
}

void bubble(card *p,int N){
	card key;
	int i,j;
	for(i=0;i<N;i++){
		for(j=N-1;j>i;j--){
			if(p[j].value<p[j-1].value){
				key=p[j];
				p[j]=p[j-1];
				p[j-1]=key;
			}
		}
	}
}