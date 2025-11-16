#include <stdio.h>
#define N 36

typedef struct
{
  char mark;
  char num;
} CARD;

int main()
{
  int n,i,j,minj;
  CARD C1[N],C2[N],a;
  CARD Select[N];
  char ch;

  scanf("%d%c",&n,&ch);

  for(i=0 ; i<n ;i++)
  {
    scanf("%c%c%c",&C1[i].mark,&C1[i].num,&ch);

    C2[i]=C1[i];
  }


/*BubbleSort*/
for(i=0 ; i<n ; i++)
{
  for(j=n-1 ; j>i ; j--)
  {
    if(C1[j].num < C1[j-1].num)
    {
      a=C1[j];
      C1[j]=C1[j-1];
      C1[j-1]=a;
    }
  }
}

/*SelectionSort*/
for(i=0 ; i<n ; i++)
{
  minj = i;
  for(j=i ; j<n ; j++)
  {
    if(C2[j].num < C2[minj].num) minj = j;
  }
    a=C2[i];
    C2[i] =  C2[minj];
    C2[minj] = a;
}


/*print*/
for(i=0 ; i<n-1 ; i++)
{
  printf("%c%c ",C1[i].mark,C1[i].num);
}
printf("%c%c\nStable\n",C1[n-1].mark,C1[n-1].num);

for(i=0 ; i<n-1 ; i++)
{
  printf("%c%c ",C2[i].mark,C2[i].num);
}
printf("%c%c\n",C2[n-1].mark,C2[n-1].num);

for(i=0 ; i<n ; i++)
{
  if(C1[i].mark != C2[i].mark)
  {
    printf("Not stable\n");
    break;
  }
}
if(i==n) printf("Stable\n");

  return 0;
}

