#include<stdio.h>

struct Card{
  char suit;
  char value;
};

struct Card C1[101], C2[101];

void trace(struct Card C[], int n)
{
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%c%c",C[i].suit, C[i].value);
  }
  printf("\n");
}

void Bubble(struct Card CB[], int n)
{
  struct Card CB2[101];
  int i,j,mini;
  for(i=0 ; i<n ; i++)
    {
      for(j=n ; j >= i+1 ; j--)
	{
	  if(CB[j].value < CB[j-1].value)
	    {
	      CB2[j] = CB[j];
	      CB[j] = CB[j-1];
	      CB[j-1] = CB2[j];
	    }
	}
    }
  trace(CB,n);
  printf("Stable\n");
}

void Selection(struct Card CS[], int n)
{
  struct Card CS2[101];
  int i,j,mini,count,flag=0;
  for(i=0 ; i<=n ; i++)
    {
      mini = i;
      count=0;
      for(j=i ; j<=n ; j++)
	{
	  if(CS[j].value < CS[mini].value)
	    {
	      mini = j;
	      count=1;
	    }
	}
      if(count==1)
	{
	  CS2[i] = CS[i];
	  CS[i] = CS[mini];
	  CS[mini] = CS2[i];
	}
      if(CS[i].suit != C1[i].suit)
	flag = 1;
    }
  trace(CS,n);
  if(flag==1)
    printf("Not stable\n");
  else printf("Stable\n");
}

int main(){
  
  int n, i,j,mini;
  char ch;

  scanf("%d%c", &n, &ch);
  for ( i = 1; i <= n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
    C2[i]=C1[i];
  }

  Bubble(C1, n);
  Selection(C2, n);
  return 0;
}