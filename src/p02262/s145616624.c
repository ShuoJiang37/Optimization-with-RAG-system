#include<stdio.h>
#include<stdlib.h>

long long cnt;
int l,A[1000000],n,Gsize;
int * G;

void insertionSort(int A[], int n, int g){
  int i,j,v;
  for(i=g;i<=n-1;i++) {
    v=A[i];
    j=i-g;
    while(j>=0&&A[j]>v){
      A[j+g]=A[j];
      j=j-g;
      cnt++;
    }
    A[j+g]=v;
  }
}

void shellSort(int A[], int n) {
  int i=0,j,h;
  for(h=1;;) {
    if(h>n) break;
    G[i++]=h;
     h=h*3+1;
  }
  Gsize=i;
  for(i=Gsize-1;i>=0;i--) {
    insertionSort(A,n,G[i]);
  }
}

int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  G=(int *)malloc(sizeof(int)*n);
  cnt = 0;
  shellSort(A,n);
  printf("%d\n",Gsize);
  for(i=Gsize-1;i>=0;i--) {
    printf("%d",G[i]);
    if(i){
      printf(" ");
    }
  }
  printf("\n" );
  printf("%lld\n", cnt);
  for (i=0;i<n;i++){
    printf("%d\n",A[i]);
  }
  return 0;
}