#include <stdio.h>
#include <stdlib.h>
typedef struct Card_s{
  char suit;
  int value;
}Card;

void bubble( Card *a, int length ){
  for( int i = 0; i < length ; i ++ ){
    for( int j = length - 1 ; j > i; j -- ){
      if( a[j].value < a[ j - 1 ].value ){
        Card tmp = a[ j ];
        a[ j ] = a[ j - 1 ];
        a[ j - 1 ] = tmp;
      }
    }
  }
}

void selection(Card * a, int length ){
  for( int i = 0; i < length; i ++ ){
    int mini = i;
    for( int j = i + 1; j < length ; j ++ ){
      if( a[ j ].value < a[ mini ].value )
        mini = j;
    }
    if( i != mini ){
      Card tmp = a[ mini ];
      a[ mini ] = a[ i ];
      a[ i ] = tmp;
    }
  }
}

int main( void ){
  int n;
  scanf("%d\n", &n );
  Card *a = ( Card * )malloc( n * sizeof( Card ) );
  Card *b = ( Card * )malloc( n * sizeof( Card ) );
  for( int i = 0; i < n; i ++ ){
    char suit;
    int value;
    scanf("%c%d ", &suit, &value );
    a[ i ].suit = suit;
    a[ i ].value = value;
    b[ i ].suit = suit;
    b[ i ].value = value;
  }
  bubble( a, n );
  selection( b, n);
  int is_stable = 1;
  for( int i = 0; i < n ; i ++ ){
    if( a[ i ].suit != b[ i ].suit )
      is_stable = 0;
  }
  for( int i = 0; i < n - 1; i ++ )
    printf("%c%d ", a[ i ].suit, a[ i ].value );
  printf("%c%d\nStable\n", a[ n - 1 ].suit, a[ n - 1 ].value );

  for( int i = 0; i < n - 1; i ++ )
    printf("%c%d ", b[ i ].suit, b[ i ].value );
  printf("%c%d\n", b[ n - 1 ].suit, b[ n - 1 ].value );
  if( is_stable )printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}






