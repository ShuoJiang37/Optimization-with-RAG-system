#include <stdio.h>

typedef struct {
  char suit;
  int num;
  int id;
} Card;

void bubble ( Card a[], int N );
void selection( Card b[], int N );

void swap ( Card *x, Card *y ) {
  Card temp = *y;
  *y = *x;
  *x = temp;
}

void trace ( Card x[], int N ) {
  int f = 0;
  char ns[] = "Not stable"; char s[] = "Stable";
  for ( int i = 0; i < N ; i++ ) {
    printf ( "%c", x[i].suit );
    printf ( "%d", x[i].num );
    if ( x[i].num == x[i+1].num && x[i].id > x[i+1].id ) f = 1;
    if ( i == N - 1 ) break;
    printf( " " );
  }
  putchar ( '\n' );
  printf ( "%s\n", f ? ns : s );
}

void bubble ( Card a[], int N ) {
  for ( int i = 0; i < N - 1; i++ ) {
    for (int j = N - 1; j > i ; j-- ) {
      if ( a[j].num < a[j-1].num ) {
        swap ( &a[j], &a[j-1] );
      }
    }
  }
  trace ( a, N );
}

void selection ( Card b[], int N ) {
  for ( int i = 0; i < N - 1; i++ ) {
    int minj = i;
    for ( int j = i; j < N; j++ ) {
      if ( b[j].num < b[minj].num ) {
        minj = j;
      }
    }
    swap ( &b[minj], &b[i] );
  }
  trace ( b, N );
}

int main ( void ) {
  Card a[36], b[36];
  int i, N;
  scanf ( "%d", &N );
  for ( i = 0; i < N; i++ ) {
    scanf ( " %c%d", &a[i].suit, &a[i].num );
    a[i].id = i;
    b[i] = a[i];
  }

  bubble ( a, N );
  selection ( b, N );
}

