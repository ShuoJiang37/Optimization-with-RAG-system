#include<stdio.h>

#define N 1000000

int cnt=0;

void insertionSort(int *A, int n,int g){
  int i,j,v;

  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0&&A[j]>v){
      A[j+g] = A[j];
      j=j-g;
      cnt++;
    }
    A[j+g]=v;
  }
}

void shellSort(int *A,int n){
  int i,m,cm;
  cnt = 0;
  cm=0;
  m=5;
  int G[5]={1000,100,10,4,1};

  for(i=0;i<m;i++){
    insertionSort(A,n,G[i]);
    if(G[i]<=n) cm++;
  }
  printf("%d\n",cm);

  for(i=0;i<m-1;i++){
    if(G[i]<=n) printf("%d ",G[i]);
  }

  printf("%d\n",G[i]);
  printf("%d\n",cnt);
  for(i=0;i<n;i++) printf("%d\n",A[i]);
}

int main(){
  int n,i,A[1000000];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&A[i]);

  shellSort(A,n);
  return 0;
}