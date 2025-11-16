#include<stdio.h>
void insertionSort(int *,int,int);
void shellSort(int *,int);
int cnt=0;
int m=0;
int G[100];
int main(){
  int A[1000001];
  int i;
  int N;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  shellSort(A,N);
  printf("%d\n",m);
  for(i=m-1;i>=0;i--){
    printf("%d",G[i]);
    if(i) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  for(i=0;i<N;i++){
    printf("%d\n",A[i]);
  }
  return 0;
}

void insertionSort(int A[],int n,int g){
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

void shellSort(int A[],int n){
  int i;
  int ret=0;
  cnt=0;
  while(1){
    ret=ret*3+1;
    if(ret>n) break;
    G[m++]=ret;
  }
    
  for(i=0;i<m;i++){
    insertionSort(A,n,G[m-i-1]);
  }
}
  

