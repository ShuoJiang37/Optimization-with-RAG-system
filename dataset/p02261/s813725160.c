#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int i, j, N, minj;
  char store[36][3], Bubble[36][3], Select[36][3], temp[3];

  
  scanf("%d", &N);

  for( i=0; i<N; i++ )
    {
      scanf("%s", store[i]);
      strcpy(Bubble[i],store[i]);
      strcpy(Select[i],store[i]);
    }

  
  for( i=0; i<N; i++ )
    {
      for( j=N-1; j>=i+1; j-- )
	{
	  
	  if( Bubble[j][1] < Bubble[j-1][1] )
	    {
	      strcpy(temp,Bubble[j]);
	      strcpy(Bubble[j],Bubble[j-1]);
	      strcpy(Bubble[j-1],temp);
	    }
	}
      

      minj = i;
      
      for( j=i; j<N; j++ )
	{
	  if( Select[j][1] < Select[minj][1] ) minj = j;    
	}

      if( minj != i);
      {
	strcpy(temp, Select[i]);
	strcpy(Select[i],Select[minj]);
	strcpy(Select[minj],temp);
      }


      printf("%s", Bubble[i]);
      
      if( i == N-1 )
	{
	  printf("\n");
	  break;
	}
      printf(" ");
      
    }
  
  printf("Stable\n");
  

  for( i=0; i<N; i++ )
    {
      printf("%s", Select[i]);
      if( i == N-1 )
	{
	  printf("\n");
	  break;
	}
      printf(" ");
    }

  for( i=0; i<N; i++ )
    {
      if( Bubble[i][0] != Select[i][0] && Bubble[i][1] != Select[i][0] )
	{
	  printf("Not stable\n");
	  return 0;
	}
    }
  
  printf("Stable\n");
  
  return 0;
}

  

	  
	      

