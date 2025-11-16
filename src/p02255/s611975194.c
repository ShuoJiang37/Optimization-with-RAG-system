#include<stdio.h>


int main(){
  int i,j,k,tmp,N,A[100];


  scanf("%d", &N);
  for(i = 0;i<N;i++) scanf("%d", &A[i]);

  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");



for(i=1;i<N;i++){

  tmp=A[i];
  j=i-1;
  while(j>=0 && A[j]> tmp){

    A[j+1]=A[j];

    j--;
  }

  A[j + 1]=tmp;

 for(k=0;k<N;k++){
    if(k>0)printf(" ");
    printf("%d",A[k]);
  }
  printf("\n");
 }

  
  return 0;
}

