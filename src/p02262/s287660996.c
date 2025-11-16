#include<stdio.h>

void insertionSort(int *,int,int);
void shellSort(int *,int);
int cnt,mcnt=0;
int main(){

  int i,n;
  int A[2000000];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  shellSort(&A[0],n);

  for(i=0;i<n;i++)printf("%d\n",A[i]);

  return 0;
}

void shellSort(int *A,int n){
  int m,i,j;
  int G[100];
  cnt=0;
  m=99;
  for(i=m;i>=0;i--) {
    G[i]=1+(m-i)*6;
    if(G[i]<=n)mcnt++;
  }
    
  
  for(i=0;i<m+1;i++) insertionSort(A,n,G[i]);
    
  printf("%d\n",mcnt);
  for(i=m-mcnt+1;i<m;i++) printf("%d ",G[i]);
  printf("%d\n%d\n",G[i],cnt);
}

void insertionSort(int *A,int n,int g){
  int v,j,i;
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

