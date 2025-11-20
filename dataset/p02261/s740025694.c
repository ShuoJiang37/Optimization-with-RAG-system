#include <stdio.h>
#include <string.h>
#define M 36

typedef struct {
  char suit;
  int value;
} Card;

void BubbleSort(Card *, int);
void SelectionSort(Card *, int);
void disply(Card *, int);
int isStable(Card *, Card *, int);

int main()
{
  Card A[M+1], B[M+1];
  int i, N;

  scanf("%d", &N);
  for( i = 0 ; i < N ; i++ ){
    scanf(" %c%d", &A[i].suit, &A[i].value);
  }
  for( i = 0 ; i < N ; i++ ) B[i] = A[i];

  BubbleSort(A, N);
  disply(A, N);
  printf("Stable\n");
  SelectionSort(B, N);
  disply(B, N);

  if( isStable(A, B, N) == 0 ) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

void BubbleSort(Card A[], int N)
{
  int i, j;
  Card t;

  for( i = 0 ; i < N ; i++ ){
    for( j = N-1 ; j > i ; j-- ){
      if( A[j].value < A[j-1].value ){
        t = A[j];
        A[j] = A[j-1];
        A[j-1] = t;
      }
    }
  }
}

void SelectionSort(Card B[], int N)
{
  int i, j, minj;
  Card t;

  for( i = 0 ; i < N ; i++ ){
    minj = i;
    for( j = i ; j < N ; j++ ){
      if( B[j].value < B[minj].value ) minj = j;
    }
    t = B[i];
    B[i] = B[minj];
    B[minj] = t;
  }
}

void disply(Card c[], int N)
{
  int i;

  for( i = 0 ; i < N ; i++ ){
    if( i > 0 ) printf(" ");
    printf("%c%d", c[i].suit, c[i].value);
  }
  printf("\n");
}

int isStable(Card A[], Card B[], int N)
{
  int i;

  for( i = 0 ; i < N ; i++ )
  if( A[i].suit != B[i].suit ) return 1;

  return 0;
}
