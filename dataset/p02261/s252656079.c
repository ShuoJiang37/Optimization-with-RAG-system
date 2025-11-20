//Stable sort

#include<stdio.h>
#define N 100
#define TRUE 1
#define FALSE 0

typedef struct
{
  char suit;
  int num;
}card;

int main()
{
  int i,j,n;
  card arr1[N],arr2[N], swit;
  
  //input data
  scanf("%d",&n);
  for(i = 0; i < n; i++)  scanf(" %c%d",&arr1[i].suit, &arr1[i].num);
    
  //initialize a array2 for selection sort
  for(i = 0; i < n; i++) arr2[i] = arr1[i];

  //bubble
  for(i = 0; i < n-1; i++)
    {
      for(j = n - 1; j >= i+1; j--)
	{
	  swit = arr1[j];
	  if(arr1[j].num < arr1[j-1].num)
	    {
	      arr1[j] = arr1[j-1];
	      arr1[j-1] = swit;
	    }
	}
    }

  //select
  for(i = 0; i < n-1; i++)
    {
      int min = i;
      for(j = i; j < n; j++)
	{
	  if(arr2[j].num < arr2[min].num) min = j;
	}
      card swit = arr2[i];
      arr2[i] = arr2[min];
      arr2[min] = swit;
    }

  //check stable
  int judge = 1;
  for(i = 0; i < n; i++)
    {
      if(arr1[i].suit != arr2[i].suit) judge = 0;
    }

  //output data
  for(i = 0; i < n; i++)
    {
      if(i > 0) printf(" ");
      printf("%c%d",arr1[i].suit,arr1[i].num);
    }
  printf("\n");
  printf("Stable\n");

  for(i = 0; i < n; i++)
    {
      if(i > 0) printf(" ");
      printf("%c%d",arr2[i].suit,arr2[i].num);
    }
  printf("\n");

  if(judge) printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;
}

