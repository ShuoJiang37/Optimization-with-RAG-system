#include <stdio.h>
int main(){
  int N,a,i,j,k,minj;
  int count=0;
  int A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    if(A[i]!=A[minj]){
        a=A[i];
        A[i]=A[minj];
        A[minj]=a;
        count++;
      }
  }
  for(k=0;k<N;k++){
    printf("%d",A[k]);
    if(k<N-1)printf(" ");
  }
  printf("\n");
  printf("%d",count);
  printf("\n");
}



