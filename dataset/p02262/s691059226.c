#include<stdio.h>
int A[10000000];
int m,count=0;
int G[1000000];
 
void insert(int *A,int n,int g){
  int v;
  int i,j;
  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0 && A[j]>v){
      A[j+g]=A[j];
      j-=g;
      count++;
    }
    A[j+g]=v;
  }
}
void shell(int *A,int n){
  int h,i;
  for(i=0,h=1;;i++){
    if(h>n)break;
    G[i]=h;
    h=3*h+1;
  }
  m=i+1;
  for(i=m-1;i>=0;i--){
    insert(A,n,G[i]);
  }
}
int main(){
  int n,i,j;
  scanf("%d",&n);
 
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  shell(A,n);
  printf("%d\n",m-1);
  for(i=m-2;i>=0;i--){
    printf("%d",G[i]);
    if(i)printf(" ");
  }
  printf("\n%d\n",count);
  for(i=0;i<n;i++)printf("%d\n",A[i]);
 
  return 0;
}