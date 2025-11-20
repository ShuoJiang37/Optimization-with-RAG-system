#include <stdio.h>
int main(){
  int N,a,i,j,k,count=0;
  int A[100];
  int flag;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  flag=1;
  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j] < A[j-1]){
	a=A[j];
	A[j]=A[j-1];
	A[j-1]=a;
	flag=1;
      count++;
      }
    }
    }
  for(k=0;k<N;k++){
    printf("%d",A[k]);
    if(k<N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
}

