#include <stdio.h>

int cnt=0,m=0;
int G[100];

void insertionSort(int *A,int n,int g){
  int i,j,v;
  for(i=g;i<n;i++){
    v  = A[i];
    j = i - g;
    while(j>=0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(int *A,int n){
  int i,h=0;
  cnt = 0;
  while(1){
    h=h*3+1;
    if(h>n){
      for(i=0;i<m;i++){
	h=(h-1)/3;
	G[i]=h;
      }
      break;
    }
    m++;
  }

  for(i=0;i<m;i++){
    insertionSort(A,n,G[i]);
  }
  
}

int main(){
  int i,n,A[1000001];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  shellSort(A,n);
  printf("%d\n",m);
  for(i=0;i<m;i++){
    if(i)
      printf(" ");
    printf("%d",G[i]);
  }
  printf("\n%d\n",cnt);
  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }
  return 0;
}

