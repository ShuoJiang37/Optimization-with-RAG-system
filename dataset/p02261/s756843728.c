#include<stdio.h>

typedef struct{
  char suit;
  int num;
}Card;

void swap(Card *x, Card *y)
{
  Card tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int bubbleSort(Card *A, int N) // N 個の要素を含む 0-オリジンの配列 A
{
  int count = 0;

  int flag = 1; // 逆の隣接要素が存在する
  while(flag){
    flag = 0;
    int j = N-1;
    while(j >= 1){
      if (A[j].num < A[j-1].num) {
        swap(&A[j], &A[j-1]);
        flag = 1;
        count++;
      }
      j--;
    }
  }
  return count;
}

int selectionSort(Card *A, int N) // N個の要素を含む0-オリジンの配列A
{
  int minj, tmp;
  int count = 0;
  
  for(int i=0; i<N; i++){
    minj = i;
    for(int j=i; j<N; j++){
      if (A[j].num < A[minj].num)
        minj = j;
    }
    if (i != minj) {
      swap(&A[i], &A[minj]);
      count++;
    }
  }

  return count;
}

int main(void)
{
  Card A[36], B[36];
  int N, i;
  
  int count;
  
  scanf("%d",&N);
  for(i=0;i<N;i++) {
    scanf(" %c%d", &A[i].suit, &A[i].num);//配列読み込み
    B[i] = A[i];
  }    

  count = bubbleSort(A, N);

  for (int i = 0; i< N-1; i++)
    printf("%c%d ", A[i].suit, A[i].num);
  printf("%c%d\n", A[N-1].suit, A[N-1].num);
  printf("Stable\n");

  count = selectionSort(B, N);

  for (int i = 0; i< N-1; i++)
    printf("%c%d ", B[i].suit, B[i].num);
  printf("%c%d\n", B[N-1].suit, B[N-1].num);

  int flag = 0;
  for(i=0; i<N; i++){
    if (A[i].suit != B[i].suit) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    printf("Stable\n");
  }else {
    printf("Not stable\n");
  }
  
  return 0;
}

  

