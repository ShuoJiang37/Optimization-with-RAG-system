#include<stdio.h>
typedef struct
{
  char mark;
  char num;
}cards;

void bubble(cards C[],int N)
{
  int i,j;
  for(i=0;i<N;i++)
    {
      for(j=N-1;j>=i;j--)
        {
          if(C[j].num<C[j-1].num)
            {
              cards b;
              b=C[j];
              C[j]=C[j-1];
              C[j-1]=b;
            }
        }
    }
}

void select(cards C[],int N)
{
  int i,j;
  for(i=0;i<N;i++)
    {
      int minv=i;
      for(j=i;j<N;j++)
        {
          if(C[j].num<C[minv].num) minv=j;
        }
      cards b;
      b=C[i];
      C[i]=C[minv];
      C[minv]=b;
    }
}

int isStable(cards A[],cards B[],int N)
{
  int i;
  for(i=0;i<N;i++)
    {
      if(A[i].mark!=B[i].mark)return 0;
    }
  return 1;
}

int main()
{
 cards A[100],B[100];
  int i,N;
  char card[3];
  char carda[3];
  char cardb[3];

  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%s",card);
      A[i].mark=card[0];
      A[i].num=card[1];
    }

  for(i=0;i<N;i++)
    {
      B[i]=A[i];
    }

  bubble(A,N);
  select(B,N);

  for(i=0;i<N;i++)
    {
      if(i>0)printf(" ");
      card[0]=A[i].mark;
      card[1]=A[i].num;
      printf("%s",card);
    }
  printf("\n");
  printf("Stable\n");
  for(i=0;i<N;i++)
    {
      if(i>0)printf(" ");
      card[0]=B[i].mark;
      card[1]=B[i].num;
      printf("%s",card);
    }
  printf("\n");
  if(isStable(A,B,N)==1)
    {
      printf("Stable\n");
    }
  else
    {
      printf("Not stable\n");
    }
  return 0;
}