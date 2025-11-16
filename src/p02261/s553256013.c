#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))

typedef struct
{
  char suit;
  char value;
} Card;

void swap(Card *a,Card *b)
{
  Card tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void print(Card a[],int n)
{
  int i, value, sort;
  for(i = 1; i <= n; i++)
    {
      printf("%c%c",a[i].suit,a[i].value);
      if(i != n) printf(" ");
    }
  printf("\n");
}

void print_judge(bool a)
{
  if(a) printf("Stable\n");
  else printf("Not stable\n");
}
 
void Selectionsort(Card a[],Card b[],const int n)
{
  int i, j, min_index;
  bool judge = true;
  for(i = 1; i <= n; i++)
    {
      min_index = i;
      for(j = i; j <= n; j++)
	{
	  if(a[j].value < a[min_index].value) min_index = j;
	}
      if(min_index != i)
	{
	  swap(&a[i],&a[min_index]);
	}
    }
  print(a,n);
  for(i = 1; i <= n; i++) if(a[i].suit != b[i].suit) judge = false;
  print_judge(judge);
}

void Bubblesort(Card a[],const int n)
{
  int i , j;
  bool judge = true;
  for(i = 1; i <= n; i++)
    {
      for(j = n; j >= i+1; j--)
	{
	  if(a[j].value < a[j-1].value)
	    {
	      swap(&a[j],&a[j-1]);
	    }
	}
    }
  print(a,n);
  print_judge(judge);
}

int main(){
  Card C1[101], C2[101];
  int n, i;
  char ch;

  scanf("%d%c", &n, &ch);
  for ( i = 1; i <= n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
    C2[i] = C1[i];
  }
  Bubblesort(C1,n);
  Selectionsort(C2,C1,n);
  return 0;
}