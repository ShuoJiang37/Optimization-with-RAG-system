#include<stdio.h>

#define MAX 500000
#define INFTY 2000000000

int g_count;

void merge(int [],int,int,int);
void mergeSort(int [],int,int);

int main(){
  int n,i;
  int A[MAX];

  scanf("%d",&n);
  for(i = 0;i <= n-1;i++) scanf("%d",&A[i]);
  
  mergeSort(A,0,n);
  
  for(i = 0;i <= n-1;i++){
    if(i != 0) printf(" ");
    
    printf("%d",A[i]);
  }
  
  printf("\n");
  
  printf("%d\n",g_count);

  return 0;
}


void merge(int A[],int left,int mid,int right){
  int L[MAX / 2 + 2],R[MAX / 2 + 2];
  int n1,n2,i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;
  /*L[0...n1],R[0...n2]を生成*/
  for(i = 0;i <= n1-1;i++)
    L[i] = A[left + i];

  for(i = 0;i <= n2-1;i++)
    R[i] = A[mid + i];
  
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j= 0;
  for(k = left;k <= right-1;k++){
    g_count++;
    if (L[i] <= R[j])
      A[k] = L[i++];
    
    else
      A[k] = R[j++];
  }
}

void mergeSort(int A[],int left,int right){
  if(left + 1 < right){
    int mid = (left + right) / 2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
  

