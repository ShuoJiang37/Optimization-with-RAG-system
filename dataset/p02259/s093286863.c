#include<stdio.h>

int main()
{
  
  int i,j,x,count=0,N,flag;
  int A[100];

  scanf("%d",&N);
  
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  
  flag = 1;

  while(flag){
    flag = 0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	x = A[j];
	A[j] = A[j-1];
	A[j-1] = x;
	flag = 1;
	count++;
      }
    }
  }
  
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i != N-1) printf(" ");   
  }
  
  printf("\n");
  
  printf("%d\n",count);
  
  return 0;
}