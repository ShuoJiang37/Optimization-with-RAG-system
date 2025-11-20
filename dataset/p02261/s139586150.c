#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char mark;
  int value;
} KARD;

int isStable(KARD,KARD);

int main()
{
  int i,j,N,minj,a,b,f = 0;
  scanf("%d",&N);
  KARD C[N],sub,D[N];
  for(i = 0;i < N;i++)
    {
      scanf("%c%c%d",&C[i].mark,&C[i].mark,&C[i].value);
    }
  /*for(i = 0;i < N;i++)
    {
      printf("\n%c%d\n",C[i].mark,C[i].value);
      }*/
  for(i = 0;i < N;i++)
    {
      D[i] = C[i];
    }
  
  for(i = 0;i < N;i++)//bubble
    {
      for(j = N - 1; j >= i + 1;j--)
	{
	  if(C[j].value < C[j-1].value)
	    {
	      sub = C[j];
	      C[j] = C[j - 1];
	      C[j - 1] = sub;
	    }	    
	}
    }
  for(i = 0;i < N;i++)
    {
      printf("%c%d",C[i].mark,C[i].value);
      if(i != N- 1)
	{
	  printf(" ");
	}
      else{ printf("\n");}
    }
  for(i = 0;i < N;i++)
    {
      for(j = i + 1;j < N;j++)
	{
	  for(a = 0;a < N;a++)
	    {
	      for( b = a + 1;b < N;b++)
		{
		  if(D[i].value == D[j].value && D[i].mark == C[b].mark &&D[i].value == C[b].value && D[j].mark == C[a].mark && D[j].value == C[a].value)
		    {
		       printf("Not stable\n");
		       f = 1;
		    }
		}
	    }
	}
    }
  if(f == 0)
    {
      printf("Stable\n");
    }
  
  f = 0;
  for(i = 0;i < N;i++)
    {
      C[i] = D[i];
    }
  for(i = 0;i < N - 1;i++)//selection
    {
      minj = i;
      for(j = i;j < N;j++)
	{
	  if(C[j].value < C[minj].value)
	    {
	      minj = j;
	    }
	}
      sub = C[i];
      C[i] = C[minj];
      C[minj] = sub;
    }

for(i = 0;i < N;i++)
    {
      printf("%c%d",C[i].mark,C[i].value);
      if(i != N- 1)
	{
	  printf(" ");
	}
      else{ printf("\n");}
    }
  for(i = 0;i < N;i++)
    {
      for(j = i + 1;j < N;j++)
	{
	  for(a = 0;a < N;a++)
	    {
	      for( b = a + 1;b < N;b++)
		{
		  if(D[i].value == D[j].value && D[i].mark == C[b].mark &&D[i].value == C[b].value && D[j].mark == C[a].mark && D[j].value == C[a].value)
		    {
		      f ++;
		      if(f == 1)
			{
			  printf("Not stable\n");
			}
		    }
		}
	    }
	}
    }
  if(f == 0)
    {
      printf("Stable\n");
    }
 return 0;
}

