#include<stdio.h>
#include<string.h>

int main()
{
  int i,n,j,flag=1,minj,k=0;
  char C[36][3],t[3],str[36][3];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%s",C[i]);
    }
  for(i=0;i<n;i++)
    {
      strcpy(str[i],C[i]);
    }
  
  i=0;
  while(flag)
    {
      flag=0;
      for(j=n-1;j>=i+1;j--)
	{
	  if(C[j][1]<C[j-1][1])
	    {
	      strcpy(t,C[j]);
	      strcpy(C[j],C[j-1]);
	      strcpy(C[j-1],t);
	      flag=1;
	      
	    }
	}
      i++;
    }

  for(i=0;i<n-1;i++)
    {
      printf("%s ",C[i]);
    }
  printf("%s\n",C[i]);
  printf("Stable\n");

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++)
      {
	if(str[j][1]< str[minj][1])
	  {
	    minj=j;
	  } 
      }  
    if(i!=minj)
      {
	strcpy(t,str[i]);
	strcpy(str[i],str[minj]);
	strcpy(str[minj],t);
      }
  }

  for(i=0;i<n-1;i++)
    {
      printf("%s ",str[i]);
    }
  printf("%s\n",str[i]);
  flag=1;
  for(i=0;i<n;i++)
    {
      if(strcmp(&C[i][0],&str[i][0])!=0 && k==0)
	{
	  printf("Not stable\n");
	  flag=0;
	  k++;
	}
    }
  if(flag==1)
    {
      printf("Stable\n");
    }


  return 0;
}