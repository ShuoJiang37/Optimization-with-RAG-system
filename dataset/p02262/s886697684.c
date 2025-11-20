#include <stdio.h>

void insertionSort(int *,int,int);
void shellSort(int *,int);

int count;

int main()
{
  int i,n;

  /*入力*/
  
  scanf("%d",&n);

  int s[n];

  for(i=0;i<n;i++)scanf("%d",&s[i]);

  shellSort(s,n);//シェルソート
  
  printf("%d\n",count);//回数表示
  for(i=0;i<n;i++)printf("%d\n",s[i]);//値表示
  return 0;
}

void shellSort(int *s,int n)
{
  int i,g[n],m=0;

  /*漸化式gの定義*/
  
  g[m]=0;
  
  while(1)
    {
      g[m+1]=( 3*(g[m]) )+1;
      if(g[m+1]>n)break;
      m++;
      
    }

  /*m,gを表示*/
  
  printf("%d\n",m);
  
  for(i=m;i>0;i--)
    {
      if(i==1)printf("%d\n",g[1]);
      else printf("%d ",g[i]);
    }

  for(i=m;i>0;i--)
    {
      insertionSort(s,n,g[i]);
    }
}
void insertionSort(int *s,int n,int g)
{
  int i,j,ireru;
  
  for(i=g;i<n;i++)
    {
      ireru=s[i];
      j=i-g;
      
      while(j>=0&&s[j]>ireru)
	{
	  s[j+g]=s[j];
	  j=j-g;
	  count++;
	}
      s[j+g]=ireru;
      }
}
  
      
      
      
  
  

