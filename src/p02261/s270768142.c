#include"stdio.h"
#include"stdlib.h"
#include"string.h"
void BubbleSort(char **A,int n)
{
  int i,j;
  int buf[3];
  for(i=0;i<n;i++)
    {
      for(j=n-1;j>i;j--)
        {
          if(A[j-1][1]>A[j][1])
            {
              strcpy(buf,A[j-1]);
              strcpy(A[j-1],A[j]);
              strcpy(A[j],buf);
            }
        }
    }
  printf("%s",A[0]);
  for(i=1;i<n;i++)
    {
      printf(" %s",A[i]);
    }
  printf("\n");
}
void SelectionSort(char **A,int n)
{
  int i,j;
  int min;
  char buf[3];
  for(i=0;i<n;i++)
    {
      min=i;
      for(j=i;j<n;j++)
        {
          if(A[j][1]<A[min][1])
            {
              min=j;
            }
        }
      if(i!=min)
        {
          strcpy(buf,A[i]);
          strcpy(A[i],A[min]);
          strcpy(A[min],buf);
        }
    }
  printf("%s",A[0]);
  for(i=1;i<n;i++)
    {
      printf(" %s",A[i]);
    }
  printf("\n");
}
void Gudge(int n,char **card,char **A)
{
  int i,j,f;
  int c=0;
  for(i=1;i<n;i++)
    {
      if(A[i-1][1]==A[i][1])
        {
          for(j=c;j<n;j++)
            {
              if(A[i-1][1]==card[j][1])
                {
                  if(A[i-1][0]==card[j][0])
                    {
                      for(f=j+1;f<n;f++)
                        {
                          if(A[i][1]==card[f][1])
                            {
                              if(A[i][0]==card[f][0])
                                {
                                  c=j+1;
                                  j=n;
                                  break;
                                }
                              else
                                {
                                  i=n;
                                  j=n;
                                  break;
                                }
                            }
                        }
                    }
                  else
                    {
                      i=n;
                      break;
                    }
                }
            }
        }
      else
        {
          c=0;
        }
    }
  if(i==n+1)
    {
      printf("Not stable\n");
    }
  else
    {
      printf("Stable\n");
    }
}
int main()
{
  int n;
  char **card;
  char **card1;
  char **card2;
  int i,j;
  int f;
  scanf("%d",&n);
  card =(char**)malloc(sizeof(char*)*n);
  card1=(char**)malloc(sizeof(char*)*n);
  card2=(char**)malloc(sizeof(char*)*n);
  for(i=0;i<n;i++)
    {
      card[i] =(char*)malloc(sizeof(char)*3);
      card1[i]=(char*)malloc(sizeof(char)*3);
      card2[i]=(char*)malloc(sizeof(char)*3);
      scanf("%s",card[i]);
      strcpy(card1[i],card[i]);
      strcpy(card2[i],card1[i]);
    }
  BubbleSort(card1,n);
  Gudge(n,card,card1);
  SelectionSort(card2,n);
  Gudge(n,card,card2);
  return 0;
}
