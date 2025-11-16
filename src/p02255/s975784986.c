/*s1190073  Rina Sato,
File name: prog1a.c,
2012 4/18(Wed),
This is a sort program.*/

#include<stdio.h>
int main(void){
  int j,i,N,A[100],key;
  scanf("%d",&N);
  for(j = 0 ; j < N ; j++){
    scanf("%d",&A[j]);
    printf("%d",A[j]);
    
    /*make space on each number*/
    if(j < N-1){ 
      printf(" ");
    }
  }
  printf("\n");

  for(j = 1 ; j < N ;j++){
    key = A[j];
    /* insert A[j] into the sorted sequence A[1,...,j-1] */
    i = j - 1;
    while(A[i] > 0 && A[i] > key){
      A[i+1] = A[i];
      i = i - 1;
    }
    A[i+1] = key;
    for(i = 0 ; i < N ; i++){
      printf("%d",A[i]);
      if(i < N-1){
	printf(" ");
      }
    }     
    printf("\n");
  }
  return 0;
}