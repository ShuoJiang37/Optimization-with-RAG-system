#include <stdio.h>
#define SENTINEL 1000000000
int count=0;

void merge(int A[], int left, int mid, int right){
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;
  int L[n1+1],R[n2+1];
  for(i=0;i<n1;i++){
    L[i] = A[left+i];
  }
  for(j=0;j<n2;j++){
    R[j]=A[mid+j];
  }
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
      count++;
    }
    else{ 
      A[k]=R[j];
      j=j+1;
      count++;
    }
  }
}
void mergeSort(int A[], int left, int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int i,S[500000],n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  mergeSort(S,0,n);
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}