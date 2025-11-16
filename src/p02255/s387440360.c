#include <stdio.h>

int main() {

  int i,j,k,v,N,A[100],count=0;

  while(1) {
  scanf("%d",&N);
  if(N<1 || 100<N) printf("error\n");
  else break;
  }
  
  while(1) {
    for(i=0; i<N; i++) {
      scanf("%d",&A[i]);
      if(A[i]<0 || 1000<A[i]) count++;
    }
    if(count == 0) break;
    else printf("error\n");
    count =0;
  }
  
  for(i=0; i<N; i++){
    k = i;
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k=0; k<N; k++){
      printf("%d",A[k]);
      if(k == N-1) {
	printf("\n");
	break;
      }
      printf(" ");
    }
  }
  return 0;
}