#include <stdio.h>

int ANTEI(char *,int *,char *,int *);

int main()
{
  int n,i,j,flag,min,tmp;
  char change;

  scanf("%d",&n);

  char a[n],as[n];
  int b[n],bs[n];

  for(i=0;i<n;i++)
    {
      scanf(" %c%d",&a[i],&b[i]);
      as[i]=a[i];
      bs[i]=b[i];
    }

  for(i=0;i<n;i++)
    {
      /*バブルソート*/
      for(j=n-1;j>i;j--)
	{
	  if(b[j]<b[j-1])
	    {
	      change=a[j-1];
	      a[j-1]=a[j];
	      a[j]=change;

	      tmp=b[j-1];
	      b[j-1]=b[j];
	      b[j]=tmp;
	    }
	}
      
      /*選択ソート*/
      min=i;
      for(j=i+1;j<n;j++)
	{
	  if(bs[j]<bs[min])min=j;
	}
      if(min!=i)
	{
	  change=as[min];
	  as[min]=as[i];
	  as[i]=change;

	  tmp=bs[min];
	  bs[min]=bs[i];
	  bs[i]=tmp;
	}
    }
  
  flag=1;
  for(i=0;i<n;i++)
    {
      if(a[i]!=as[i])
	{
	  flag=0;
	  break;
	}
    }
 
  for(i=0;i<n-1;i++)printf("%c%d ",a[i],b[i]);
  printf("%c%d\n",a[n-1],b[n-1]);
  printf("Stable\n");
  
   for(i=0;i<n-1;i++)printf("%c%d ",as[i],bs[i]);
  printf("%c%d\n",as[n-1],bs[n-1]);
  if(flag==0)printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}

