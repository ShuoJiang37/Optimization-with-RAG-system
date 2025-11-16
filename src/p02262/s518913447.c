#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int c = 0;


void insertS(int *A,int n,int g){
  int i,j;
  int k;
  for( i = g ; i < n ; i++){
    j = i;
    k = A[i];
    while( 0 <= j - g){
      if( A[j-g] <= k) break;
      A[j] = A[j-g];
      j -= g;
      c++;
    }
   A[j] = k;
 }
}


int main(){
  int n;
  int i,j;
  int *A;
  int G[20];



  scanf("%d", &n);
  A = malloc(n * sizeof(int));
  for( i = 0 ; i < n ; i++ ) scanf("%d", &A[i]);

  int m = 0;
  G[0] = 0;
  while(1){
    if( n < 3*G[m]+1) break;
    G[m+1] = 3*G[m] + 1;
    m++;
 }

 for( i = m ; i > 0 ; i--) insertS(A,n,G[i]);

  printf("%d\n", m);
  for( i = m ; i >= 1 ; i-- ) printf("%d ", G[i]);
  printf("\n");
  printf("%d\n", c);

  for( i = 0 ; i < n ; i++ ) printf("%d\n", A[i]);

  return 0;
}

