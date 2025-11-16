#include<stdio.h>

void insertionSort(int array[],int n,int g);
void shellSort(int array[], int n);
int cnt,N;

int main(void){
	scanf("%d",&N);
	int array[N];
	for(int i=0;i<N;i++){
		scanf("%d\n",&array[i]);
		}
	shellSort(array,N);
	printf("%d\n",cnt);
	for(int i=0;i<N;i++){
		printf("%d\n",array[i]);
		}
	return 0;	
}
	
	
	

void insertionSort(int array[],int N,int g){
	int v,j;
	for(int i=g;i<N;i++){
		v=array[i];
		j=i-g;
		while(j>=0&&array[j]>v){
		array[j+g]=array[j];
		j=j-g;
		cnt++;
		}
		array[j+g]=v;
	}
}

void shellSort(int array[], int N){
	int num=0;
	int array2[100];
	array2[0] = 1;
	for(num = 1; 3*array2[num-1]+1 <= N; ++num){
	array2[num] = 3*array2[num-1]+1;
	}
	printf("%d\n", num);
	cnt=0; 
	for(int i = num-1; i >= 0; --i) {
    printf("%d%c", array2[i], " \n"[i==0]);
    insertionSort(array, N, array2[i]);
  }
}
		
