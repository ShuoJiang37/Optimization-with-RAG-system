#include<stdio.h>
#include<math.h>
#include<stdlib.h>

static int cnt=0;

int makeg(int n,int *G)//gを作成 制約条件を満たすようにn以下の平方根とした
{
	int x;
	int i;
	x=sqrt(n);
	if(x>100) x=100;
	for(i=x;i>0;i--){
		G[x-i]=i*i;
	}
	
	return x;
}


void insertionsort(int *a,int n,int g)
{
	int i,j,v=0;
	for(i=g;i<n;i++){//gずつ離れた全ての組をソートする
		v=a[i];
		j=i-g;
		while(j>=0&&a[j]>v){
			a[j+g]=a[j];//組の中で小さいものを左に移動する
			j=j-g;//gずつ左にずらす
			cnt++;
		}
		a[j+g]=v;//大きいものを右側に移動
	}
}

void shellsort(int *a,int n)
{
	int m=3,i;
	int *G;
	
	G=(int*)malloc(sizeof(int)*n);
	m=makeg(n,G);
	printf("%d\n",m);
	for(i=0;i<m;i++){
		if(i!=0) printf(" ");
		printf("%d",G[i]);	
		insertionsort(a,n,G[i]);
	}
	printf("\n");
	
	free(G);
}

int main(void)
{
	int n,*a,i;
	
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	shellsort(a,n);

	printf("%d\n",cnt);
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}
