#include <stdio.h>
#define N 100;

int main(){
  int A[1000],n,i,j,v;

  scanf("%d",&n);
  for( i=0 ; i<n ; i++){
    scanf("%d",&A[i]);
    printf("%d",A[i]);
    if(i < n-1)printf(" ");
  }
  printf("\n");

  for( i=1 ; i<n ; i++){
    v = A[i];
    j = i-1;
    while( j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    for( v=0 ; v<n ; v++){
      printf("%d",A[v]);
      if(v < n-1)printf(" ");
    }
    printf("\n");
  }
  return 0;
}