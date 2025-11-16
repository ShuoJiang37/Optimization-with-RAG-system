#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 36
void bubble(int);
void selec(int);
int isStable(int);
int isStabled(int);
char C[M][3],S[M][3],D[M][3];
int main()
{ 
  int i,j;
  scanf("%d",&i);
  for(j=0;j<i;j++)
    {
      scanf("%s",C[j]);
      strcpy(S[j],C[j]);
      strcpy(D[j],C[j]);
    }
  bubble(i);
  for(j=0;j<i-1;j++)
    {
      printf("%s ",C[j]);
    }
  printf("%s\n",C[i-1]);
  if(isStable(i)==1)
    printf("Stable\n");
  else
    printf("Not stable\n");
  selec(i);
  for(j=0;j<i-1;j++)
    {
      printf("%s ",D[j]);
    }
  printf("%s\n",D[i-1]);
  if(isStabled(i)==1)
    printf("Stable\n");
  else
    printf("Not stable\n");
  return 0;
}

void bubble(int N)
{
  int i,j;
  char pretend[3];
  for(i=0;i<N;i++)
    {
      for(j=N-1;j>i;j--)
	{
	  if(atoi(&C[j][1])<atoi(&C[j-1][1]))
	    {
	      strcpy(pretend,C[j]);
	      strcpy(C[j],C[j-1]);
	      strcpy(C[j-1],pretend);	     
	    }
	}
    }
}
void selec(int N)
{
  int i,j,minj;
  char pretend[3];
  for(i=0;i<N;i++)
    {
      minj=i;
      for(j=i;j<N;j++)
	{
	  if(atoi(&D[j][1])<atoi(&D[minj][1]))
	    {
	      minj=j;	      
	    }
	}
      if(minj==i)
	continue;
      strcpy(pretend,D[i]);
      strcpy(D[i],D[minj]);
      strcpy(D[minj],pretend);	
    }
}
int isStable(int N)
{
  int i,j,a,b,count=0;
  for(i=0;i<N;i++)
    {
      for(j=i+1;j<N;j++)
	{
	  for(a=0;a<N;a++)
	    {
	      for(b=a+1;b<N;b++)
		{
		  if(atoi(&S[i][1])==atoi(&S[j][1]) && S[i][0]==C[b][0] && S[j][0]==C[a][0] && atoi(&S[i][1])==atoi(&C[b][1]) && atoi(&S[j][1])==atoi(&C[a][1]))
		    {
		      return -1;
		    }
		   
		}
	    }
	}
    }
  return 1;
}
int isStabled(int N)
{
  int i,j,a,b,count=0;
  for(i=0;i<N;i++)
    {
      for(j=i+1;j<N;j++)
	{
	  for(a=0;a<N;a++)
	    {
	      for(b=a+1;b<N;b++)
		{
		  if(atoi(&S[i][1])==atoi(&S[j][1]) && S[i][0]==D[b][0] && S[j][0]==D[a][0] && atoi(&S[i][1])==atoi(&D[b][1]) && atoi(&S[j][1])==atoi(&D[a][1]))
		    {		     
		      return -1;
		    }
		}
	    }
	}
    }
  return 1;
}

