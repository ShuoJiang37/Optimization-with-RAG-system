#include <stdio.h>

int main(){
  int i, j, N, A[100], flag, temp, count=0;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  flag=1;
  i=0;
  while(flag){
    flag=0;
    for(j=N-1; j>=i+1; j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	count++;
      }
      flag=1;
    }
    i++; 
  }
  for(i=0;i<N-1;i++){
    printf("%d ", A[i]);
  }
   printf("%d", A[N-1]);
  printf("\n%d\n",count);
  return 0;
}