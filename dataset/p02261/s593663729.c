#include<stdio.h>

struct Card
{
  char suit;
  int value;
};

void bubble(struct Card A[],int n);
void selection(struct Card A[],int n);
void print(struct Card A[],int n);
int isStable(struct Card c1[],struct Card c2[],int n);


int main(void)
{
  int i;
  struct Card c1[100],c2[100];
  int n;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf(" %c %d",&c1[i].suit,&c1[i].value);
    }

  for(i=0;i<n;i++)
    {
      c2[i]=c1[i];
    }

  bubble(c1,n);
  selection(c2,n);

  print(c1,n);
  puts("Stable");
  
  print(c2,n);
  if(isStable(c1,c2,n)==1)
    {
      puts("Stable");
    }
  else
    {
      puts("Not stable");
    }

  return 0;
}

void bubble(struct Card A[], int n)
{
  int i,j;
  for(i=0;i<n;i++)
    {
      for(j=n-1;j>=i+1;j--)
	{
	  if(A[j].value<A[j-1].value)
	    {
	      struct Card t=A[j];
	      A[j]=A[j-1];
	      A[j-1]=t;
	    }
	}
    }
}

void selection(struct Card A[],int n)
{
  int i,j;
  int minj;
  
  for(i=0;i<n;i++)
    {
      minj=i;
    
      for(j=i;j<n;j++)
	{
	  if(A[j].value<A[minj].value)
	    {
	      minj=j;
	    }
	}
    
      struct Card t=A[i];
      A[i]=A[minj];
      A[minj]=t;
    }
}

void print(struct Card A[],int n)
{
  int i;
  
  for(i=0;i<n;i++)
    {
      if(i>0)
	{
	  putchar(' ');
	}
    
      printf("%c%d",A[i].suit,A[i].value);
    }
  
  putchar('\n');
}

int isStable(struct Card c1[],struct Card c2[],int n)
{  
  int i;
 
  for(i=0;i<n;i++)
    {
      if(c1[i].suit!=c2[i].suit)
	{
	  return 0;
	}
    }
  return 1;
}

