#include<stdio.h>
int insertionSort( int A[], int n, int g, int *cnt ){

  int i,j,v;
  
  for ( i = g ; i < n ; i++ ){

    v = A[i];
    j = i - g;
    
    while ( j >= 0 && A[j] > v ){
      A[ j + g ] = A[j];
      j = j - g;
      *cnt += 1;
    }

    A[ j + g ] = v;
    
  }

  return 0;

}
int main(){

  int i,k,m,n,A[1000001],G[21],cnt;

  cnt = 0;

  scanf("%d", &n );

  for ( i = 0 ; i < n ; i++ ){
    scanf("%d", &A[i] );
  }

  m = 1;
  k = 1;
  while ( k * 2 < n ){
    k *= 2;
    m += 1;
  }

  for ( i = 0 ; i < m ; i++ ){
    if ( i == 0 ) {
      G[i] = k;
    } else {
      G[i] = G[ i - 1 ] / 2;
    }
  }

  for ( i = 0 ; i < m ; i++ ){
    insertionSort( A, n, G[i], &cnt );
  }

  printf("%d\n", m );

  for ( i = 0 ; i < m ; i++ ){
    if ( i < m - 1 ) {
      printf("%d ", G[i] );
    } else {
      printf("%d\n", G[i] );
    }
  }

  printf("%d\n", cnt );

  for ( i = 0 ; i < n ; i++ ){
    printf("%d\n", A[i] );
  }

  return 0;

}