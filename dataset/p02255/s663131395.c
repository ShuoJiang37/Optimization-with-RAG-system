/* 挿入ソート */
#include <stdio.h>
#define MAX_N 100

void insertionSort(int ary[], int n) {
  /* nは配列aryの大きさ */
  int i;
  for (i = 1; i < n; i++) {
    int key = ary[i];
    int j = i-1;
    while (j >= 0 && ary[j] > key) {
      ary[j+1] = ary[j];
      j--;
    }
    ary[j+1] = key;

    /* 各計算ステップの途中結果を表示 */
    printf("%d", ary[0]);
    for (j = 1; j < n; j++) {
      printf(" %d", ary[j]);
    }
    putchar('\n');
  }
}

int main(void) {
  int i, N;
  int array[MAX_N];

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &array[i]);
  }

  /* 最初の状態を出力 */
  printf("%d", array[0]);
  for (i = 1; i < N; i++) {
    printf(" %d", array[i]);
  }
  putchar('\n');
  
  insertionSort(array, N);

  return 0;
}