#include <stdio.h>
#include <stdlib.h>
int main(){
  int flag,i,j,size,n,tmp,c=0;
  int *A;
  scanf("%d",&size);
  A = (int *)malloc(size * sizeof(int));
  flag = 1;
  for(i=0;i<size;i++){
    scanf("%d",&A[i]);
  }
  while(flag==1){
    flag = 0;
    for(j=size-1; j>=1; j--){
      if(A[j] < A[j-1]){
	tmp = A[j-1];
	A[j-1] = A[j];
	A[j] = tmp;
	flag = 1;
	c++;
      }
    }
  }
  if(size != 1){
  for(i=0;i<size-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",c);
    }
  
  if(size ==1){
    printf("%d\n%d\n",A[0],c);
  }
  return 0;
}

