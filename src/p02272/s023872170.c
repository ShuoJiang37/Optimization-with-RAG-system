#include<stdio.h>
#define N 500000
#define M 1000000000
void merge(int [],int ,int ,int );
void mergesort(int [],int ,int );
int arr[N/2+2],fg[N/2+2],count=0; 

int main(){
  int i,k,r[N];
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&r[i]);
  }
  mergesort(r,0,k);
  for(i=0;i<k-1;i++){
    printf("%d ",r[i]);
  }
  printf("%d\n",r[k-1]);
  printf("%d",count);
  printf("\n");
  return 0;
}
void merge(int A[],int l,int m,int r){
  int i,j,k;
  int a;
  int b;
  a=m-l;
  b=r-m;
  for(i=0;i<a;i++){
    arr[i] = A[l+i];
  }
  for(i=0;i<b;i++){
    fg[i]=A[m+i];
  }
  arr[a]=fg[b]=M;
  i = j = 0;
  for(k=l;k<r;k++){
    count++;
    if(arr[i] <= fg[j]){
      A[k] = arr[i];
      i++;
    }
      else {
    A[k] = fg[j];
    j++;
      }
  }
}
void mergesort(int A[],int l,int r){
  int m;
  if(l+1<r){
    m = (l+r)/2;
    mergesort(A,l,m);
    mergesort(A,m,r);
    merge(A,l,m,r);
  }
}
 