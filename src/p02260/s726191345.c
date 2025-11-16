#include <stdio.h>
#define N 100

int main(){
  int i,j,s,length,count=0,minj;
  int A[N];
  
  scanf("%d", &length);
  for( i=0 ; i<length ; i++ ){
    scanf("%d", &A[i]);
  }
  
  for( i=0 ; i<length ; i++ ){
    minj = i;
    for( j=i ; j<length ; j++ ){
      if( A[j] < A[minj] ){
	minj = j;
      }
    }
    if( i<minj ){
      s = A[i];
      A[i] = A[minj];
      A[minj] = s;
      count++; 
    }
  }
  
  for( i=0 ; i<length ; i++ ){
    printf("%d", A[i]);
    if( i!=length-1 ) printf(" ");
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}