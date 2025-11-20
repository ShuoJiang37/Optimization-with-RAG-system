#include <stdio.h>

typedef struct {
  char c;
  int value;
} Card;

int main(){
  int N,n1,n2,i,j,minj,flag = 0;
  Card C[36],C1[36],C2[36],c;

  scanf("%d",&N);

  for(i=0; i < N; i++){
    scanf(" %c%d",&C[i].c,&C[i].value);
    C1[i] = C[i];
    C2[i] = C[i];
  }

  for(i=0; i < N; i++){
    for(j=N-1; j > i; j--){
      if(C1[j].value < C1[j-1].value){
	c = C1[j];
	C1[j] = C1[j-1];
	C1[j-1] = c;
      }
    }
  }

  for(i=0; i < N-1; i++){
    if(C1[i].value == C1[i+1].value){
      for(j=0; j < N; j++){
	if(C1[i].c == C[j].c && C1[i].value == C[j].value){
	  n1 = j;
	}
	if(C1[i+1].c == C[j].c && C1[i+1].value == C[j].value){
	  n2 = j;
	}
      }
      if(n1 > n2){
  	flag = 1;
      }
    }
  }

  for(i=0; i < N; i++){
    printf("%c%d",C1[i].c,C1[i].value);
    if(i != N-1){
      printf(" ");
    }
  }
  printf("\n");

  if(flag == 0){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  flag = 0;
  
  for(i=0; i < N; i++){
    minj = i;
    for(j=i; j < N; j++){
      if(C2[j].value < C2[minj].value){
	minj = j;
      }
    }
    c = C2[i];
    C2[i] = C2[minj];
    C2[minj] = c;
  }
  
  for(i=0; i < N-1; i++){
    if(C2[i].value == C2[i+1].value){
      for(j=0; j < N; j++){
	if(C2[i].c == C[j].c && C2[i].value == C[j].value){
	  n1 = j;
	}
	if(C2[i+1].c == C[j].c && C2[i+1].value == C[j].value){
	  n2 = j;
	}
      }
      if(n1 > n2){
  	flag = 1;
      }
    } 
  }
  
  for(i=0; i < N; i++){
    printf("%c%d",C2[i].c,C2[i].value);
    if(i != N-1){
      printf(" ");
    }
  }
  printf("\n");

  if(flag == 0){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  return 0;
}

