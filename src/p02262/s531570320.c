#include<stdio.h>
#include<stdlib.h>
#define N 1000000
#define A_IN 1000000000
int cnt=0;
int n;
int*G;
int A[N];
int c=0;
void insertionSort(int A[], int n, int g){
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

void shellSort(int A[],int n){
  int i=0,q;
  cnt=0;
  G=(int *)malloc(n * sizeof(int));
 
  for(q=1;;){
    if(q>n) break;
    G[i]=q;
    i++;
    q=3*q+1;
  }
  c=i;
  for(i=c-1;i>=0;i--){
    insertionSort(A,n,G[i]);
  }
}


int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  shellSort(A,n);

  printf("%d\n",c);

  for(i=c-1;i>=0;i--){
    printf("%d",G[i]);
    if(i) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  for(i=0;i<n;i++)printf("%d\n",A[i]);

  free(G);
  
  return 0;
}

