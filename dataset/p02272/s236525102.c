#include <stdio.h>
#define INF 1000000001
#define N 500000
int comp=0;
int L[N],R[N];
void merge(int *A, int left, int mid, int right);
void mergeSort(int *A,int left,int right);

int main(void){
int A[N],i,n,left, mid, right;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&A[i]);
left=0;
right=n;
mergeSort(A, left, right);
for(i=0;i<n;i++){printf("%d",A[i]);
	if(i<n-1)printf(" ");
	else printf("\n");
	}
printf("%d\n",comp);
return 0;
}

void merge(int *A, int left, int mid, int right){
int  n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0;i<n1;i++)L[i] = A[left + i];
  for(i = 0;i<n2;i++)R[i] = A[mid + i];
  L[n1] = INF;
  R[n2] = INF;
  i = 0;
  j = 0;
//  for(k = left;k<right-1;k++) {
  for(k = left;k<=right-1;k++) {
    comp++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
    }
}
void mergeSort(int *A,int left,int right){
int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
    }
}

