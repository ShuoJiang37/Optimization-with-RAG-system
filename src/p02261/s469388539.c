/*s1190073  Rina Sato
File name: prog_2c.c
This is a program which confirm stability of Bubble Sort and Selection Sort. 
*/

#include<stdio.h>
int main(void){
  int N,i,j,n,mini=0,S=0,J=0,stability=0;
  int figure1[36],figure2[36],order1[36],order2[36];
  char symbol1[36],symbol2[36],K;
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf(" %c%d",&symbol1[i],&figure1[i]);
  }
  for(n = 0 ; n < N ; n++){ /*order of cars*/
    order1[n] = n;
  }
  for(i = 0 ; i < N ; i++){ /*_2 is for Selection Sort,_1 is for Bubble Sort.*/  
    figure2[i] = figure1[i];
    order2[i] = order1[i];
    symbol2[i] = symbol1[i];
  }
  /*BubbleSort*/
  for(i = 0 ; i < N ; i++){ 
    for(j = N-1 ; j > i ; j--){
      if(figure1[j] < figure1[j-1]){ /*exchange _[j] for _[j-1]*/
	S = figure1[j]; 
	K = symbol1[j];
	J = order1[j];

	figure1[j] = figure1[j-1];
	symbol1[j] = symbol1[j-1];
	order1[j] = order1[j-1];

	figure1[j-1] = S;
	symbol1[j-1] = K;
	order1[j-1] = J;
      }
    }
  }
  for(i = 0 ; i < N ; i++){
    printf("%c%d",symbol1[i],figure1[i]);
    if(i < N-1){ /*make space between figures*/
      printf(" ");
      if(figure1[i] == figure1[i+1]){
	if(order1[i] > order1[i+1]){ /*If order is strange, stability is 1.*/
	  stability = 1;
	}
      } 
    }
    else printf("\n");
  }
  if(stability == 1){
    printf("Not stable\n");
  } else {
    printf("Stable\n");
  }
  stability = 0;
  
  /*SelectionSort*/
  for(i = 0 ; i < N ; i++){
    mini = i;
    for(j = i+1 ; j < N ; j++){
      if(figure2[j] < figure2[mini]){ /*find the smallest figure from figure2[i+1] to 
                                                                              figure[N-1]*/
	mini = j;
      }
    }
    S = figure2[i]; /*exchange _[i] for _[mini]*/
    K = symbol2[i];
    J = order2[i];

    figure2[i] = figure2[mini];
    symbol2[i] = symbol2[mini];
    order2[i] = order2[mini];

    figure2[mini] = S;
    symbol2[mini] = K;
    order2[mini] = J;
  }
  for(i = 0 ; i < N ; i++){
    printf("%c%d",symbol2[i],figure2[i]);
    if(i < N-1){
      printf(" ");
      if(figure2[i] == figure2[i+1]){
	if(order2[i] > order2[i+1]){
	  stability = 1;
	}
      } 
    }
    else printf("\n");
  }
  if(stability == 1){
    printf("Not stable\n");
  } else {
    printf("Stable\n");
  }
  return 0;
}