#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char suit,value;
}Card;

void Bubble(Card A[],int n)
{
  int i,j;
  Card f;
  for(i=0;i<=n-1;i++)
    {
      for(j = n-1;j>=i+1;j--)
	{
	  if(A[j].value<A[j-1].value)
	    {
	      f = A[j];
	      A[j]=A[j-1];
	      A[j-1]=f;
	    }
	}
    }
}

void Selection(Card A[], int n)
{
  int i,j,minj,a,b;
  Card t;
  for(i=0;i<=n-1;i++)
    {
      minj=i;
      for(j = i;j<=n-1;j++)
	{
	  if(A[j].value<A[minj].value)
	    {
	      minj=j;
	    }
	}
	  t =A[i];A[i] = A[minj];A[minj]=t;    
	
    }
}

int isStable(Card C1[],Card C2[],int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      if(C1[i].suit != C2[i].suit)return 0;
    }
  return 1;
} 

int main()
{
  int i,j,n;
  Card C1[100],C2[100];
  char as,s[3]; 
  scanf("%d",&n);
  for(i = 0;i<n;i++)
    {
    scanf("%s",s);
  C1[i].suit=s[0];
  C1[i].value=s[1];
    }

  for(i=0;i<n;i++)C2[i]=C1[i];

  Bubble(C1,n);
  Selection(C2,n);

  for(i=0;i<n-1;i++)
    {
      s[0] = C1[i].suit;
      s[1]=C1[i].value;

      printf("%s ",s);
    }
  s[0] = C1[i].suit;
  s[1]=C1[i].value;
  printf("%s\n",s);
  printf("Stable\n");

  for(i=0;i<n-1;i++)
    {
      s[0] = C2[i].suit;
      s[1]=C2[i].value;

      printf("%s ",s);
    }
  s[0] = C2[i].suit;
  s[1]=C2[i].value;
  printf("%s\n",s);

  if(isStable(C1,C2,n))
    {
      printf("Stable\n");
    }
  else{
    printf("Not stable\n");
  }


  return 0;
}