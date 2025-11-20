#include<stdio.h>
#define N 1000000

int a[N];
int cnt=0;
int G[N];
int m=0;

void insertionSort(int n,int g){
	for(int i=g;i<n;i++){
		int v=a[i];
		int j=i-g;
		while(j>=0 && a[j] > v){
			a[j+g]=a[j];
			cnt++;
			j=j-g;
		}
		a[j+g]=v;
	}
	return;
}


void shellSort(int n){
	int temp=n;
	
	if(n==1){
		G[m++]=1;
	}
	else {
	
		while(temp/2!=0){
			G[m++]=temp/2;
			temp/=2;
		}
	}
	
	for(int i=0;i<m;i++)
		insertionSort(n,G[i]);
	
	return;
}



int main(){
	int n,i;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	shellSort(n);
	
	
	printf("%d\n",m);
	for(i=0;i<m-1;i++)
		printf("%d ",G[i]);
	printf("%d\n",G[m-1]);
	
	printf("%d\n",cnt);
	
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	
	return 0;
	
}
