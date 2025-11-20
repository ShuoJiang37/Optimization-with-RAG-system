#include<stdio.h>
int G[1000],g;
int c=0;
void sort(int A[],int n,int g){
	int i,v,j;
	for(i=g; i<n; i++){
		v=A[i];
		j=i-g;
		while(j>=0 && A[j]>v){
			A[j+g]=A[j];
			j=j-g;
			c++;
			}
		A[j+g]=v;
	}
}
void shell(int A[],int n){
	int v,p;
	G[0]=1;
	for(v=1; ; v++){
		G[v]=G[v-1]*3+1;
		if(G[v]>n){
			g=v-1;
			break;
		}
	}
	for(p=g; p>=0; p--){
		sort(A,n,G[p]);
		}
}
int main(void){
	int n,i,j;
	scanf("%d",&n);
	int A[n];
	for(i=0; i<n; i++){
		scanf("%d",&A[i]);
	}
	shell(A,n);
	printf("%d\n", g+1);
	for(i=g; i>=1; i--){printf("%d ",G[i]);}
	printf("%d\n",G[0]);
	printf("%d\n",c);
	for(i=0; i<n; i++){
		printf("%d\n",A[i]);
	}
	return 0;
}
