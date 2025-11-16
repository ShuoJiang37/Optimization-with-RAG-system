#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
   
   
   
int n,cost;
int A[1001],B[1001];
int L[501],R[502];
   
   
void merge(int left,int mid,int right){
  int i,j,n1=mid-left,n2=right-mid;
  for(i=0;i<n1;i++) L[i]=A[left+i];
  L[n1]=INT_MAX;
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  R[n2]=INT_MAX;
  int l=0,r=0;
  for(i=left;i<right;i++){
    if(L[l]<=R[r]){
      A[i]=L[l];
      l++;
    }
    else{
      A[i]=R[r];
      r++;
    }
  }
}
   
   
void m_sort(int left,int right){
  int mid;
  if( left+1 >= right) return;
  mid=(left+right)/2;
  m_sort(left,mid);
  m_sort(mid,right);
  merge(left,mid,right);
}
   
   
void swap(int a,int b,int *C){
  int swap;
  swap=C[a];
  C[a]=C[b];
  C[b]=swap;
}
   
   
   
   
   
   
     
    
     
   
int main(){
  scanf("%d",&n);
  int i,j;
  int cnt,sum,min,start,x;
  int C[1001]={};
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    B[i]=A[i];
  }
  m_sort(0,n);
  for(i=0;i<n;i++){
    if(A[i]==B[i]) C[i]=1;
  }
  cost=0;
  for(i=0;i<n;i++){
    if(C[i]!=1){
      C[i]=1;
      cnt=0;
      sum=0;
      min=B[i];
      x=i;
      while(1){
        for(j=0;j<n;j++){
          if(B[x]==A[j]){
            C[j]=1;
            cnt++;
            sum+=B[j];
            if(min > B[j]) min=B[j];
            x=j;
            break;
          }
        }
        if(x==i) break;
      }
      sum-=min;
      if( (cnt -1)*min > (cnt -1)*A[0]+2*(min +A[0])) cost+=sum+(cnt-1)*A[0]+2*(min +A[0]);
      else cost+=sum+(cnt-1)*min;
    }
  }
  printf("%d\n",cost);
  return 0;
}