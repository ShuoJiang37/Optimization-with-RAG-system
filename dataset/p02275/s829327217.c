
#include<stdio.h>

int A[2000001],B[1000001],C[2000001],i,j,n;

int main() {
  scanf("%d",&n);

  for(i=1;i<n+1;i++){
    scanf("%d",&A[i]);
  }
   
  for(j=0;j<100000;j++){
    B[j]=0;
    C[j]=0;
  }
  for(i=1;i<n+1;i++){
    B[A[i]]++;
  }

  for(i=1;i<10001;i++)B[i]+=B[i-1];

  /*
  for(i=1;i<n+1;i++)printf("%d ",A[i]);
  printf("\n");
  for(i=0;i<10;i++)printf("%d ",B[i]);
  printf("\n");
  */

  for(i=n;i>0;i--){
    C[B[A[i]]]=A[i];
    B[A[i]]--;
  }

  for(i=1;i<n+1;i++){
 
    if(i<n) printf("%d ",C[i]);
    else  printf("%d\n",C[i]);
    }
  return 0;
}