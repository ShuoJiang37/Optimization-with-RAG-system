#include <stdio.h>

#define false 0;
#define true 1;

typedef struct{
  char mark;
  int value;
}card;

int isStable(card[],card[],int);

int main()
{
  int N,i,j,c,minj;
  card C[36],t,in[36],C2[36];

  scanf("%d",&N);

  if(N < 1 || N >36) return 0;

  for(i = 0 ; i < N ; i++ )
    {
      scanf(" %c %d",&C[i].mark,&C[i].value);
      in[i] = C[i];
      C2[i] = C[i];
    }

  for(i = 0 ; i <= N-1 ; i++)
    {
      for(j = N-1 ; j >= i+1 ; j--)
	{
	  if(C[j].value < C[j-1].value)
	    {
	      t = C[j];
	      C[j] = C[j-1];
	      C[j-1] = t;
	    }
	}
    }
  for(i = 0 ; i < N ; i++)
    {
      printf("%c%d",C[i].mark,C[i].value);
      if(i < N-1) printf(" ");
    }

  printf("\n");

  if(isStable(in,C,N)) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0 ; i <= N-1 ; i++)
    {
      minj = i;
      for(j = i ; j <= N-1 ; j++)
	{
	  if(C2[j].value < C2[minj].value)
	    {
	      minj = j;
	    }
	}
      t = C2[i];
      C2[i] = C2[minj];
      C2[minj] = t;
    }

  for(i = 0 ; i < N ; i++)
    {
      printf("%c%d",C2[i].mark,C2[i].value);
      if(i < N-1) printf(" ");
    }
   
  printf("\n");
 
  if(isStable(in,C2,N)) printf("Stable\n");
  else printf("Not stable\n"); 
  
  return 0;
}

int isStable(card *in,card *out,int N)
{
  int i,j,a,b;

  for(i = 0 ; i <= N-1 ; i++)
    {
      for(j = i+1 ; j <= N-1 ; j++)
	{
	  for(a = 0 ; a <= N-1 ; a++)
	    {
	      for(b = a+1 ; b <= N-1 ; b++)
		{
		  if(in[i].value == in[j].value && in[i].value == out[b].value && in[i].mark == out[b].mark && in[j].value == out[a].value && in[j].mark == out[a].mark) return false;
		}
	    }
	}
    }
  
  return true;
}

