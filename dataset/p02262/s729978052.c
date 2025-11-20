#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int insertion_sort(int * a, int length, int g){
  int count = 0;
  for( int i = 0; i < length; i ++ ){
    int v = a[ i ];
    int j = i - g;
    while( j >= 0 && a[ j ] > v ){
      a[ j + g ] = a[ j ];
      j = j - g;
      count ++;
    }
    a[ j + g ] = v;
  }
  return count;
}

void shell( int *a, int length ){
  int count = 0;
  int m = length / 3 + 1;
  int *g = ( int * )malloc( m * sizeof( int ) );
  int k = 3, i;
  for( i = 0; i < m && (k - 1)/2 <= length; i ++ ){
    g[ i ] = (k - 1)/2;
    k *= 3;
  }
  m = i;
  printf("%d\n", m );
  for( i = m - 1; i > 0; i -- )
    printf("%d ", g[ i ] );
  printf("%d\n", g[ i ] );

  for( i = m - 1; i >= 0; i -- )
    count += insertion_sort( a, length, g[ i ] );

  printf("%d\n", count );
}

int main( void ){
  int n;
  scanf("%d\n", &n );

  int *a = ( int * )malloc( n * sizeof( int ) );
  for( int i = 0; i < n; i ++ )
    scanf("%d\n", a + i );

  shell( a, n );
  for( int i = 0; i < n ; i ++ )
    printf("%d\n", a[ i ] );

  return 0;
}
