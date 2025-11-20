#include<stdio.h>

int selectionSort(int A[], int N) {
  int i, j, swap_medium, swap_cnt = 0, minj;
  for (i = 0; i < N - 1; i++) {
    // iからN-1までの、はじめに見つかる最小値の位置minjを得る
    minj = i;
    for (j = i; j < N; j++) {
      if (A[j] < A[minj]) minj = j;
    }
    // 最小のminjと端のiの値を交換する
    swap_medium = A[i]; A[i] = A[minj]; A[minj] = swap_medium;
    // minj = iでなければ交換があるので記録する
    if (minj != i) swap_cnt++;
  }
  return swap_cnt;
}

int main() {
  // 宣言 & 入力
  int N, i, swap_cnt;
  scanf("%d", &N);
  int A[N];
  for (i = 0; i < N; i++) scanf("%d", &A[i]);
  // 実行
  swap_cnt = selectionSort(A, N);
  //出力
  for (i = 0; i < N; i++) {
    if (i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", swap_cnt);

  return 0;
}

