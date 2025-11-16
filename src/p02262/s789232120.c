#include <stdio.h>

int cnt=0;
int A[1000000];
int G[100];

void insertionSort(int A[],int n,int g){
  int i,v,j;

  for(i=g;i<n;i++){
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

void shellSort(int A[],int n){
  int m,i=0,h;

  for(h=1;h<=n;i++){
    G[i]=h;
    h=3*h+1;
  }
  m=i;
  printf("%d\n",m);
  for(i=0;i<m;i++){
    printf("%d",G[m-i-1]);
    if(i<m)printf(" ");
    insertionSort(A,n,G[m-i-1]);
  }
}

int main(void){
  int n,i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  shellSort(A,n);
  printf("\n");
  printf("%d\n",cnt);
  for(i=0;i<n;i++)printf("%d\n",A[i]);

  return 0;
}