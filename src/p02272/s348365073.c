#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

 
int count=0;


/*????????????????????????A[left]*/
void merge(int *A,int left,int mid,int right){
  int i,n1,n2;
  n1=mid-left;
  n2=right-mid;
  int L[n1+1],R[n2+1];
  for(i=left;i<=mid-1;i++) L[i-left]=A[i];
  for(i=mid;i<=right-1;i++) R[i-mid]=A[i]; 
  L[n1]=INT_MAX;
  R[n2]=INT_MAX;
  int l=0,r=0;
  for(i=left;i<right;i++){
    count++;
    if(L[l]<R[r]){
      A[i]=L[l];
      l++;
    }
    else{
      A[i]=R[r];
      r++;
    }
  }
}


void m_sort(int *A,int left,int right){
  if(right <= left+1) return;
  int mid;
  mid=(left+right)/2;
  m_sort(A,left,mid);
  m_sort(A,mid,right);
  merge(A,left,mid,right);
}
    




int main(){
  int n,*A,i;
  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  m_sort(A,0,n);
  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}