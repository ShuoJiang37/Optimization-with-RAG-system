#include<stdio.h>
struct Card
{
  char mark;
  char value;
};

main(){
  struct Card C1[100],C2[100],c;
  int n,i,j,mini;
  char ch;
  scanf("%d%c",&n,&ch);
  for(i=0;i<n;i++)
    {
      scanf("%c%c%c",&C1[i].mark,&C1[i].value,&ch);
      C2[i]=C1[i];
    }

  for(i=0;i<=n-1;i++)
    {
      for(j=n-1;j>=i+1;j--)
	{
	  if(C1[j].value<C1[j-1].value)
	  {
	    c=C1[j];
	    C1[j]=C1[j-1];
	    C1[j-1]=c;
	  }
	}
    }

  for(i=0;i<=n-1;i++)
    {
      mini=i;
      for(j=i;j<=n-1;j++)
	{
	  if(C2[j].value<C2[mini].value)
	    {
	      mini=j;
	    }
	}
      c=C2[i];
      C2[i]=C2[mini];
      C2[mini]=c;
    }
  for(i=0;i<n;i++)
    {
      printf("%c%c",C1[i].mark,C1[i].value);
      if(i<n-1) printf(" ");
    }
  printf("\nStable\n");
  for(i=0;i<n;i++)
    {
      printf("%c%c",C2[i].mark,C2[i].value);
      if(i<n-1) printf(" ");
    }
  for(i=0;i<n;i++)
    {
    if(C1[i].mark!=C2[i].mark)
      {
	printf("\nNot stable\n"); break;
      }
    }
  if(i==n) printf("\nStable\n");

  return 0;
}