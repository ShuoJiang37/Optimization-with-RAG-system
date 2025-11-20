#include<stdio.h>
#include<stdlib.h>
 
void insertionSort(int *, int, int);
void shellSort(int *,int);

int cnt = 0;
main(){
  int i,j,n,*A;


  scanf("%d",&n);
  A=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  shellSort(A, n);
  printf("%d\n",cnt);
  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }

  free(A);

  return 0;
}
 
void insertionSort(int *A, int n, int g){
   
  int i,j,v;
  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0 && A[j]>v){
      A[j+g]=A[j];
      j=j-g;
      cnt++;
    }
    A[j+g]=v;
  }
}
 
 
void shellSort(int *A,int n){
   
  int i,m = 0,*G;
 
  G=(int *)malloc(sizeof(int)*n);
  G[0]=0;
  for(i=0;i<n;i++){
    G[i+1]=3*G[i]+1;
    m++;
    if(G[i+1]>1000000)break;
  }

  while(G[m] > n)m--;

  printf("%d\n",m);

  for(i=m;i>1;i--)printf("%d ",G[i]);

  printf("%d\n", G[1]);

  for(i=m;i>=0;i--)insertionSort(A, n, G[i]);

  free(G);

}