#include <stdio.h>
#include <stdlib.h>

struct C {
  char a;
  int b;
};

int N;

int isStable(struct C b[], struct C s[]){
  int i;

  for(i = 0; i < N; i++){
    if(b[i].a != s[i].a)  return 0;
  }
  return 1;
}

void BubbleSort(struct C c[]){ //??????
  int i, j;
  struct C k;

  for(i = 0; i < N; i++){
    for(j = N-1; j >= i+1; j--){
      if(c[j].b < c[j-1].b){
	k = c[j];
	c[j] = c[j-1];
	c[j-1] = k;
      }
    }
  }
}

void SelectionSort(struct C c[]){ //?????????
  int i, j, minj;
  struct C k;

  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(c[j].b < c[minj].b)  minj = j;
    }
    k = c[i];
    c[i] = c[minj];
    c[minj] = k;
  }
}

int main()
{
  struct C s[36], b[36];
  char x[2];
  int i;
  
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%s", x);
    b[i].a = x[0];
    b[i].b = atoi(&x[1]);
  }
  for(i = 0; i < N; i++)  s[i] = b[i];
  BubbleSort(b);
  SelectionSort(s);

  for(i = 0; i < N; i++){
    printf("%c%d", b[i].a, b[i].b);
    if(i < N - 1) printf(" ");
    else printf("\n");
  }
  printf("Stable\n");

  for(i = 0; i < N; i++){
    printf("%c%d", s[i].a, s[i].b);
    if(i < N - 1) printf(" ");
    else printf("\n");
  }
  if(isStable(b, s)) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}