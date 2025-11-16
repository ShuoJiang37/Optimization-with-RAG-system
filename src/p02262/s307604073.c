#include<stdio.h>
#include<stdlib.h>

int insert(int *,int,int);
void shell(int *,int);
int gizi(int *,int);
int main(){
	int n,i,*a;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	shell(a,n);
	free(a);
	return 0;
}

int insert(int *a,int n,int g){
	int i,j,key,cnt=0;
	for(i=g;i<n;i++){
		key=a[i];
		j=i-g;
		while(j>=0 && key<a[j]){
		a[j+g]=a[j];
		j=j-g;	
		cnt++;
		}
		a[j+g]=key;
	}
	
	return cnt;
}
void shell(int *a,int n){
	int m,i,cnt=0;
	int *g;
	g=(int *)malloc(sizeof(int)*n);
	m=gizi(g,n);
	for(i=m-1;i>=0;i--){
		cnt+=insert(a,n,g[i]);
	}
	printf("%d\n",cnt);
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	
}
int gizi(int *g,int n){
	int i=0,j;
	g[i]=1;
	while(n>=g[i]){
		i++;
		g[i]=3*g[i-1]+1;
	}
	printf("%d\n",i);
	for(j=i-1;j>=0;j--){
		if(j==0)printf("%d\n",g[j]);
		else printf("%d ",g[j]);
	}
	return i;
}


