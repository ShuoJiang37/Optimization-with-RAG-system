#include<stdio.h>
#include<stdlib.h>

void insertionSort(int A[], int n, int g);
void ShellSort(int A[], int n);

int count;

int main(){
  int n;
  int i;
  int *A = NULL;

  scanf("%d", &n);
  A = (int*)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ShellSort(A, n);
  for(i = 0; i < n; i++){
    printf("%d\n", A[i]);
  }

  return 0;
}

void insertionSort(int A[], int n, int g){
  int i, j;
  int tmp = 0;

  for(i = g; i < n; i++){
    tmp = A[i];
    j = i - g;
    while(j >= 0 && A[j] > tmp){
      A[j+g] = A[j];
      j = j - g;
      count++;
    }
    A[j+g] = tmp;
  }
}

void ShellSort(int A[], int n){
  int i, j, m;
  int G[100];
  count = 0;

  m = 0;
  for(i = 0, j = 1; ; i++){
    if(j > n){break;}
    G[i] = j;
    j = 3*j+1;
    m++;
  }

  for(i = m-1; i >= 0; i--){
    insertionSort(A, n, G[i]);
  }

  printf("%d\n", m);
  for(i = m-1; i >= 0; i--){
    if(i == 0){
      printf("%d\n", G[i]);
    }else{
      printf("%d ", G[i]);
    }
  }
  printf("%d\n", count);
}

