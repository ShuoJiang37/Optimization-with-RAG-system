#include <stdio.h>
#include <string.h>
 
int main()
{
  int i, j, n, minj, count = 0, a, b,hantei = 0;
  char c[36][3],c2[36][3], temp[3];

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      scanf("%s",c[i]);
    }

  for(i = 0; i < n; i++)
    {
      strcpy(c2[i],c[i]);
    }

  for(i = 0; i < n; i++)
    {
      for(j = n-1; j > i; j--)
	{
	  if(c[j][1] < c[j-1][1])
	    {
	      strcpy(temp,c[j]);
	      strcpy(c[j],c[j-1]);
	      strcpy(c[j-1],temp); 
	    }
	}
    }

  for(i = 0; i < n-1; i++)
    {
      printf("%s ",c[i]);
    }

  printf("%s\n",c[n-1]);
  printf("Stable\n");

  for(i = 0; i < n; i++)
    {
      minj = i;
      for(j = i; j < n; j++)
	{
	  if(c2[j][1] < c2[minj][1])
	    {
	      minj = j;
	      count++;
	    }
	}
       if(count != 0)
	{
	  strcpy(temp,c2[i]);
	  strcpy(c2[i],c2[minj]);
	  strcpy(c2[minj], temp); 
	  count = 0;
	}
    }

  for(i = 0; i < n; i++)
    {
      for(j = i+1; j < n; j++)
	{
	  for(a = 0; a < n; a++)
	    {
	      for(b = a+1; b < n; b++)
		{
		  if(c[i][1] == c[j][1] && strcmp(c[i],c2[b]) == 0 && strcmp(c[j],c2[a]) == 0)hantei = 1;
		}
	    }
	}
    }
  
  for(i = 0; i < n-1; i++)
    {
      printf("%s ",c2[i]);
    }
  
  printf("%s\n",c2[n-1]);

  if(hantei == 1)printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}

