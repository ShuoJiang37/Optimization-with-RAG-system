#include<stdio.h>

int main()
{
  int i,j,v;
  int A[100],N;
  
  scanf("%d",&N);/*number of value*/
  for(i=0; i<N; ++i){
    scanf("%d",&A[i]);/*input number*/
    printf("%d",A[i]);
    if(i!=N-1)printf(" ");
 
 }
  printf("\n");

  for(i=1; i<N; i++){/*sort*/
    v=A[i];
    /*insert A[j] into the sorted sequence A[1,....,i-1]*/
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      
    }
    A[j+1]=v;
    
    for(j=0;j<N;j++){/*output*/
      printf("%d",A[j]);
      if(j!=N-1)printf(" ");
    }
    printf("\n");
  }
  return 0;
}