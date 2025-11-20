#include<stdio.h>
//#include<stdlib.h>
#define INF (1<<30)

int A[500000];
int count = 0;
int R[500000],L[500000];


void merge(int A[],int left,int mid,int right){
  
  int n1,n2;
  int i,j,k;

  n1 = mid - left;
  n2 = right - mid; //divided by mid

  for( i = 0 ; i < n1 ; i++)
    L[i] = A[left + i];
  for( i = 0 ; i < n2 ; i++)
    R[i] = A[mid + i];

  L[n1] = INF;
  R[n2] = INF;

  i = 0;
  j = 0;
  
  for(k = left ; k < right ; k++){
    count++;
    if(L[i] < R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}


void mergeSort(int A[], int left, int right){
  int mid;
  if( left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
  
}


int main(){
  int length,i;
  scanf("%d",&length);
  for(i = 0; i < length ; i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,length);
  for(i = 0 ; i < length-1 ; i++)
    printf("%d ",A[i]);
  printf("%d\n%d\n",A[i],count);

  return 0;
  
}