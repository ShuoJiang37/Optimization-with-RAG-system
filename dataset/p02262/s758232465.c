#include<stdio.h>
#include<stdlib.h>
void shellSort(int *,int);
void insertSort(int *,int,int,int *);
int main(){
  int n,i,j,cut,v,k,m;
  int *array;
  scanf("%d",&n);
  array = malloc(sizeof(int)*n);
  for(i=0;i<n;i++)scanf("%d",&array[i]);
  shellSort(array,n);
  for(i=0;i<n;i++)printf("%d\n",array[i]);
  free(array);
  return 0;
}

void shellSort(int *array,int n){
  int cnt = 0,m,i;
  int *G;
  G = malloc(sizeof(int)*n);
  G[0]=1;
  for(i=1;1;i++){
    if(3*G[i-1]+1 < n)G[i] = 3*G[i-1]+1;
    else break;
  }
  m = i-1;
  for( i = m;i>=0;i--){
    insertSort(array,n,G[i],&cnt);
  }
  printf("%d\n",m+1);
  for(i=m;i>=0;i--){
    if(i != 0)printf("%d ",G[i]);
    else printf("%d\n",G[i]);
  }
  printf("%d\n",cnt);
  free(G);
}

void insertSort(int *A,int n,int g,int *cnt){
  int i,v,j;
  for(i=g;i<n;i++){
    v = A[i];
    j = i - g;
    while( j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j-g;
      (*cnt)++;
    }
    A[j+g] = v;
  }
}
  
  
    
  
		
  
  
  

