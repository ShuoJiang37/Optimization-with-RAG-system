#include<stdio.h>
#define N 100

void print(int a[],int n){
	for(int i=0;i<n-1;i++)
		printf("%d ",a[i]);
		
	printf("%d\n",a[n-1]);
	
	return;
}


void insertionSort(int a[],int n){
	int i,j;
	
	for(i=0;i<n;i++){
		int t=a[i];
		j=i-1;
		while(j>=0 && a[j] > t){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
		print(a,n);
	}
	
	return;
}


int main(){
	int n,i;
	int a[N];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	insertionSort(a,n);
	
	return 0;
	
}
