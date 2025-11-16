#include<stdio.h>
#define STABLE 1
#define NOT_STABLE 0
int BubbleSort( char Suit[], char Number[], int Order[], int n ){

  int i,j,k;
  char c;

  for ( i = 0 ; i < n ; i++ ){
    for ( j = n - 1 ; j > i ; j-- ){
      if ( Number[j] < Number[ j - 1 ] ) {
	c = Suit[j];
	Suit[j] = Suit[ j - 1 ];
	Suit[ j - 1 ] = c;
	c = Number[j];
	Number[j] = Number[ j - 1 ];
	Number[ j - 1 ] = c;
	k = Order[j];
	Order[j] = Order[ j - 1 ];
	Order[ j - 1 ] = k;
      }
    }
  }

  return 0;

}
int SelectionSort( char Suit[], char Number[], int Order[], int n ){

  int i,j,k,minj;
  char c;

  for ( i = 0 ; i < n ; i++ ){
    minj = i;
    for( j = i ; j < n ; j++ ){
      if ( Number[j] < Number[minj] ){
	minj = j;
      }
    }
    c = Suit[i];
    Suit[i] = Suit[minj];
    Suit[minj] = c;
    c = Number[i];
    Number[i] = Number[minj];
    Number[minj] = c;
    k = Order[i];
    Order[i] = Order[minj];
    Order[minj] = k;
  }

  return 0;
  
}
int is_stable( char Suit[], char Number[], int Order[], int n ){

  int i;

  for ( i = 0 ; i < n - 1 ; i++ ){
    if ( Number[i] == Number[ i + 1 ] && Order[i] > Order[ i + 1 ] ) {
      return NOT_STABLE;
    }
  }

  return STABLE;
  
}



int main(){

  int i,n;

  scanf("%d", &n );

  char Suit[37],Number[37],c;
  int Order[37];

  for ( i = 0 ; i < n ; i++ ){
    scanf("%c", &c );
    scanf("%c", &Suit[i] );
    scanf("%c", &Number[i] );
    Order[i] = i;
  }

  char Suit1[37],Number1[37];
  int Order1[37];

  for ( i = 0 ; i < n ; i++ ){
    Suit1[i] = Suit[i];
    Number1[i] = Number[i];
    Order1[i] = Order[i];
  }
  
  BubbleSort( Suit1, Number1, Order1, n );

  for ( i = 0 ; i < n ; i++ ){
    if ( i < n - 1 ) {
      printf("%c%c ", Suit1[i], Number1[i] );
    } else {
      printf("%c%c\n", Suit1[i], Number1[i] );
    }
  }

  if ( is_stable( Suit1, Number1, Order1, n ) == STABLE ){
    printf("Stable\n");
  } else if ( is_stable( Suit1, Number1, Order1, n ) == NOT_STABLE ){
    printf("Not stable\n");
  } else {
    printf("ERROR\n");
  }

  SelectionSort( Suit, Number, Order, n );

  for ( i = 0 ; i < n ; i++ ){
    if ( i < n - 1 ) {
      printf("%c%c ", Suit[i], Number[i] );
    } else {
      printf("%c%c\n", Suit[i], Number[i] );
    }
  }

  if ( is_stable( Suit, Number, Order, n ) == STABLE ){
    printf("Stable\n");
  } else if ( is_stable( Suit, Number, Order, n ) == NOT_STABLE ){
    printf("Not stable\n");
  } else {
    printf("ERROR\n");
  }


  return 0;

}