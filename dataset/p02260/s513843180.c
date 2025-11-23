/* Sort I - Selection Sort */

#include <stdio.h>

int main( void )
{
  int N, i, j;
  scanf( "%d", &N );

  int a[N];
  for ( i = 0; i < N; i++ )
    scanf( "%d", &a[i] );

  int swapCount = 0;
  for ( i = 0; i < N; i++ ) {
    int mini = i;
    for ( j = i; j < N; j++ )
      if ( a[j] < a[mini] )
        mini = j;
    if ( i != mini ) {
      int tmp;
      tmp = a[i];
      a[i] = a[mini];
      a[mini] = tmp;
      swapCount++;
    }
  }

  for( i = 0; i < N - 1; i++ )
    printf( "%d ", a[i] );
  printf( "%d\n", a[N - 1] );
  printf( "%d\n", swapCount );

  return 0;
}