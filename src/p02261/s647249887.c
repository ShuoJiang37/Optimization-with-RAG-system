#include <stdio.h>
#define N 36
typedef struct{
  char mark,num;
}card;
int main()
{
  int n,i,j,l,k=1,mini;
  card A1[N],A2[N],a;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf(" %c%c",&A1[i].mark,&A1[i].num);
  }
  for(i=0;i<n;i++)
  {
    A2[i]=A1[i];
  }

  for(i=0;i<=n-1;i++)
  {
    mini = i;
    for(j=i;j<=n-1;j++)
    {
      if(A2[j].num < A2[mini].num)
        {
          mini = j;
        }
    }
      a = A2[i];
      A2[i] = A2[mini];
      A2[mini] = a;
  }
  for(i=0;i<n;i++)
  {
    for(j=n-1;j>=i;j--)
    {
      if(A1[j].num < A1[j-1].num)
      {
        a=A1[j];
        A1[j]=A1[j-1];
        A1[j-1]=a;
      }
    }
  }
  for(l=0;l<n;l++)
  {
    if(l)
      printf(" ");
    printf("%c%c",A1[l].mark,A1[l].num);
  }
  printf("\nStable\n");
  for(i=0;i<n;i++)
  {
    printf("%c%c",A2[i].mark,A2[i].num);
    if(i!=n-1)
      printf(" ");
  }
  for(i=0;i<n;i++)
  {
    if(A1[i].mark!=A2[i].mark)
      k=0;
  }
  if(k!=0)
    printf("\nStable\n");
  else
    printf("\nNot stable\n");
  return 0;
}

