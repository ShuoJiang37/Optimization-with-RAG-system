#include<stdio.h>
#include<stdlib.h>

int selectionSort(int num[],int len);

int main(void)
{
  int i,count;
  int len;
  int *num;

  scanf("%d",&len);
  
  num=calloc(len,sizeof(int));

  for(i=0;i<len;i++)
    {
      scanf("%d",&num[i]);
    }

  count=selectionSort(num,len);

  for(i=0;i<len;i++)
    {
      printf("%d",num[i]);

      if(i!=len-1)
	{
	  putchar(' ');
	}
    }
  
  putchar('\n');

  printf("%d\n",count);
  
  return 0;
}


int selectionSort(int num[],int len)
{
  int i,j,min,tmp,count=0;
  
  for(i=0;i<len-1;i++)
    {
      min=i;
      
      for(j=i;j<len;j++)
	{
	  if(num[j]<num[min])
	    {
	      min=j;
	    }
	}
      
      tmp=num[i];
      num[i]=num[min];
      num[min]=tmp;

      if(i!=min)
	{
	  count++;
	}
    }
  
  return count;
}

