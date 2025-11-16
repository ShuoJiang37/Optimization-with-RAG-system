#include <stdio.h>

typedef struct
{
  char ch;
  char num;
}P;

void Bubble(P C[],int n)
{
  P t;
  int i,j;

  for(i = 0;i < n;i++)
  {
    for(j = n - 1;j >= i + 1;j--)
    {
      if(C[j].num < C[j - 1].num)
      {
        t = C[j];
        C[j] = C[j - 1];
        C[j - 1] = t;
      }
    }
  }
}

void Select(P C[],int n)
{
  P t;
  int i,j,min;

  for(i = 0;i < n;i++)
  {
    min = i;
    for(j = i;j < n;j++)
    {
      if(C[j].num < C[min].num) min = j;
    }
    t = C[i];
    C[i] = C[min];
    C[min] = t;
  }
}

void Print(P C[],int n)
{
  int i;

  for(i = 0;i < n;i++)
  {
    if(i) printf(" ");
    printf("%c",C[i].ch);
    printf("%c",C[i].num);
  }
  printf("\n");
}

int Judg(P C1[],P C2[],int n)
{
  int i;

  for(i = 0;i < n;i++)
  {
    if(C1[i].ch != C2[i].ch) return 0;
  }
  return 1;
}

int main()
{
  P C1[100],C2[100];
  int i,n;

  scanf("%d",&n);
  for(i = 0;i < n;i++)
  {
    scanf(" %c%c",&C1[i].ch,&C1[i].num);
    C2[i] = C1[i];
  }

  Bubble(C1,n);
  Print(C1,n);
  printf("Stable\n");

  Select(C2,n);
  Print(C2,n);
  if(Judg(C1,C2,n)) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

