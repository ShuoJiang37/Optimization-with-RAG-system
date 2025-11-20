#include <stdio.h>
#include <string.h>

static const int MAX = 36;

typedef struct {
  char  s;
  short v;
} card;

void output( card *p, short n ) {
  short i;
  for ( i = 0; i < (n - 1); i++ ) {
    printf( "%c%d ", p[i].s, p[i].v );
  }
  printf( "%c%d\n", p[i].s, p[i].v );
}

void swap(card *a, card *b ) {
  card t;
  t = *a;
  *a = *b;
  *b = t;
}

short isStable( card *a, card *b, short n ) {
  short i, flag = 1;
  for( i = 0; i < n; i++ ) {
    if( (a[i].v == b[i].v) && (a[i].s != b[i].s) ) {
      return flag = 0;
    }
  }
  return flag;
}

void selectionSort( card *p, short n ) {
  short i, j, idx;
  for ( i = 0; i < n; i++ ) {
    idx = i;
    for ( j = i; j < n; j++ ) {
      if (p[j].v < p[idx].v) idx = j;
    }
    if ( idx != i ) swap( &p[i], &p[idx] );
  }
}

void bubbleSort( card *p, short n ) {
  short i, j;

  for( i = 1; i <= (n - 1); i++ ) {
    for ( j = (n - 1); j >= 1; j-- ) {
      if ( p[j].v < p[j - 1].v ) swap( &p[j], &p[j - 1] );
    }
  }
}

int main( void ) {
  short i, n;
  card c01[MAX + 1], c02[MAX + 1];

  scanf( "%d%*c", &n );
  for ( i = 0; i < n; i++ ) {
    scanf( "%c%d%*c", &c01[i].s, &c01[i].v );
    memcpy( &c02[i], &c01[i], sizeof(card) );
  }

  bubbleSort( c01, n );
  output( c01, n );
  printf( "Stable\n" );

  selectionSort( c02, n );
  output( c02, n );
  if ( isStable(c01,c02,n) )
    printf( "Stable\n" );
  else
    printf( "Not stable\n" );

  return 0;
}

