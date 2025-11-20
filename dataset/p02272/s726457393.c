#include <stdio.h>
#include <limits.h>

#define MAX_N 500000
#define INF INT_MAX

int mergeSort(int,int,int,int*);
int merge(int,int,int,int*);

int main(){
  int N,A[MAX_N],i,cnt;
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }
  cnt = mergeSort(0,N,N,A);
  for(i = 0 ; i < N ; i++){
    printf("%d%c",A[i],(i < N-1 ? ' ' : '\n'));
  }
  printf("%d\n",cnt);
  return 0;
}

int mergeSort(int left,int right,int N,int *A){
  int mid,res = 0;
  if(left + 1 < right){
    mid = (left + right) / 2;
    res += mergeSort(left,mid,N,A);
    res += mergeSort(mid,right,N,A);
    res += merge(left,mid,right,A);
  }
  return res;
}

int merge(int left,int mid,int right,int *A){
  int i,j,k,n1 = mid-left,n2 = right-mid;
  int L[n1+1],R[n2+1],res = 0;
  for(i = 0 ; i < n1 ; i++){ L[i] = A[left+i]; }
  for(i = 0 ; i < n2 ; i++){ R[i] = A[mid+i]; }
  L[n1] = R[n2] = INF;
  i = j = 0;
  for(k = left ; k < right ; k++){
    if(L[i] <= R[j]){ A[k] = L[i++]; }
    else{ A[k] = R[j++]; }
    res++;
  }
  return res;
}