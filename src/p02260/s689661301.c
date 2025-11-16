/*s1190073  Rina Sato
File name: prog2b.c
This program is Selection Sort program.*/

#include<stdio.h>
int main(void){
  int A[100],temp=0,count=0,mini=0,N,i,j;
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }
  
  /*compare figures*/
  for(i = 0 ; i < N ; i++){
    mini = i;
    for(j = i+1 ; j < N ; j++){
      if(A[j] < A[mini]){ /*find the smallest figure from A[i+1] to A[N-1]*/ 
	mini = j;
      }         
    }
    temp = A[i];    /*exchange A[i] for A[mini]*/
    A[i] = A[mini];
    A[mini] = temp;
    if(A[i] != A[mini]) count++; /*count a number of exchange*/
  }
  
  for(j = 0 ; j < N ; j++){
    printf("%d",A[j]);
    if(j < N-1){ /*make space between figures*/
      printf(" ");
    }
  }
  printf("\n%d\n",count);
  return 0;
}