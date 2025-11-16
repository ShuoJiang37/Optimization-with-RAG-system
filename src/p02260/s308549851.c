#include<stdio.h>

int main()
{
  
  int i,minj,j,tmp,count=0,N;
  int A[100];

  scanf("%d",&N);
  
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  
 
  for(i=0;i<=N-1;i++){
    minj = i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj])minj = j;
    }
    if(i!=minj){
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      count++;    
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