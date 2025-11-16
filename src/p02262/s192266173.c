#include<stdio.h>
#include<stdlib.h>

void shell_sort(int a[], int n){
  int i, j, h;
  int m = 0;
  int cnt = 0;
  int x[100] ={1};

  if(n < 2){
  printf("1\n1\n0\n");  
  }else{
  for(h = n / 2; h > 0; h /=2, m++){
        x[m] = h;
    for(i = h; i  < n; i++){
      int tmp = a[i];
      for(j = i - h; j >= 0 && a[j] > tmp; j -= h){
        a[j + h] = a[j];
        cnt++;
      }
      a[j + h] = tmp;
    }
  }
  printf("%d\n", m);
  for(i = 0; i < m - 1; i++){
    printf("%d ", x[i]);
  }
  printf("%d\n", x[i]);
  printf("%d\n", cnt);
  }
}

int main(void){
  int n, i;
  int *A;

  scanf("%d", &n);
  A = calloc(n, sizeof(int));

  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  shell_sort(A, n);

  for(i = 0; i < n; i++){
    printf("%d\n", A[i]);
  }

  free(A);

  return 0;
}

