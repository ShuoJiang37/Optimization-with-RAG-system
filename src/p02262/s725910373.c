#include<stdio.h>
#define MAX 1000005

int A[MAX], G[MAX], n, cnt=0, m=1;

void insertSort(int g){
	int i,j,v;
	
    for(i=g+1; i<=n; i++){
		v=A[i];
		j=i-g;
		while(j>=1 && A[j]>v){
			A[j+g]=A[j];
			j-=g;
			cnt++;
		}
		A[j+g]=v;
	}
}


int main(){
  int i;	
  scanf("%d",&n);
  
  for(i=1; i<=n; i++)
        scanf("%d", &A[i]);
        
  G[1]=1;
  while(G[m]*3+1<n){
	m++;
	G[m]=G[m-1]*3+1;
  }
  
  for(i=m; i>=1; i--)
	  insertSort(G[i]);
  printf("%d\n",m);
  
  for(i=m; i>=1; i--)
	  printf("%d ",G[i]);
	  
  printf("\n");
  printf("%d\n",cnt);
  
  for(i=1; i<=n; i++)
	  printf("%d\n",A[i]);
 
  return 0;
}

