#include<stdio.h>
#include<stdlib.h>
#define N 1000000
int count=0,l,*S;
 
void insertionSort(int A[], int n, int m){
int i,v,j;
  for(i=m;i<n;i++){
    v=A[i];
    j=i-m;
    while(j>=0&&A[j]>v){
      A[j+m]=A[j];
      j-=m;
      count++;
    }
    A[j+m]=v;
  }
}
 
void Sort(int A[],int n){
  int i=0,a;
 
  S=(int *)malloc(n * sizeof(int));
 
  for(a=1; ; ){
    if(a>n) break;
    S[i]=a;
    i++;
    a=3*a+1;
  }
  l=i;
  for(i=l-1;i>=0;i--){
    insertionSort(A,n,S[i]);
  }
}
 
 
 
int main(){
  int i,A[N],n;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
 
  Sort(A,n);
 
  printf("%d\n",l);
 
  for(i=l-1;i>=0;i--){
    printf("%d",S[i]);
    if(i) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  for(i=0;i<n;i++)printf("%d\n",A[i]);
 
  free(S);
  return 0;
}

