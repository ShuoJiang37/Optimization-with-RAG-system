#include <stdio.h>

typedef struct{
  char m;
  int value;
} CA;

int isStable(CA *,CA *,int);

int main()
{
  int i,j,n,k,o,minj;
  char null,e;
  scanf("%d",&n);
  CA C[36],B[36];
  for(k=0;k<n;k++)
    {
      scanf(" %c%d",&C[k].m,&C[k].value);
      B[k].m=C[k].m;
      B[k].value=C[k].value;
    }
  
  //baburu
  for(i=0;i<=n-1;i++)
    {
      for(j=n-1;j>=i+1;j--)
	{
	  if(C[j].value<C[j-1].value)
	    {
	      o = C[j].value;
	      C[j].value = C[j-1].value;
	      C[j-1].value = o;
	      e = C[j].m;
	      C[j].m = C[j-1].m;
	      C[j-1].m = e;
	    }
	}
    }
	      
  for(k=0;k<n-1;k++)
    {
      printf("%c%d ",C[k].m,C[k].value);
    }
  printf("%c%d\n",C[n-1].m,C[n-1].value);
  printf("Stable\n");

  //sentaku
  for(i=0;i<=n-1;i++)
    {
      minj=i;
      for(j=i;j<=n-1;j++)
	{
          if(B[j].value<B[minj].value)
	    {
	      minj=j;
	    }
	}
      if(i!=minj)
	{
	  o=B[i].value;
	  B[i].value=B[minj].value;
	  B[minj].value=o;
	  e = B[i].m;
	  B[i].m = B[minj].m;
	  B[minj].m = e;
	}
    }

  for(k=0;k<n-1;k++)
    {
      printf("%c%d ",B[k].m,B[k].value);
    }
  printf("%c%d\n",B[n-1].m,B[n-1].value);

  if(isStable(C,B,n)==1)printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

int isStable(CA *c,CA *d,int n)
{
  int i,j,a,b;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++)
	  {
	    if(c[i].value==c[j].value && c[i].value==d[b].value &&c[j].value == d[a].value &&c[i].m==d[b].m &&c[j].m == d[a].m)return 0;
	}
      }
    }
  }
  return 1;
}

