#include<stdio.h>

#define MAX 500000
#define INFTY 2000000000

int count;

void merge(int [],int,int,int);
void mergeSort(int [],int,int);

int main(){
  int n,i;
  int S[MAX];

  scanf("%d",&n);
  for(i = 0;i <= n-1;i++){
    scanf("%d",&S[i]);
  }
  
  mergeSort(S,0,n);
  
  for(i = 0;i <= n-1;i++){
    if(i != 0){
      printf(" ");
    }
    printf("%d",S[i]);
  }
  
  printf("\n");
  
  printf("%d\n",count);

  return 0;
}


void merge(int S[],int left,int mid,int right){
  int L[MAX / 2 + 2],R[MAX / 2 + 2];
  int n1,n2,i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;
  /*L[0...n1],R[0...n2]を生成*/
  for(i = 0;i <= n1-1;i++){
    L[i] = S[left + i];
  }
  for(i = 0;i <= n2-1;i++){
    R[i] = S[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j= 0;
  for(k = left;k <= right-1;k++){
    count++;
    if (L[i] <= R[j]){
      S[k] = L[i++];
    }
    else{
      S[k] = R[j++];
    }
  }
}

void mergeSort(int S[],int left,int right){
  if(left + 1 < right){
    int mid = (left + right) / 2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}
  

