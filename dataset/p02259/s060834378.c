#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int num[],int com,int *count);

int main(void)
{
  int *num;
  int com;
  int i;
  int count=0;

  scanf("%d",&com);

  num=calloc(com,sizeof(int));

  for(i=0;i<com;i++)
    {
      scanf("%d",&num[i]);
    }

  bubbleSort(num,com,&count);

  for(i=0;i<com;i++)
    {
      printf("%d",num[i]);

      if(i!=com-1)
	printf(" ");
    }
  
  putchar('\n');

  printf("%d\n",count);
  
  free(num);
  
  return 0;
}


void bubbleSort(int num[],int com,int *count)
{
  int i,j,tmp;


  for(i=0;i<com-1;i++)
    {
      for(j=com-1;j>i;j--)
	{
	  if(num[j-1]>num[j])
	    {
	      tmp=num[j-1];
	      num[j-1]=num[j];
	      num[j]=tmp;
	      (*count)++;
	    }
	}
    }
}

