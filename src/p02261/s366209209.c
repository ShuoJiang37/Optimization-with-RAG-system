#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char mark;
  int value;
} Card;

int isStable(Card *, Card *, int);


int main() {
  Card *IN, *OUTBubble, *OUTSelection, temp;
  char c;
  int i, j, N, minj;
  
  scanf( "%d" , &N );
  IN = malloc(N * sizeof(Card));
  OUTBubble = malloc(N * sizeof(Card));
  OUTSelection = malloc(N * sizeof(Card));
  for ( i=0; i<N; i++ ) {
    scanf( " %c" , &(IN[i].mark) );
    scanf( "%d" , &(IN[i].value) );
    OUTBubble[i] = OUTSelection[i] = IN[i];
  }
  
  for ( i=0; i<N; i++ )
    for ( j=(N-1); j>i; j-- )
      if ( OUTBubble[j].value < OUTBubble[j-1].value ) {
	temp = OUTBubble[j];
	OUTBubble[j] = OUTBubble[j-1];
	OUTBubble[j-1] = temp;
      }
  
  for ( i=0; i<(N-1); i++ )
    printf( "%c%d " , OUTBubble[i].mark , OUTBubble[i].value ); 
  printf( "%c%d\n" , OUTBubble[N-1].mark , OUTBubble[N-1].value );
  if ( isStable(IN, OUTBubble, N) == 1 ) printf( "Stable\n" );
  else printf( "Not stable\n" );

  for ( i=0; i<N; i++ ) {
    minj = i;
    for ( j=i; j<N; j++ )
      if ( OUTSelection[j].value < OUTSelection[minj].value ) minj = j;
    temp = OUTSelection[i];
    OUTSelection[i] = OUTSelection[minj];
    OUTSelection[minj] = temp;
  }

  for ( i=0; i<(N-1); i++ )
    printf( "%c%d " , OUTSelection[i].mark , OUTSelection[i].value ); 
  printf( "%c%d\n" , OUTSelection[N-1].mark , OUTSelection[N-1].value );
  if ( isStable(IN, OUTSelection, N) == 1 ) printf( "Stable\n" );
  else printf( "Not stable\n" );
  
  return 0;
}


int isStable(Card *IN, Card *OUT, int N) {
  int i, j, a, b;
  for ( i=0; i<N; i++ )
    for ( j=(i+1); j<N; j++ )
      for ( a=0; a<N; a++ )
	for ( b=(a+1); b<N; b++ )
	  if ( (IN[i].value == IN[j].value)
	       && (IN[i].mark == OUT[b].mark)
	       && (IN[i].value == OUT[b].value)
	       && (IN[j].mark == OUT[a].mark)
	       && (IN[j].value == OUT[a].value) ) return 0;
  return 1;
}

