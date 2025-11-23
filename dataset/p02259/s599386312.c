#include <stdio.h>
int main(){
  int i,N,A[100],flag=1,tmp,count=0;
  scanf("%d",&N);
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  while(flag){
    flag = 0;
    for(i = N-1; i >= 1; i--){
      if(A[i] < A[i-1]){
	tmp = A[i];
	A[i] = A[i-1];
	A[i-1] = tmp;
	count++;
	flag = 1;
      }
    }
  }
  for(i = 0; i < N-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}