#include <stdio.h>

typedef struct{
	char suit;
	int num;
}card_t;



void BubbleSort(card_t c[],int N){
	int j,flag=1;
	card_t x;
	
	while(flag==1){
		flag=0;
		for(j=N-1;j>=1;j--){
			if(c[j].num<c[j-1].num){
				x=c[j];
				c[j]=c[j-1];
				c[j-1]=x;
			
				flag=1;
			}
		}
	}
}

void SelectionSort(card_t a[], int N){
	int i, j,min, flag=1;
	card_t x;
	
	while(flag==1){
		flag=0;
		for(i=0;i<N;i++){
			min=i;
			for(j=i; j<N; j++){
				if(a[j].num<a[min].num){
					min=j;
					flag=1;
				}
			}
			x=a[i];
			a[i]=a[min];
			a[min]=x;
			
		}
	}
}

int isStable(card_t in[], card_t out[], int N){
	int i, j, a, b;
	
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
			for(a=0; a<N; a++){
				for(b=a+1; b<N;b++){
					if((in[i].num==in[j].num)&&(in[j].num==out[a].num)&& (in[i].num==out[b].num) && (in[i].suit==out[b].suit) && (in[j].suit==out[a].suit)){return 1;}
				}
			}
		}
	}
	return 0;
}

int main(void)
{
	int N;
	int i, judge;
	scanf("%d", &N);
		
	card_t c[N];
	card_t a[N];
	card_t r[N];
	for(i=0; i<N; i++){
		scanf("%*c%c", &c[i].suit);
		scanf("%d", &c[i].num);
		a[i]=c[i];
		r[i]=c[i];
	}
	
	BubbleSort(c, N);
	SelectionSort(a,N);
	
	
	for(i=0; i<N-1; i++){
		printf("%c", c[i].suit);
		printf("%d ", c[i].num);
		}
	printf("%c", c[N-1].suit);
	printf("%d\n", c[N-1].num);
	judge=isStable(c, r, N);
	if(judge==0){printf("Stable\n");}
	else {printf("Not stable\n");}
	
	for(i=0; i<N-1; i++){
		printf("%c", a[i].suit);
		printf("%d ", a[i].num);
		}
	printf("%c", a[N-1].suit);
	printf("%d\n", a[N-1].num);
	judge=isStable(a, r, N);
	if(judge==0){printf("Stable\n");}
	else {printf("Not stable\n");}
	return 0;
}
