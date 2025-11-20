#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  int i,j,k,l,n,minj,flag=0;
  char *num[36],*out1[36],*out2[36],*temp;
  char str[3];
  
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%s",str);
      num[i]=(char *)malloc(sizeof(char)*(2+1));
      out1[i]=(char *)malloc(sizeof(char)*(2+1));
      out2[i]=(char *)malloc(sizeof(char)*(2+1));
      strcpy(out1[i],str);
      strcpy(out2[i],str);
      strcpy(num[i],str);
      
    }
  
  for(i=0;i<n;i++)
    {
      for(j=n-1;j>i;j--)
	{
	  if(out1[j][1] < out1[j-1][1])
	    {
	      temp=out1[j];
	      out1[j]=out1[j-1];
	      out1[j-1]=temp;
	    }
	}
    }
  
  for(i=0;i<n;i++)
    {
      if(i == n-1)
	{
	  printf("%s\n",out1[i]);
	}
      else
	{
	  printf("%s ",out1[i]);
	}
    }
  
  for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
	{
	  for(k=0;k<n;k++)
	    {
	      for(l=k+1;l<n;l++)
		{
		  if(num[i][1] == num[j][1] && strcmp(num[i],out1[l]) == 0 && strcmp(num[j],out1[k]) == 0)
		    {
		      flag=1;
		    }
		}
	    }
	}
    }
  
  if(flag == 0)
    {
      printf("Stable\n");
    }
  else
    {
     printf("Not stable\n");
    }
  
  flag=0;
  
  for(i=0;i<n;i++)
    {
      minj=i;
      for(j=i;j<n;j++)
	{
	  if(out2[j][1] < out2[minj][1])
	    {
	      minj=j;
	    }
	}
      temp=out2[i];
      out2[i]=out2[minj];
      out2[minj]=temp;
    }
  
  for(i=0;i<n;i++)
    {
      if(i == n-1)
	{
	  printf("%s\n",out2[i]);
	}
      else
	{
	  printf("%s ",out2[i]);
	}
    }
  
  for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
	{
	  for(k=0;k<n;k++)
	    {
	      for(l=k+1;l<n;l++)
		{
		  if(num[i][1] == num[j][1] && strcmp(num[i],out2[l]) == 0 && strcmp(num[j],out2[k])  ==0)
		    {
		      flag=1;
		    }
		}
	    }
	}
    }
  
  if(flag==0)
       {
	 printf("Stable\n");
       }
  else
    {
     printf("Not stable\n");
    }
  
  
  return 0;
}