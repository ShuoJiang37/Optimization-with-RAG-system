#include<stdio.h>
#define MAX 36
struct Card{
  char suit;
  char value;
};
int main()
{
  struct Card a1[MAX],a2[MAX],tmp;
  int i,j,tmp2;
  int min,x,kt=1;
  char y,tmp1;
  scanf("%d%c",&x,&y);
  for(i=0;i<x;i++)
    {
      scanf("%c%c%c",&a1[i].suit,&a1[i].value,&y);
      a2[i] = a1[i];
    }

  for(i=0;i<x;i++)
    {
      for(j=x-1;j>i;j--)
	{
	  if(a1[j].value < a1[j-1].value)
	    {
	      tmp = a1[j];
	      a1[j] = a1[j-1];
	      a1[j-1] = tmp;
	    }
	}
    }

  for(i=0;i<x;i++)
    {
      min = i;
      for(j=i;j<x;j++)
	{
	  if(a2[j].value < a2[min].value)
	    {
	      min = j;
	    }
	}
      if(i!=min)
	{
	  tmp = a2[i];
	  a2[i] = a2[min];
	  a2[min] = tmp;
	}
    }
  for(i=0;i<x;i++)
    {
      printf("%c%c",a1[i].suit,a1[i].value);
      if(i != x-1)
	{
	  printf(" ");
	}
      else printf("\n");
    }
  printf("Stable\n");
 for(i=0;i<x;i++)
    {
      printf("%c%c",a2[i].suit,a2[i].value);
      if(i != x-1)
	{
	  printf(" ");
	}
      else printf("\n");
    }
 for(i=0;i<x;i++)
   {
     if(a1[i].suit != a2[i].suit)
       {
	 printf("Not stable\n");
	 kt = 0;
	 break;
       }
   }
 if(kt==1)
   {
     printf("Stable\n");
   }
 return 0;
}