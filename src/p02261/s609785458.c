#include <stdio.h>

struct card{
	char mark;
	int number;
};

void bubbleSort(struct card *a, int N);
void selectionSort(struct card *b, int N);
void check(struct card *a,struct card *b, int N);
int main(void){
	int i,N;
	scanf("%d",&N);
	
	struct card a[N];
	struct card b[N];
	
	for(i=0;i<N;i++){
		scanf(" %c%d",&(a[i].mark),&(a[i].number));
		b[i]=a[i];
		}
	bubbleSort(a, N);
	selectionSort(b, N);
	check(a,b,N);
	return 0;
}


void bubbleSort(struct  card *a,int N){
	int i,j;
	struct card tmp;
	for(i=0;i<N;i++){
		for(j=N-1;j>=i+1;j--){
			if(a[j].number<a[j-1].number){
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
			}
		}
	}
	
	for(j=0;j<N;j++){
		if(j!=N-1)printf("%c%d ",a[j].mark,a[j].number);
		else{printf("%c%d\n",a[j].mark,a[j].number);}
	}
	printf("Stable\n");
}

void selectionSort(struct card *a,int N){
	int i,j,minj = 0;
	struct card tmp;
	for(i=0;i<=N-1;i++){
		minj = i;
		for(j=i;j<= N-1;j++)
		{
			if(a[j].number<a[minj].number)
			{
				minj = j;
			}
		}
			tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
	}
	
	for(j=0;j<N;j++){
		if(j!=N-1)printf("%c%d ",a[j].mark,a[j].number);
		else{printf("%c%d\n",a[j].mark,a[j].number);}
	}
}

void check(struct card *a,struct card *b,int N){
	int count=0;
	int i;
	for(i=0;i<N;i++){
		if(a[i].mark !=b[i].mark){
			count++;
			}
	}
	
	if(count==0){
			printf("Stable\n");
			}
		else{
			printf("Not stable\n");
			}
}
