#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 36
int main()
{
  int i, j, n, minj, value, a, b, flag = 0; 
  char *C[N],  *out1[N], *out2[N], *temp, str[3];
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++)
    {
      scanf("%s",str);
      C[i] =(char *)malloc(3);
      out1[i] =(char *)malloc(3);
      out2[i] =(char *)malloc(3);
      strcpy(C[i],str);
      strcpy(out1[i],str);
      strcpy(out2[i],str);
    }

  for(i = 0 ; i < n ; i++)
    {
      for(j = n - 1 ; j > i ; j--)
	{
	  if(out1[j][1] < out1[j-1][1])
	    {
	      temp = out1[j];
	      out1[j] = out1[j-1];
	      out1[j-1] = temp;
	     
	    }
	}
    }

  for(i = 0 ; i < n ; i++)
    {
      if(i == n - 1){
	printf("%s\n",out1[i]);
      } else{
	printf("%s ",out1[i]);
      }
    }
  for(i = 0 ; i < n ; i++)
    {
      for(j = i + 1 ; j < n ; j++)
	{
	  for(a = 0 ; a < n ; a++)
	    {
	      for(b = a + 1 ; b < n ; b++)
		{
		  if(C[i][1] == C[j][1] && strcmp(C[i],out1[b]) == 0 && strcmp(C[j],out1[a]) == 0)
		    {
		      flag = 1;
		    }
		}
	    }
	}
    }
  if(flag == 0){ printf("Stable\n");
  } else{ 	printf("Not stable\n");
  }
  flag = 0;
  for(i = 0 ; i < n ; i++ )
    {
      minj = i;
      for(j = i ; j < n ; j++)
	{
	  if(out2[j][1] < out2[minj][1]){
	    minj = j;
	  }
	} 
      temp = out2[i];
      out2[i] = out2[minj];
      out2[minj] = temp;
    }
  for(i = 0 ; i < n ; i++)
    {
      if(i == n - 1){
	printf("%s\n",out2[i]);
      } else{
	printf("%s ",out2[i]);
      }
    }
  for(i = 0 ; i < n ; i++)
    {
      for(j = i + 1 ; j < n ; j++)
	{
	  for(a = 0 ; a < n ; a++)
	    {
	      for(b = a + 1 ; b < n ; b++)
		{
		  if(C[i][1] == C[j][1] && strcmp(C[i],out2[b]) == 0 && strcmp(C[j],out2[a]) == 0)
		    {
		      flag = 1;
		    }
		}
	    }
	}
    }
  if(flag == 0){ printf("Stable\n");
  }else{ 	printf("Not stable\n");
  }
  return 0;
}