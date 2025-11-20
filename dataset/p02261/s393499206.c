#include <stdio.h>

int ANTEI(char *,int *,char *,int *);

int main()
{
  int n,i,j,flag,min,koukan;
  char change;

  scanf("%d",&n);

  char A[n],As[n];//アルファベットを入れる配列
  int B[n],Bs[n];//数字を入れる配列

  for(i=0;i<n;i++)
    {
      scanf(" %c%d",&A[i],&B[i]);
      As[i]=A[i];
      Bs[i]=B[i];
    }

  for(i=0;i<n;i++)
    {
      /*バブルソート*/
      for(j=n-1;j>i;j--)
	{
	  if(B[j]<B[j-1])
	    {
	      change=A[j-1];
	      A[j-1]=A[j];
	      A[j]=change;

	      koukan=B[j-1];
	      B[j-1]=B[j];
	      B[j]=koukan;
	    }
	}
      
      /*選択ソート*/
      min=i;
      for(j=i+1;j<n;j++)
	{
	  if(Bs[j]<Bs[min])min=j;
	}
      if(min!=i)
	{
	  change=As[min];
	  As[min]=As[i];
	  As[i]=change;

	  koukan=Bs[min];
	  Bs[min]=Bs[i];
	  Bs[i]=koukan;
	}
    }
  /*安定デスカ？*/
  flag=1;
  for(i=0;i<n;i++)
    {
      if(A[i]!=As[i])
	{
	  flag=0;
	  break;
	}
    }
  /*出力*/
  /*バブルソート*/
  for(i=0;i<n-1;i++)printf("%c%d ",A[i],B[i]);
  printf("%c%d\n",A[n-1],B[n-1]);
  printf("Stable\n");
  /*選択ソート*/
   for(i=0;i<n-1;i++)printf("%c%d ",As[i],Bs[i]);
  printf("%c%d\n",As[n-1],Bs[n-1]);
  if(flag==0)printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}
