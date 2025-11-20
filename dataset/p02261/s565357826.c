#include <stdio.h>
#include <string.h>
#define M 36

typedef struct {
  char mark;
  int value;
} Card;

void BubbleSort(Card *, int);
void SelectionSort(Card *, int);
void disply(Card *, int);
int isStable(Card *, Card *, int);

int main()
{
  Card c1[M+1], c2[M+1];
  int i, N;

  scanf("%d", &N);

//文字列と数字でそれぞれ格納
  for( i = 0 ; i < N ; i++ ){
    scanf(" %c%d", &c1[i].mark, &c1[i].value);
  }

//BubbleSortとSelectionSortで比較するためにもう一つの配列に格納する
  for( i = 0 ; i < N ; i++ ) c2[i] = c1[i];

  BubbleSort(c1, N);
  disply(c1, N);
  //BubbleSortは常に安定なソートとなるため比較不要
  printf("Stable\n");

  SelectionSort(c2, N);
  disply(c2, N);

//c1に安定ソートされた文字列数字が格納されているためそれと比較し、同じでなければNot Stable
  if( isStable(c1, c2, N) == 0 ) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}
void BubbleSort(Card c1[], int N)
{
  int i, j;
  Card t;

  for( i = 0 ; i < N ; i++ ){
    for( j = N-1 ; j > i ; j-- ){
      if( c1[j].value < c1[j-1].value ){
        t = c1[j];
        c1[j] = c1[j-1];
        c1[j-1] = t;
      }
    }
  }
}

void SelectionSort(Card c2[], int N)
{
  int i, j, minj;
  Card t;

  for( i = 0 ; i < N ; i++ ){
    minj = i;
    for( j = i ; j < N ; j++ ){
      if( c2[j].value < c2[minj].value ) minj = j;
    }
    t = c2[i];
    c2[i] = c2[minj];
    c2[minj] = t;
  }
}

void disply(Card c[], int N)
{
  int i;

  for( i = 0 ; i < N ; i++ ){
    if( i > 0 ) printf(" ");
    printf("%c%d", c[i].mark, c[i].value);
  }
  printf("\n");
}

int isStable(Card c1[], Card c2[], int N)
{
  int i;

  for( i = 0 ; i < N ; i++ )
  if( c1[i].mark != c2[i].mark ) return 1;

  return 0;
}

