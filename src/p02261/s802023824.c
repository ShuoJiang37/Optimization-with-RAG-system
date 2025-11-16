/* Sort I - Stable Sort */

#include <stdio.h>

void swap( char* a, char* b )
{
  char tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main( void )
{
  int n, i, j;
  scanf( "%d\n", &n );

  char bE[n], bA[n];
  for ( i = 0; i < n; i++ )
    scanf( " %c%c", &bE[i], &bA[i] );

  char sE[n], sA[n];
  for ( i = 0; i < n; i++ ) {
    sE[i] = bE[i];
    sA[i] = bA[i];
  }

  /* BubbleSort */
  for ( i = 0; i < n; i++ ) {
    for ( j = n - 1; j > i; j-- ) {
      if ( bA[j] < bA[j-1] ) {
        swap( &bA[j], &bA[j-1] );
        swap( &bE[j], &bE[j-1] );
      }
    }
  }

  /* SelectionSort */
  for ( i = 0; i < n; i++ ) {
    int minj = i;
    for ( j = i; j < n; j++ ) {
      if ( sA[j] < sA[minj] )
        minj = j;
    }
    swap( &sA[i], &sA[minj] );
    swap( &sE[i], &sE[minj] );
  }


  for ( i = 0; i < n - 1; i++ )
    printf( "%c%c ", bE[i], bA[i] );
  printf( "%c%c\n", bE[n-1], bA[n-1] );
  printf( "Stable\n" );

  for ( i = 0; i < n - 1; i++ )
    printf( "%c%c ", sE[i], sA[i] );
  printf( "%c%c\n", sE[n-1], sA[n-1] );


  int stablep = 1;
  for ( i = 0; i < n; i++ ) {
    if ( bE[i] != sE[i] ) {
      stablep = 0;
      break;
    }
  }

  if ( stablep )
    printf( "Stable\n" );
  else
    printf( "Not stable\n" );

  return 0;
}