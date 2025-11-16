#include<stdio.h>
typedef struct jinde{
	char c;
	int number;
	int i;
}temp;

void bubbleSort(struct jinde c[], int n);
void selectionSort(struct jinde c[], int n);

int main (void){
	int n, i;
	scanf("%d", &n);
	struct jinde miku[n], miku2[n];
	
	for(i=0; i<n; i++) scanf(" %c%d", &miku[i].c, &miku[i].number);
	for(i=0; i<n; i++){
		miku[i].i=i;
		miku2[i] = miku[i];
	}
	
	bubbleSort(miku, n);
	selectionSort(miku2, n);
	return 0;
}

void bubbleSort(struct jinde c[], int n){
	int i, j, count=0;
	struct jinde x;
	
	for(i=0; i<n; i++){
		for(j=n-1; i+1<=j; j--){
			if(c[j].number < c[j-1].number){
				x=c[j];
				c[j]=c[j-1];
				c[j-1]=x;
			}
		}
	}

	for(i=0; i<n-1; i++) printf("%c%d ", c[i].c, c[i].number);
	printf("%c%d\n", c[i].c, c[i].number);
	
	for(i=0; i<n-1; i++){
		if(c[i].number==c[i+1].number){
			if(c[i].i<c[i+1].i){
				printf("Stable\n");
				break;
			}
			else{
				printf("Not stable\n");
				break;
			}
		}
		if(c[i].number!=c[i+1].number) count++;
	}
	
	if(count==n-1) printf("Stable\n");
}

void selectionSort(struct jinde c[], int n){
	int i, j, minj, count=0;
	struct jinde x;
	for(i=0; i<n; i++){
		minj=i;
		for(j=i; j<n; j++){
			if(c[j].number < c[minj].number){
				minj=j;
			}
		}
		x=c[i];
		c[i]=c[minj];
		c[minj]=x;
	}
	
	for(i=0; i<n-1; i++) printf("%c%d ", c[i].c, c[i].number);
	printf("%c%d\n", c[i].c, c[i].number);
	
	for(i=0; i<n-1; i++){
		if(c[i].number==c[i+1].number){
			if(c[i].i<c[i+1].i) count++;
		}
		if(c[i].number!=c[i+1].number) count++;
	}
	if(count!=n-1) printf("Not stable\n");
	else printf("Stable\n");
}
