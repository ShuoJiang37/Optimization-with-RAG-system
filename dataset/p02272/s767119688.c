#include<stdio.h>
#include<stdlib.h>
#define N 500000
#define SENTINEL 1000000000

void Merge(int *, int, int, int);
void Sort(int *, int, int);
int count;

main(){
  int i, n, A[N];

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &A[i]);
  }
  Sort(A, 0, n);
  for(i = 0;i < n - 1;i++){
    printf("%d ", A[i]);
  }
  printf("%d\n%d\n", A[n - 1], count);
  return 0;
}

void Merge(int *A, int left, int mid, int right){
  /*int i, j, k, l, n1, n2, *L, *R;
  n1 = mid - left;
  n2 = right - mid;
  L = malloc(n1 * sizeof(int));
  R = malloc(n2 * sizeof(int));*/
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2], i, j, k;
  for(i = 0;i < n1;i++){
    L[i] = A[left + i];
  }
  for(i = 0;i < n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = SENTINEL;
  i = j = 0;
  for(k = left;k < right;k++){    
    if(L[i] <= R[j]){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
    count++;
  }
}

void Sort(int *A, int left, int right){
  int mid;
  if((left+1) < right){
    mid = (left + right) / 2;
    Sort(A, left, mid);
    Sort(A, mid, right);
    Merge(A, left, mid, right);
  }
}