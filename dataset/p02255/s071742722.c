#include <stdio.h>
#include <stdlib.h>
int main(){
  int *A,N,i,j,v,n;
  scanf("%d",&N);

  if(N<1||100<N)exit(1);

  A=(int*)malloc(N*sizeof(int));
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(n=0;n<N;n++){
    printf("%d",A[n]);
    if(n<N-1)printf(" ");
  }
  printf("\n");
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(n=0;n<N;n++){
      printf("%d",A[n]);
      if(n<N-1)printf(" ");
    }
    printf("\n");
  }  
  free(A);
  return 0;
}