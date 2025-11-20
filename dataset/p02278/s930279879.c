#include <stdio.h>

#define MAX 10001

typedef struct{
  int kazu;
  int hantei;
}weight;
  
int Kosu[MAX],Doko1[MAX],Doko2[MAX+1];

int main()
{
  int n,i,j,basho=0,min,min2,hazime,sumW=0,w1,w2,omosa,irekae,kosu,SUM=0;

  scanf("%d",&n);

  int seiretu[n];
  weight Wi[n];

  /*整列させてる(Counting Sort)*/
  
  for(i=0;i<n;i++)
    {
      scanf("%d",&Wi[i].kazu);
      Wi[i].hantei=0;
      Kosu[Wi[i].kazu]++;
    }
  
  for(i=0;i<10001;i++)
    {
      basho+=Kosu[i];
      Doko1[i]=basho-1;
      Doko2[i]=Doko1[i];
    }

  for(i=0;i<n;i++)
    {
      seiretu[ Doko1[Wi[i].kazu] ]=Wi[i].kazu;
      Doko1[Wi[i].kazu]--;
    }

  /*最小コストをもとめる*/

  min=seiretu[0];

  for(i=0;i<n;i++)
    {
      if(Wi[i].kazu!=seiretu[i]&&Wi[i].hantei==0)
	{
	  /*初期化*/
	  j=1001;
	  kosu=0;
	  sumW=0;
	  min2=10001;
	  omosa=Wi[i].kazu;
	  Wi[i].hantei=1;
	  
	  while(j!=i)
	    {
	      kosu++;
	      if(min2>omosa)min2=omosa;
	      sumW+=omosa;
	      for(j=0;j<n;j++)
		{
		  if(omosa==seiretu[j])break;
		}
	      Wi[j].hantei=1;
	      omosa=Wi[j].kazu;
	    }
	  
	  w1=sumW+( (kosu-2)*min2 );
	  w2=sumW+min2+( (kosu+1)*min );
	  
	  if(w1<w2)SUM+=w1;
	  else SUM+=w2;
	}
    }

  printf("%d\n",SUM);
	  
      
  return 0;
}

