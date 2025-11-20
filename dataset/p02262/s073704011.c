#include<stdio.h>
#include<stdlib.h>

int cnt=0;

void isort(int* a,int n,int g){
	
	int v,j;
	
	for(int i=g;i<n;i++){
		v=a[i];
		j=i-g;
		while(j>=0&&a[j]>v){
			a[j+g]=a[j];
			j=j-g;
			cnt++;
		}
		a[j+g]=v;
	}
}

void shsort(int* a,int n){
	
	int cnt=0;
	int j=0;
	int h=1;
	int* g=(int*)malloc(sizeof(int)*n);
	
	while(h<=n){
		g[j]=h;
		j++;
		h=3*h+1;
	}
	
	int m=j;
	for(int i=m-1;i>=0;i--){
		isort(a,n,g[i]);
	}
	printf("%d\n",m);
	
	for(int i=m-1;i>=0;i--){
			printf("%d",g[i]);
			if(i!=0){
				printf(" ");
		}else{
			printf("\n");
		}
	}
	
}

int main(void){
	
	int n;
	
	scanf("%d",&n);
	
	int* a=(int*)malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	shsort(a,n);
	
	printf("%d\n",cnt);
	
	
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	
}

