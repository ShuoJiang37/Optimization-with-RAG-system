#include <stdio.h>
#include <stdlib.h>
#define N 1000000
void insertionSort(int *A,int n,int g);
void shellSort(int *A,int n);
int m=7,cnt;
int main(){
  int i,n,A[N];
  
  scanf("%d",&n);
    
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  shellSort(A,n);
  
  for(i=0;i<n;i++) printf("%d\n",A[i]);
  
  return 0;
}
void insertionSort(int *A,int n,int g){
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
  int i,x=0,G[]={1093,364,121,40,13,4,1};
  cnt=0;
  if(n<1093) x++;
  if(n<364) x++;
  if(n<121) x++;
  if(n<40) x++;
  if(n<13) x++;
  if(n<4) x++;
  printf("%d\n",m-x);
  for(i=x;i<m;i++){
    if(i<m-1)  printf("%d ",G[i]);
    else printf("%d\n",G[i]);
    }
  
    for(i=x;i<m;i++){
      insertionSort(A,n,G[i]);
    }
  printf("%d\n",cnt);
}