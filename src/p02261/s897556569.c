#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char simbol;
  int value;
}CARD;

int isStable(CARD *, CARD *, int);

int main(){
  int i, j, minj, N;

  CARD temp, C_bubble[36], C_select[36], C_store[36];
  
  scanf("%d", &N);
  if(N >= 1 && N <= 36){
    for(i = 0; i < N; i++){
      scanf(" %c", &C_bubble[i].simbol);
      scanf("%d", &C_bubble[i].value);
      C_select[i] = C_bubble[i];
      C_store[i] = C_bubble[i];
    }
      
    //BubbleSort
    for(i = 0; i < N; i++){
      for(j = N-1; j > i; j--){
	if(C_bubble[j].value < C_bubble[j-1].value){
	  temp = C_bubble[j];
	  C_bubble[j] = C_bubble[j-1];
	  C_bubble[j-1] = temp;
	}
      }
    }
    
    for(j = 0; j < N; j++){
      if(j != N-1) printf("%c%d ", C_bubble[j].simbol, C_bubble[j].value);
      else printf("%c%d\n", C_bubble[j].simbol, C_bubble[j].value);
    }
    if(isStable(&C_store[0], &C_bubble[0], N) == 1)
      printf("Stable\n");
    else
      printf("Not stable\n");
    
    //SelectionSort
    for(i = 0; i < N; i++){
      minj = i;
      for(j = i; j < N; j++){
	if (C_select[j].value < C_select[minj].value)
	  minj = j;
      }
      if(i != minj){
	temp = C_select[i];
	C_select[i] = C_select[minj];
	C_select[minj] = temp;
      }
    }
    for(i = 0; i < N; i++){
      if(i != N-1) printf("%c%d ", C_select[i].simbol, C_select[i].value);
      else printf("%c%d\n", C_select[i].simbol, C_select[i].value);
    }
    if(isStable(&C_store[0], &C_select[0], N) == 1)
      printf("Stable\n");
    else
      printf("Not stable\n");
  }
  return 0;
}

int isStable(CARD *in, CARD *out, int N){
  int i, j, a, b;
  for(i=0; i < N; i++)
    for(j = i+1;j < N; j++)
      for(a = 0; a < N; a++)
	for( b = a+1; b < N; b++)
	  if(in[i].value == in[j].value && in[i].simbol == out[b].simbol && in[j].simbol == out[a].simbol && in[i].value == out[b].value && in[j].value == out[a].value)
	    return 0;
  return 1;
}

