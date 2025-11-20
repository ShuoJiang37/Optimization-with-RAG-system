#include <stdio.h>
#include <string.h>


#define M 36

typedef struct {
  char mark;
  int value;
} C;

void Bubble(C *, int);
void Selection(C *, int);
void disply(C *, int);
int Stable(C *, C *, int);

int main()
{
  C c1[M+1], c2[M+1];
  int i, N;

  scanf("%d", &N);



  for( i = 0 ; i < N ; i++ ){
    scanf(" %c%d", &c1[i].mark, &c1[i].value);
  }

  for( i = 0 ; i < N ; i++ ) c2[i] = c1[i];

  Bubble(c1, N);
  disply(c1, N);
  printf("Stable\n");

  Selection(c2, N);
  disply(c2, N);

  if( Stable(c1, c2, N) == 0 ) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}
void Bubble(C c1[], int N)
{
  int i, j;
  C t;

  for( i = 0 ; i < N ; i++ ){
    for( j = N-1 ; j > i ; j-- ){
      if( c1[j].value < c1[j-1].value ){
        t = c1[j];
        c1[j] = c1[j-1];
        c1[j-1] = t;
      }
    }
  }
}



void Selection(C c2[], int N)
{
  int i, j, minj;
  C t;

  for( i = 0 ; i < N ; i++ ){
    minj = i;
    for( j = i ; j < N ; j++ ){
      if( c2[j].value < c2[minj].value ) minj = j;
    }
    t = c2[i];
    c2[i] = c2[minj];
    c2[minj] = t;
  }
}


int Stable(C c1[], C c2[], int N)
{
  int i;

  for( i = 0 ; i < N ; i++ )
  if( c1[i].mark != c2[i].mark ) return 1;

  return 0;
}


void disply(C c[], int N)
{
  int i;

  for( i = 0 ; i < N ; i++ ){
    if( i > 0 ) printf(" ");
    printf("%c%d", c[i].mark, c[i].value);
  }
  printf("\n");
}

