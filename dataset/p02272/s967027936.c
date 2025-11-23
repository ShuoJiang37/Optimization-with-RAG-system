#include<stdio.h>
//#include<stdlib.h>

void mergesort(int[],int,int);
void merge(int[],int,int,int);
int cnt = 0;

int main(){

  int S[1000000];
  int i,j;
  
  scanf("%d",&i);
 
  // S=(int *)malloc(i*sizeof(int));

  for(j = 0; j < i; j++){
    scanf("%ld",&S[j]);
  }

  mergesort(S,0,i);
  
  for(j = 0; j < i; j++){
   
    printf("%ld",S[j]);
    if(j < i-1){
      printf(" ");
    }
  }
  printf("\n%ld\n",cnt);
  
  //free(S);
  return 0;
}


void mergesort(int A[],int left,int right){

  int mid;
  
  if(left+1 < right){
    mid = (left + right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
  }


void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  int L[mid - left];
  int R[right - mid];

   n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }

  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }

  L[n1] = 999999999;
  R[n2] = 999999999;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i] < R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
    cnt++;
  }
}

