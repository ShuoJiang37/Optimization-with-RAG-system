#include<stdio.h>
#define N 36

struct card{
  char a;
  char b;
};

main(){
  struct card A1[N], A2[N], a;
  int i, j, n, min;
  
  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf(" %c%c", &A1[i].a, &A1[i].b);
    A2[i] = A1[i];
  }

  for(i = 0; i < n; i++){
    for(j = n-1; j > i; j--){
      if(A1[j].b < A1[j-1].b){
	a = A1[j];
	A1[j] = A1[j-1];
	A1[j-1] = a;
      }
    }
  }

  for(i = 0; i < n; i++){
    printf("%c%c", A1[i].a, A1[i].b);
    if(i == n-1) break;
    printf(" ");
  }

  printf("\nStable\n");

  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(A2[j].b < A2[min].b)
	min = j;
    }
    if(A2[i].b != A2[min].b){
      a = A2[i];
      A2[i] = A2[min];
      A2[min] = a;
    }
  }

  for(i = 0; i < n; i++){
    printf("%c%c", A2[i].a, A2[i].b);
    if(i == n-1) break;
    printf(" ");
  }

  for(i = 0; i < n; i++){
    if(A1[i].b == A2[i].b){
      if(A1[i].a == A2[i].a)
	j = 1;
      else {
	j = 0;
	break;
      }
    }
  }

  if(j == 1)
    printf("\nStable\n");
  else printf("\nNot stable\n");

  return 0;
}