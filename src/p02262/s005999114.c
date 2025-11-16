#include<stdio.h>

int n,cont,flag=0;
int A[1000000];
int G[1000000];

void insertionSort(int *A,int n,int g){
  int v,j,i;
  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0 && A[j]>v){
      A[j+g]=A[j];
      j-=g;
      cont++;
    }
    A[j+g]=v;
  }
}

void shellSort(int *A,int n){
  int h,i;
  for(h=1; ; ){
    if(h>n) break;
    G[flag++]=h;
    h=3*h+1;
  }
  for(i=flag-1;i>=0;i--){
    insertionSort(A,n,G[i]);
  }
}

int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  cont=0;
  shellSort(A,n);
  printf("%d\n",flag);
  for(i=flag-1;i>=0;i--){
    printf("%d",G[i]);
    if(i) printf(" ");
  }
  printf("\n");
  printf("%d\n",cont);
  for(i=0;i<n;i++) printf("%d\n",A[i]);
  return 0;
}
  
  