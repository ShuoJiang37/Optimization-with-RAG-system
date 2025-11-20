#include<stdio.h>
#include<string.h>
void bubblesort(char bubble[][3],int N);
void selectionsort(char select[][3],int N);
int main(void){
	int i;
	int N;
	scanf("%d",&N);
	char buffer[N][3];
	char bubble[N][3];
	char select[N][3];
	for(i=0;i<N;i++){
		scanf("%s",buffer[i]);
	}
	for(i=0;i<N;i++){
		strcpy(bubble[i],buffer[i]);
		strcpy(select[i],buffer[i]);
	}
	bubblesort(bubble,N);
	selectionsort(select,N);
	//1行目
	for(i=0;i<N;i++){
		if(i!=N-1) printf("%s ",bubble[i]);
		else printf("%s\n",bubble[i]);
	}
	//2行目
	printf("Stable\n");
	//3行目
	for(i=0;i<N;i++){
		if(i!=N-1) printf("%s ",select[i]);
		else printf("%s\n",select[i]);
	}
	//4行目
	for(i=0;i<N;i++){
		if(strcmp(bubble[i],select[i])!=0){
			printf("Not stable\n");
			return 0;
		}
	}
	printf("Stable\n");
	return 0;
}
void bubblesort(char bubble[][3],int N){
	char tempsuit;
	char tempnum;
	int i,j;
	for(i=0;i<N;i++){
		for(j=N-1;j>i;j--){
			if(bubble[j-1][1]>bubble[j][1]){
				tempsuit=bubble[j-1][0];
				tempnum=bubble[j-1][1];
				bubble[j-1][0]=bubble[j][0];
				bubble[j-1][1]=bubble[j][1];
				bubble[j][0]=tempsuit;
				bubble[j][1]=tempnum;
			}
		}
	}
}
void selectionsort(char select[][3],int N){
	char tempsuit;
	char tempnum;
	int i,j;
	int minj;
	for(i=0;i<N;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(select[minj][1]>select[j][1]){
				minj=j;
			}
		}
		tempsuit=select[i][0];
		tempnum=select[i][1];
		select[i][0]=select[minj][0];
		select[i][1]=select[minj][1];
		select[minj][0]=tempsuit;
		select[minj][1]=tempnum;
	}
}


