#include <stdio.h>

typedef struct{
  char s;
  int n;
} card;

void bubble(card c[], int N)
{
  int i, j;
  card x;
  
  for (i = 0; i < N; i++)
    for (j = N-1; j > i; j--)
      if (c[j].n < c[j-1].n){
	x = c[j];
	c[j] = c[j-1];
	c[j-1] = x;
      }
}

void selection(card c[], int N)
{
  int i, j, min;
  card x;

  for (i = 0; i < N; i++){
    min = i;
    for (j = i; j < N; j++)
      if (c[j].n < c[min].n)
	min = j;
    x = c[i];
    c[i] = c[min];
    c[min] = x;
  }
}

int stable(card c1[], card c2[], int N)
{
  int i;
  
  for (i = 0; i < N; i++)
    if (c1[i].s != c2[i].s)
      return 0;
  return 1;
}

int main()
{
  int i, N;
  card c1[36], c2[36];
  
  scanf("%d",&N);
  for (i = 0; i < N; i++){
    scanf(" %c%d",&c1[i].s,&c1[i].n);
    c2[i] = c1[i];
  }
  bubble(c1,N);
  selection(c2,N);
  for (i = 0; i < N; i++){
    printf("%c%d",c1[i].s,c1[i].n);
    if (i < N-1)
      printf(" ");
    else
      printf("\n");
  }
  printf("Stable\n");
  for (i = 0; i < N; i++){
    printf("%c%d",c2[i].s,c2[i].n);
    if (i < N-1)
      printf(" ");
    else
      printf("\n");
  }
  if (stable(c1,c2,N) == 0)
    printf("Not stable\n");
  else
    printf("Stable\n");

  return 0;
}

