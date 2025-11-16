#include <stdio.h>
#define N 36

typedef struct
{
  char ki;
  int su;
}inf;

int main()
{
  int n,i,j,de1,minj,de2,flag=0;
  char ni1,ni2;
  inf cards1[N],cards2[N];
  scanf("%d",&n);
  for(i=0;i<=n-1;i++)
    {
      scanf(" %c%d",&cards1[i].ki,&cards1[i].su);
    }

  for(i=0;i<=n-1;i++)
    {
      cards2[i].ki=cards1[i].ki;
      cards2[i].su=cards1[i].su;
    }
  /*
  for(i=0;i<=n-1;i++)
    {
      printf("%c%d ",cards2[i].ki,cards2[i].su);
    }
  printf("\n");
  */
  for(i=0;i<=n-1;i++)
    {
      for(j=n-1;j>=i+1;j--)
	{
	  if(cards1[j].su<cards1[j-1].su)
	    {
	      //C[j] と C[j-1] を交換
	      de1=cards1[j].su;
	      ni1=cards1[j].ki;
	      cards1[j].su=cards1[j-1].su;
	      cards1[j].ki=cards1[j-1].ki;
	      cards1[j-1].su=de1;
	      cards1[j-1].ki=ni1;
	    }
	}
    }
  for(i=0;i<=n-1;i++)
    {
      minj=i;
      for(j=i;j<=n-1;j++)
	{
	  if(cards2[j].su<cards2[minj].su)
	    {
	      minj=j;
	    }
	}
      //C[i] と C[minj] を交換
      de2=cards2[i].su;
      ni2=cards2[i].ki;
      cards2[i].su=cards2[minj].su;
      cards2[i].ki=cards2[minj].ki;
      cards2[minj].su=de2;
      cards2[minj].ki=ni2;
    }
  for(i=0;i<=n-1;i++)
    {
      if(cards1[i].ki!=cards2[i].ki)
	{
	  flag=1;
	}
    }
  for(i=0;i<=n-1;i++)
    {
      if(i==n-1)
	{
	  printf("%c%d\n",cards1[i].ki,cards1[i].su);
	}
      else
	{
	  printf("%c%d ",cards1[i].ki,cards1[i].su);
	}
    }
  printf("Stable\n");
  for(i=0;i<=n-1;i++)
    {
      if(i==n-1)
	{
	  printf("%c%d\n",cards2[i].ki,cards2[i].su);
	}
      else
	{
	  printf("%c%d ",cards2[i].ki,cards2[i].su);
	}
    }
  if(flag==1)
    {
      printf("Not stable\n");
    }
  else
    {
      printf("Stable\n");
    }

  return 0;
}

/*
#include <stdio.h>
#define N 36
tepedef struct
{
  char kigou;
  int suuzi;
}cardsinf;

void BubbleSort(char,int);
void SelectionSort(char,int);

int main()
{
  int casu,i;
  cardsinf cards[N];
  scanf("%d",&casu);
  for(i=0;i<casu;i++)
    {
      scanf("%c%d",&cards[i].kigou,&cards[i].suuzi);
    }

  for(i=0;i<casu;i++)
    {
      BubbleSort(cards[i].kigou,cards[i].suuzi);
      SelectionSort(cards[i].kigou,cards[i].suuzi);
    }



  for(i=0;i<casu;i++)
    {
      if(i<casu-1)
	{
	  printf("%c%d ",cards[i].kigou,cards[i].suuz);
	}
      else
	{
	  printf("%c%d",cards[i].kigou,cards[i].suuz);
	}
    }
  return 0;
}

void BubbleSort(char kigou,int suuzi)
{

}

void SelectionSort(char kigou,int suuzi)
{

}

void BubbleSort(C, N)
{
  for (i=0;i<=N-1;i++)
    {
      for (j=N-1;j>=i+1;i--)
	{
	  if (C[j].value < C[j-1].value)
	    {
	      //C[j] と C[j-1] を交換
	    }
	}
    }
}

void SelectionSort(C, N)
{
  for(i=0;i<=N-1;i++)
    {
      minj=i;
      for(j=i;j<=N-1;j++)
	{
	  if(C[j].value < C[minj].value)
	    {
	      minj=j;
	    }
	}
      //C[i] と C[minj] を交換
    }
}

*/

