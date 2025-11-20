#include<stdio.h>

typedef struct{
  char mark;
  int number;
}Card;

int main(){
  int i, j, n, v = 0, min;
  Card B[36], S[36], C;
  char space;

  scanf("%d%c",&n, &space);

  for(i = 0; i < n; i++){
    if(i != n - 1) scanf("%c%d%c",&B[i].mark, &B[i].number, &space);
    else scanf("%c%d",&B[i].mark, &B[i].number);
  }

  for(i = 0; i < n; i++) S[i] = B[i];

  // Bubble
  for(i = 0; i < n; i++){
    for(j = n - 1; j > i; j--){
      if(B[j - 1].number > B[j].number){
      C = B[j];
      B[j] = B[j - 1];
      B[j - 1] = C;
      }
    }
  }
  
  for(i = 0; i < n; i++){
    printf("%c%d",B[i].mark, B[i].number);
    if(i != n - 1) printf(" ");
  }
  printf("\nStable\n");

  // Selection
  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(S[j].number < S[min].number) min = j;
    }

    if(i != min){
      C = S[min];
      S[min] = S[i];
      S[i] = C;
    }
    printf("%c%d",S[i].mark, S[i].number);
    if(i != n - 1) printf(" ");
  }
  printf("\n");

  // is prime
  for(i = 0; i < n; i++){
    if(B[i].mark != S[i].mark) v++;
  }
  if(v != 0) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}