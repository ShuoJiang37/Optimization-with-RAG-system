#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *A, int n, int g);
void shellSort(int *A, int n);

static int count;

int main(void){
  int i, n, *a;

  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  if(a == NULL){
    printf("?????¢????¢??????¨??????\n");
    return -1;
  }
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  shellSort(a, n);
  for(i = 0; i < n; i++){
    printf("%d\n", a[i]);
  }
  free(a);
  return 0;
}


void insertionSort(int *A, int n, int g){
  int i, j, v;

  for(i = g; i < n; i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j -= g;
      count++;
    }
    A[j+g] = v;
  }
}


void shellSort(int *A, int n){
  int m = 1, h = 1;

  while(3*h+1 < n){
    h = 3 * h + 1;
    m++;
  }
  printf("%d\n", m);
  count = 0;
  for( ; h >= 1; h /= 3){
    insertionSort(A, n, h);
    printf("%d", h);
    if(h != 1){
      printf(" ");
    }
  }
  printf("\n%d\n", count);
}