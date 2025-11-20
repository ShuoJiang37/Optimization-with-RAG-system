#include <stdio.h>
#define N 101

int main(){

  int i,j,k,m,n;
  int A[N];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&A[i]);

  for(k=0;k<n;k++){
	  printf("%d",A[k]);
	  if(k==n-1){
	    printf("\n");
	  }else{ printf(" ");
	  }
  }

  for(i=1;i<n;i++){
    m=A[i];
    j=i-1;
    while(j>=0 && m<A[j]){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=m;
	
    for(k=0;k<n;k++){
	  printf("%d",A[k]);
	  if(k==n-1){
	    printf("\n");
	  }else{ printf(" ");
	  }
    }
  }
  return 0;
}