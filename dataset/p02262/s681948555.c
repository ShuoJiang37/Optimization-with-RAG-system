#include<stdio.h>
#include<stdlib.h>

long long cnt;
int l,A[1000000],n,G[1000000],j=0;

void insertionsort(int A[],int n,int g){
  int i,v,j;
  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0 && A[j]>v){
      A[j+g]=A[j];
      j-=g;
      cnt++;
      }
    A[j+g]=v;
  }
}

void shellsort(int A[],int n){
  int h,i;
  for(h=1;;){
    if(h>n)break;
    G[j++]=h;
    h=3*h+1;
  }
  for(i=j;i>=0;i--)insertionsort(A,n,G[i]);
}

int main(){
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  cnt=0;

  shellsort(A,n);

  printf("%d\n",j);
  for(i=j-1;i>=0;i--){
    printf("%d",G[i]);
    if(i)printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  for(i=0;i<n;i++)printf("%d\n",A[i]);

  return 0;
}
