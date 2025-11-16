#include<stdio.h>
#define N 100

typedef struct{
  int index[1000000];
} NS;

void ISsort(NS *,int,int);

int cnt=0;

int main(){
  int i,n,G[100],m;
  NS ns;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d", &(ns.index[i]) );
  }

  G[0]=1;

  for(i=1; (G[i-1]*3+1)<n ;i++){
    G[i]=G[i-1]*3+1;
  }
  
  m=i;

  for(i=m-1;i>=0;i--) ISsort(&ns,n,G[i] );

  printf("%d\n",m);
  for(i=m-1;i>=0;i--){
    printf("%d",G[i] );
    if(i!=0) printf(" ");
  }
  printf("\n%d\n",cnt);
  for(i=0;i<n;i++) printf("%d\n", ns.index[i] );    

  return 0;
}

void ISsort(NS *ns,int n,int g){
  int i,j,swap;

  for(i=g;i<n;i++){
    swap=ns->index[i];
    j=i-g;
    while(j >= 0 && ns->index[j] > swap){
      ns->index[j+g]=ns->index[j];
      j-=g;
      cnt++;
    }
    ns->index[j+g]=swap;
  }
  
}

