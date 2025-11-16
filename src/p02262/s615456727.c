#include <stdio.h>

#define N 1000000

int G[N];
int cou=0,num=0;

void insertsort(int *A,int n,int g){
  int i,j,v;

  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0 && v<A[j]){
      A[j+g]=A[j];
      j-=g;
      num++;
    }
    A[j+g]=v;
  }
}

void shell(int *A,int n){
  int h,i;

  for(h=1;;){
    if(h>n) break;
    G[cou]=h;
    h=3*h+1;
    cou++;
  }
  for(i=cou-1;i>=0;i--){
    insertsort(A,n,G[i]);
  }
}

int main(void){
  int n,i;
  int A[N];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  shell(A,n);

  printf("%d\n",cou);

    for(i=cou-1;i>=0;i--){
      printf("%d",G[i]);
      if(i!=0)printf(" ");
    }
  printf("\n");
  printf("%d\n",num);
  for(i=0;i<n;i++) printf("%d\n",A[i]);
  return 0;
}