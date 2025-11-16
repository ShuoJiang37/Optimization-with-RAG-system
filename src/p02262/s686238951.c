#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define O 0
#define I 1
#define T 3

int c=0;

void insertSort(int *,int,int);

int main(){
  int i,j,n,m=O,G[20];
  int *A;

  scanf("%d",&n);
  A = malloc(n*sizeof(int));
  for(i=O;i<n;i++){
    scanf("%d",&A[i]);
  }
  G[O]=O;
  while(I){
    if(n<T*G[m]+I){
      break;
    }
    G[m+I]=T*G[m]+I;
    m++;
 }
  for(i=m;i>O;i--){
    insertSort(A,n,G[i]);
  }
  printf("%d\n",m);
  for(i=m;i>=I;i--){
    printf("%d ",G[i]);
  }
  printf("\n");
  printf("%d\n",c);
  for(i=O;i<n;i++){
    printf("%d\n",A[i]);
  }
  return O;
}

void insertSort(int *A,int n,int g){
  int i,j,key;
  for(i=g;i<n;i++){
    j=i;
    key=A[i];
    while(O<=j-g){
      if(A[j-g]<=key){
	break;
      }
      A[j]=A[j-g];
      j-=g;
      c++;
    }
   A[j]=key;
 }
}


