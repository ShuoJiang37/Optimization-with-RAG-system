#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 36

int main()
{
  int i, j, min, num, tem, sflag=0, flag=0;
  int count = 0;
  char barray[N][3], sarray[N][3];
  char temp[3];
  char a[N];
  int n[N];

  scanf("%d", &num);

  for(i=0;i<num;i++)
    {
      scanf("%s", barray[i]);
      strcpy(sarray[i],barray[i]);
      a[i] = barray[i][0];
      n[i] = atoi(&barray[i][1]);
    }

  /*for(i = 0; i < num; i++)
    {
      printf("%d ", n[i]);
    }
    printf("\n");*/
    
  for( i = 0; i < num-1; i++)
    {
      for( j = num-1; j >= i+1; j--)
	{
	  if(n[j] < n[j-1])
	    {
	      if(n[j] == n[j-1])sflag = 1;
	      tem = n[j];
	      n[j] = n[j-1];
	      n[j-1] = tem;
	      
	      strcpy(temp, barray[j]);
	      strcpy(barray[j], barray[j-1]);
	      strcpy(barray[j-1], temp);
	    }
	}
    }
  
  for( i = 0; i < num-1; i++)
    {
      printf("%s ", barray[i]);
    }
  printf("%s\n", barray[num-1]);
  if(sflag)printf("Not stable\n");
  else printf("Stable\n");

  flag = 0;
  sflag = 0;
   for(i=0;i<num;i++)
    {
      a[i] = sarray[i][0];
      n[i] = atoi(&sarray[i][1]);
    }
   
  for (i = 0; i < num-1; i++)
    {
      min = i;
      for (j = i + 1; j < num; j++)
	{
	  if (n[j] < n[min])
	    {
	      min = j;
	      flag = 1;
	    } 
	}
      if(flag)
	{
	  for(j=min-1;j>i;j--)
	    {
	      if(n[i]==n[j])sflag=1;
	    }
      tem = n[i];
      n[i] = n[min];
      n[min] = tem;

      strcpy(temp, sarray[i]);
      strcpy(sarray[i], sarray[min]);
      strcpy(sarray[min], temp);
      
      count++;
      flag = 0;
	}
    }
  
  for(i = 0; i < num-1; i++)
    {
      printf("%s ", sarray[i]);
    }
  printf("%s\n", sarray[num-1]);
  if(sflag)printf("Not stable\n");
  else printf("Stable\n");
 
  return 0;
}

