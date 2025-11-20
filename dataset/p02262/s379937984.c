#include<stdio.h>

int makeg( int n )
{
  int k = 1 ;
  int i ;
  for ( i = 0 ; i < n ; i++) {
    if ( k > n ) break ;
    k = 3 * k + 1 ;
  }
  return i ;
}

void shellsort( int n, int a[] )
{
  int m = makeg(n) ;
  int g[20] ;
  int k = 1 ;
  for (int i = 0 ; i < m ; i++) {
    g[i] = k ;
    k = 3 * k + 1 ;
  }

  int ans = 0 ;
  for( int i = m-1 ; i >= 0 ; i-- ){
    int gg = g[i] ;
    for (int j = gg; j < n; j++) {
      int v = a[j] ; // sort対象
      int l = j -gg ;
      while( l >= 0 && a[l] > v ){
        a[l+gg] = a[l] ;
        l = l - gg ;
        ans++ ;
      }
      a[l+gg] = v ;
    }
  }

  printf("%d\n", m) ;
  for (int i = m-1; i > 0 ; i--) {
    printf("%d ", g[i]) ;
  }
  printf("%d\n", g[0]) ;
  printf("%d\n", ans) ;

  for (int i = 0; i < n ; i++) {
    printf("%d\n", a[i] ) ;
  }
}

int main()
{
  int n ;
  scanf("%d",&n) ;

  int a[n] ;
  for (int i = 0; i < n ; i++){
    scanf("%d",&a[i]) ;
  }

  shellsort( n, a ) ;

  return 0;
}

