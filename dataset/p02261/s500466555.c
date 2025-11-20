#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char mark;
	int num;	
}card;

void BubbleSort(card *, int );
void SelectionSort(card *, int );
int juage(card *, card *, int );
int main(void){
	card arr[40],barr[40],sarr[40];
	int i,j,N;
	char tmp[3];
	scanf("%d",&N);
	for(i=0; i<N; i++){
		scanf("%s",tmp);
		barr[i].mark = sarr[i].mark = arr[i].mark = tmp[0];
		barr[i].num = sarr[i].num = arr[i].num = atoi(&tmp[1]);
//		printf("%c%d ",arr[i].mark,arr[i].num);
	}
	BubbleSort(barr, N);
	printf("Stable\n");
	SelectionSort(sarr, N);
	if(juage(barr,sarr, N)){
		printf("Not stable\n");
	}
	else {
		printf("Stable\n");
	}
	return 0;	
}
int juage(card *barr,card *sarr, int _N){
	int i;
	for(i=0; i<_N; i++){
		if(barr[i].mark != sarr[i].mark){
			return 1;
		}
	}
	return 0;
}
void BubbleSort(card *arr, int _N){
	int i,j,ntmp;
	char mtmp;
	for(i=0; i< _N-1; i++){
		for(j = _N-1; j>0; j--){
			if(arr[j].num < arr[j-1].num){
				ntmp = arr[j].num;
				mtmp = arr[j].mark;
				arr[j].num = arr[j-1].num;
				arr[j].mark = arr[j-1].mark;
				arr[j-1].num = ntmp;
				arr[j-1].mark = mtmp;
			}
		}
	}
	for(i=0; i < _N-1; i++){
		printf("%c%d ",arr[i].mark,arr[i].num);
	}
		printf("%c%d",arr[_N-1].mark,arr[_N-1].num);
	printf("\n");
}	

void SelectionSort(card *arr, int _N){
	int minj,i,j,ntmp;
	char mtmp;
	for(i=0; i<_N; i++){
		minj = i;
		for(j=i; j<_N; j++){
			if(arr[j].num < arr[minj].num){
				minj = j;
			}
		}
		ntmp = arr[i].num;
		mtmp = arr[i].mark;	
		arr[i].num = arr[minj].num;
		arr[i].mark = arr[minj].mark;
		arr[minj].num = ntmp;
		arr[minj].mark = mtmp;
	}		
	for(i=0; i < _N-1; i++){
		printf("%c%d ",arr[i].mark,arr[i].num);
	}
		printf("%c%d",arr[_N-1].mark,arr[_N-1].num);
	printf("\n");
}