#include<stdio.h>
#include<stdbool.h>
typedef struct{
  char shcd;
  int value;
} Data;

bool isStable(int N, Data C1[] , Data C2[])
{
  for(int i = 0;i < N;i++)
    {
      if(C1[i].shcd != C2[i].shcd) return false;
    }
  return true;
}

int main()
{
  int N,i,j,minj;
  Data C[36],C1[36],C2[36],X;

  scanf("%d",&N);
  
  for(i = 0;i <= N - 1;i++)
    scanf(" %c%d",&C[i].shcd,&C[i].value);

  for(i = 0;i <= N - 1;i++)
    {
      C1[i] = C[i];
      C2[i] = C[i];
    }

  for(i = 0;i <= N - 1;i++)
    {
      for(j = N - 1;j >= i + 1;j--)
	{
	  if(C1[j].value < C1[j - 1].value)
	    {
	      X = C1[j];
	      C1[j] = C1[j - 1];
	      C1[j - 1] = X;
	    }
	}
    }
  for(i = 0;i < N - 1;i++)
     printf("%c%d ",C1[i].shcd,C1[i].value);
  printf("%c%d",C1[N - 1].shcd,C1[N - 1].value);
  printf("\n");
  
    printf("Stable\n");
 
  for(i = 0;i <= N - 1;i++)
    {
      minj = i;
      for(j = i;j <= N - 1;j++)
	{
	  if(C2[j].value < C2[minj].value)
	    minj = j;
	}
      X = C2[i];
      C2[i] = C2[minj];
      C2[minj] = X;
    }
  
   for(i = 0;i < N - 1;i++)
     printf("%c%d ",C2[i].shcd,C2[i].value);
   printf("%c%d",C2[N - 1].shcd,C2[N - 1].value);
   printf("\n");
   
   if(isStable(N,C1,C2))
     {
     printf("Stable\n");
     }
   else printf("Not stable\n");
  return 0;
}  
      

