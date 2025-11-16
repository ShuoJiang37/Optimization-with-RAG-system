#include <stdio.h>
#include <stdlib.h>
#define N 36

typedef struct{
  int a;
  char c;
}Card;

int decision(int, Card *);

Card C[N];

int main(){

  int i, j;
  int n, minv;
  Card CB[N], CS[N], TMP;
  char kamase[2];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s", kamase);

    C[i].a = atoi(&kamase[1]);
    C[i].c = kamase[0];

    CB[i] = C[i];
    CS[i] = C[i];
  }


  //Bubble
  for(i = 0; i < n; i++){
    for(j = n - 1; j > i; j--){//
      if(CB[j].a < CB[j - 1].a){
	TMP = CB[j];
	CB[j] = CB[j - 1];
	CB[j - 1] = TMP;
      }

    }

    }

  //Sellect
  for(i = 0; i < n; i++){
    minv = i;

    for(j = i; j < n; j++){
      if(CS[j].a < CS[minv].a){
	minv = j;
      }

    }

    TMP = CS[i];
    CS[i] = CS[minv];
    CS[minv] = TMP;
    }

  for(i = 0; i < n; i++){
    printf("%c%d", CB[i].c, CB[i].a);
    if(i < n - 1) printf(" ");
  }

  if(decision(n, &CB[0]) == 0) printf("\nStable\n");
  else printf("\nNot stable\n");

  for(i = 0; i < n; i++){
    printf("%c%d",CS[i].c, CS[i].a);
    if(i < n - 1) printf(" ");
  }

  if(decision(n, &CS[0]) == 0) printf("\nStable\n");
  else printf("\nNot stable\n");

  return 0;
}

int decision(int n, Card *CC){

  int i, j;
  Card TMP;
  
  for(i = 0; i < n - 1; i++){
    TMP = CC[i];
    
    if(TMP.a == CC[i + 1].a){

      for(j = 0; j < n; j++){

	if(C[j].c == TMP.c && C[j].a == TMP.a) break;
	if(C[j].c == CC[i + 1].c && C[j].a == CC[i + 1].a) return 1;

      }
      
    }
    
  }

  return 0;
}