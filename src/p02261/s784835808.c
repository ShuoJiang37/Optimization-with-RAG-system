#include <stdio.h>
#define N 36

typedef struct{
	char mark;
	int number;
} card_t;

void Bubblesort(card_t a[],int n){
	char c1;
	int i,j,c2;
	for(i=0;i<n;i++){
		for(j=n-1;j>i;j--){
			if(a[j].number<a[j-1].number){
				c1=a[j].mark;
				c2=a[j].number;
				a[j].mark=a[j-1].mark;
				a[j].number=a[j-1].number;
				a[j-1].mark=c1;
				a[j-1].number=c2;
			}
		}
	}
	
	for(i=0;i<n;i++){
		if(i>0){
			printf(" ");
		}
		printf("%c%d",a[i].mark,a[i].number);
		if(i==n-1){
			printf("\n");
		}
	}
}

void Selectionsort(card_t a[],int n){
	char c1;
	int c2,i,j,min;
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(a[j].number<a[min].number){
				min=j;
			}
		}
		c1=a[i].mark;
		c2=a[i].number;
		a[i].mark=a[min].mark;
		a[i].number=a[min].number;
		a[min].mark=c1;
		a[min].number=c2;
	}
	for(i=0;i<n;i++){
		if(i>0){
			printf(" ");
		}
		printf("%c%d",a[i].mark,a[i].number);
		if(i==n-1){
			printf("\n");
		}
	}
}

int Stable(card_t a[],card_t b[],int n){
	int i;
	
	for(i=0;i<n;i++){
		if(a[i].mark!=b[i].mark){
			return 0;
		}
	}
	return 1;
}

int main(void){
	card_t  a[N],b[N];
	int i,n;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf(" %c",&a[i].mark);
		scanf(" %d",&a[i].number);
	}
	
	for(i=0;i<n;i++){
		b[i]=a[i];
	}
	
	Bubblesort(a,n);
	
	printf("Stable\n");
	
	Selectionsort(b,n);
	
	if(Stable(a,b,n)==1){
		printf("Stable\n");
	}
	
	else{
		printf("Not stable\n");
	}
	
	return 0;
}
