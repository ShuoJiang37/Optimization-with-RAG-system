#include<stdio.h>
typedef struct
{
  char moji;
  int value;
}card;
  int main()
{
  int i,j,n,min,c=0;
  card A[36],C[36],a,b;
  scanf("%d",&n);
    for(i=0;i<n;i++)
      {
        scanf(" %c%d",&C[i].moji,&C[i].value);
  A[i].moji=C[i].moji;
  A[i].value=C[i].value;
       }
  for(i=0;i<n-1;i++)
    {
      for(j=n-1;j>i;j--)
        {
          if(C[j].value<C[j-1].value)
            {
              a=C[j];
              b=C[j-1];
              C[j]=b;
              C[j-1]=a;
            }
        }
    }
  for(i=0;i<=n;i++)
    {
      min=i;
      for(j=i;j<n;j++)
        {
          if(A[j].value<A[min].value)
            {
              min=j;
            }
        }
      a=A[i];
      b=A[min];
      A[i]=b;
      A[min]=a;
    }
  for(i=0;i<n-1;i++)
    {
      printf("%c%d ",C[i].moji,C[i].value);
    }
  printf("%c%d\n",C[n-1].moji,C[n-1].value);
  printf("Stable\n");
  for(i=0;i<n-1;i++)
    {
      printf("%c%d ",A[i].moji,A[i].value);
    }
  printf("%c%d\n",A[n-1].moji,A[n-1].value);
  for(i=0;i<=n-1;i++)
    {
      if(C[i].moji!=A[i].moji)
        {
          c=1;
        }
    }
  if(c==1)
    printf("Not stable\n");
  else
    printf("Stable\n");
  
      
  return 0;
}

