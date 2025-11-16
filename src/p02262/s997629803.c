#include<stdio.h>

void insertionSort(int a[], int n,int g);
void shellSort(int a[] ,int n);
int cnt=0;
int G[9999];
int m;
void insertionSort(int a[], int n, int g){
	int i,j,v;
	
	for(i = g;i < n;i++){
		v = a[i];
		j = i - g;
		while(j >=0 && a[j] > v){
			a[j+g] = a[j];
			j = j-g;
			cnt++;
		}
		a[j+g] = v;
	}
}
void shellSort(int a[] ,int n){
	cnt = 0;
	int i;
	G[0] = 1;
	
	for(i = 1;;i++){
		G[i] = G[i-1]*3+1;
		if(G[i]>n){break;}
	}
	m = i-1;
	for(i = m;i >=0;i--){
		insertionSort(a,n,G[i]);
	}
	
}
int main (void){
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i =0;i < n;i++){
		scanf("%d",&a[i]);
	}
	shellSort(a,n);
	
	printf("%d\n",m+1);
	for(i = m;i>0;i--){
		printf("%d ",G[i]);
	}
	printf("%d\n",G[0]);
	printf("%d\n",cnt);
	for(i = 0;i < n;i++){
		printf("%d\n",a[i]);
	}
	
}
