#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int c;

void merge(int e[], int n, int left, int mid, int right){
  int i, j, k;

  int x = mid - left;
  int y = right - mid;
  for ( i = 0; i < x; i++ ) L[i] = e[left + i];
  for ( i = 0; i < y; i++ ) R[i] = e[mid + i];
  L[x] = R[y] = SENTINEL;
  i = j = 0;
  for ( k = left; k < right; k++ ){
    c++;
    if ( L[i] <= R[j] ){
      e[k] = L[i++];
    } else {
      e[k] = R[j++];
    }
  }
}

void mergeSort(int e[], int n, int left, int right ){
  int mid;
  if ( left+1 < right ){
    mid = (left + right)/2;
    mergeSort(e, n, left, mid);
    mergeSort(e, n, mid, right);
    merge(e, n, left, mid, right);
  }
}

main(){
  int e[MAX], n, i;
  scanf("%d", &n);
  c = 0;
  for ( i = 0; i < n; i++ ) {
    scanf("%d", &e[i]);
    if (e[i] >= SENTINEL ){
      return 1;
    }
  }
  mergeSort(e, n, 0, n);

  for ( i = 0; i < n; i++ ) {
    if ( i!=0 ) printf(" ");
    printf("%d", e[i]);
    }
  printf("\n");

  printf("%d\n", c);

  return 0;
}
