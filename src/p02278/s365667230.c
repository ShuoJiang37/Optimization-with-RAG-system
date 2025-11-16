#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEF_ELEM_MAX 1000
#define DEF_VMAX 10000
#ifndef min
#define min(a, b)            (((a) < (b)) ? (a) : (b))
#endif
int A[DEF_ELEM_MAX];
int B[DEF_ELEM_MAX];
int VD[DEF_ELEM_MAX];
int N;

int search(int x)
{
  int i;
  for ( i = 0 ; i < N ; i++ ) {
    if ( A[i] == x ) {
      break;
    }
  }
  return i;
}
 
int int_sort( const void * a , const void * b ){
  int p = *( int * )a;
  int q = *( int * )b;
  if( p < q ) {
    return -1;
  }  else if( p == q  ) {
    return 0;
  }
  return 1;
}

int sillysort( void ){
  int s,cost=0,i,amin,sum,n,x;
  s = B[0];
  for ( i = 0 ; i < N ; i++ ) {
    x = i;
    n = sum = 0;
    amin = DEF_VMAX;
    while ( VD[x] == 0 ) {
      VD[x] = 1;
            n++;
            sum += A[x];
            amin = min(amin, A[x]);
            x = search(B[x]);
        }
        if ( n > 1 ) { 
            cost += min(sum+(n-2)*amin, sum+amin+(n+1)*s);
        }
    }
    return cost;
}

int main(void){
  int i,ans;
    scanf("%d", &N);
    for ( i = 0 ; i < N ; i++ ) {
        scanf("%d", &A[i] );
        B[i] = A[i];
    }
    qsort(B, N , sizeof( int ), int_sort );
    ans = sillysort();
    printf("%d\n", ans);
    return 0;
}