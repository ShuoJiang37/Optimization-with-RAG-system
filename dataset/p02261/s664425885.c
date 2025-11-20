#include <stdio.h>
#include <stdlib.h>
 
int main()
{ 
  int i,j,min,n;
  int C[50][2],ki[50][2],syo[50][2];
  int N;
  int tmp1;
  char tmp2,str[3];

 
  scanf("%d",&N);
 
  for(i=1; i<=N;i++)
    {
      scanf("%s",str);
      C[i][0] = ki[i][0] = syo[i][0] = atoi(&str[1]);
      C[i][1] = ki[i][1] = syo[i][1] = str[0];
    }
 
  for (i=1; i<=N; i++)
    {
      for (j=N; j>=i+1; j--)
	{
 
	  if(ki[j][0] < ki[j-1][0])
	    {
     
	      tmp1 = ki[j][0];
	      tmp2 = ki[j][1];
	      ki[j][0] = ki[j-1][0];
	      ki[j][1] = ki[j-1][1];
	      ki[j-1][0] = tmp1;
	      ki[j-1][1] = tmp2;
    
	    }
	}
    }

  for (i=1; i<=N; i++)
    {
      min = i;
      for (j=i; j<=N; j++)
	{
	  if(syo[j][0] < syo[min][0])
	    {
	      min = j;
	    }
	}

      if(i != min)
	{
  
	  tmp1 = syo[i][0];
	  tmp2 = syo[i][1];
	  syo[i][0] = syo[min][0];
	  syo[i][1] = syo[min][1];
	  syo[min][0] = tmp1;
	  syo[min][1] = tmp2;
	
	}
      
    }
  
  n = 1;
  
  for (i=1; i<=N; i++)
    {
      printf("%c%d",ki[i][1],ki[i][0]);
      
      if(n == 1 && i > 1 && ki[i][0] == ki[i-1][0])
	{
	  for(j=1; j<=N; j++)
	    {
	      if(C[j][0] == ki[i][0] && C[j][1] == ki[i][1])
		{
		  n = 0;
		  break;
		}
	      if(C[j][0] == ki[i-1][0] && C[j][1] == ki[i-1][1])
		{
		  break;
		}
	    }
	}
    
      if(i!=N)
	{
	  printf(" ");
	}
    }
  
  printf("\n");
  if(n == 1)
    {
      printf("Stable");
    }
  else{
    printf("Not stable");
  }
  printf("\n");
  
  n = 1;
  
  for (i=1; i<=N; i++)
    {
      printf("%c%d",syo[i][1],syo[i][0]);
  
  
      if(n == 1 && i > 1 && syo[i][0] == syo[i-1][0])
	{
	  for(j=1; j<=N; j++)
	    {
	      if(C[j][0]==syo[i][0] && C[j][1]== syo[i][1])
		{
		  n = 0;
		  break;
		}
	      if(C[j][0] == syo[i-1][0] && C[j][1] == syo[i-1][1])
		{
		  break;
		}
	    }
	}
  
      if(i != N)
	{
	  printf(" ");
	}
    }
  
  printf("\n");
  if(n == 1)
    {
      printf("Stable");
    }
  else{
    printf("Not stable");
  }
  printf("\n");
 
  return 0;
  
}