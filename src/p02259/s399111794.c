/*s1190073  Rina Sato
File name: prog2a.c
This program is BubbleSort program.
*/

#include<stdio.h>
int main(void){
  int N,A[100],i,j,count=0,temp=0;
  
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }

  /*compare neighbor figures*/
  for(i = 0 ; i < N ; i++){
    for(j = N-1 ; j > i ; j--){
      if(A[j] < A[j-1]){ /*If left figure is smaller than right figure, change places*/
	temp = A[j]; 
	A[j] = A[j-1];
	A[j-1] = temp;
	count++; /*count a number of exchange*/
      }
    }
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