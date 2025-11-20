#include <stdio.h>
#include <string.h>
int main()
{
  int n,i,j=0,minj=0,flag=0;
  char c[37][3],k[3],c2[37][3];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%s",c[i]);
   for(i=0;i<n;i++)strcpy(c2[i],c[i]);
  for(i=0;i<=n-1;i++)
    {
      for(j=n-1;j>=i+1;j--)
	{
	  if(c[j][1]<c[j-1][1])
	    {
	      strcpy(k,c[j]);
	      strcpy(c[j],c[j-1]);
	      strcpy(c[j-1],k);
	    }
	}
    }
  for(i=0;i<n-1;i++)printf("%s ",c[i]);
  printf("%s\n",c[i]);
  printf("Stable\n");

  for(i=0;i<n-1;i++)
    {
      minj = i;
      for(j=i;j<=n-1;j++)
	{
	  if(c2[j][1] < c2[minj][1])minj=j;
	}
      if(c2[i][1]>c2[minj][1])
	{
	  strcpy(k,c2[i]);
	  strcpy(c2[i],c2[minj]);
	  strcpy(c2[minj],k);
	}
    }
  for(i=0;i<n-1;i++)printf("%s ",c2[i]);
  printf("%s\n",c2[i]);

  for(i=0;i<n;i++)
    {
      flag = strcmp(c[i],c2[i]);
      if(flag != 0)
	{
	  printf("Not stable\n");
	  break;
	}
    }
  if(flag == 0)printf("Stable\n");
  return 0;
}


