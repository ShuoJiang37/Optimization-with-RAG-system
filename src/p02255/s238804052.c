#include <stdio.h>
int B[101];
void insertionSort(int n);
void Print(int n);
int main(void){
	int i,n;

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&B[i]);
	insertionSort(n);
	return 0;
}

void insertionSort(int n){
	int i,j,v;
	for(i=0;i<n;i++){
		v = B[i];
		j = i - 1;
		while(j>=0 && B[j]>v){
			B[j+1] = B[j];
			j--;
			B[j+1] = v;
		}
		Print(n);
	}
}
void Print(int n){
	int k;
	for(k=0;k<n;k++){
		if(k) printf(" ");
		printf("%d",B[k]);
	}
	printf("\n");
}