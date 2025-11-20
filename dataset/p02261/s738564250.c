#include<stdio.h>
#define true 1;
#define false 0;
struct Card{
  char match;
  char value;
};

void bubble(struct Card A[],int n)
{
  struct Card t;
  int i;
  int j;
  
  for( i = 0 ; i < n ; i++ ){
    for( j = n - 1; j >= i; j-- ){
      if( A[j].value < A[j-1].value ){
        t = A[j];
	A[j] = A[j-1];
	A[j-1] = t;
      }
    }
  }
}

void select(struct Card A[], int n )
{
  struct Card t;
  int i;
  int j;
  int min=0;
  
  for( i = 0 ; i < n; i++ ){
    min = i;
    for( j = i ; j < n ; j++ ){
      if(A[j].value < A[min].value ) min = j;
    }
    t = A[i];
    A[i] = A[min];
    A[min] = t;
  }
}

void print(struct Card A[], int n)
{
  int i;
  
  for( i = 0 ; i < n ; i++ ){
    if( i > 0 )printf(" ");
    printf("%c%d",A[i].match,A[i].value);
  }
  printf("\n");
}

int stable( struct Card c1[],struct Card c2[],int n )
{
  int i;
  
  for( i = 0 ; i < n; i++ ){
    if( c1[i].match != c2[i].match )return false;
  }
  return true;
}

int main(){
  struct Card c1[100],c2[100];
  int n;
  char moji;
  int i;

  scanf("%d",&n);
  for( i = 0 ; i < n; i++ ){
    scanf(" %c%d",&c1[i].match,&c1[i].value);
  }
  for( i = 0 ; i < n ; i++ )c2[i] = c1[i];

  bubble(c1,n);
  select(c2,n);

  print(c1,n);
  printf("Stable\n");
  print(c2,n);
  if( stable(c1,c2,n)){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }

  return 0;
}
  
  

