#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 36

struct Card{
  char str[2];
  int num;
};

int main()
{
  int N,i,flag=1,j,minj,judge=0;
  struct Card A[MAX],temp,B[MAX];
  char *moji;

  scanf("%d",&N);
  if( N < 1 || MAX < N ) exit(2);

  for( i = 0 ; i < N ; i++ )
    {
      scanf("%s",&A[i].str);
      A[i].num = atoi(&A[i].str[1]);
         if( A[i].str[0] != 'H' && A[i].str[0] != 'S' &&
    A[i].str[0] != 'D' && A[i].str[0] != 'C') exit(3);
    if( A[i].num < 1 || 9 < A[i].num ) exit(4);
      B[i] = A[i];
    }
 


  i = 0;
  while( flag != 0 )
    {
      flag = 0;
      for( j = N-1 ; j >= i+1 ; j-- )
	{
	  if( A[j].num < A[j-1].num )
	    {	
	      temp = A[j];
	      A[j] = A[j-1];
	      A[j-1] = temp;
	      flag = 1;
	    } 
	}
      i++;
    }

  for( i = 0 ; i < N ; i++ )
    {
      minj=i;
      for( j = i+1 ; j < N ; j++ )
	{
	  if( B[j].num < B[minj].num )
	    minj = j;
	}
      if( i != minj )
	{
	  temp = B[i];
	  B[i] = B[minj];
	  B[minj] = temp;
	}
    }
  
  for( i = 0 ; i < N ; i++ )
    {
      if( strcmp(A[i].str,B[i].str)  != 0)
	{
 moji = "Not stable";
 judge=1;
 break;
	}
    }
  if(judge == 0 ) moji = "Stable";
  for( i = 0 ; i < N-1 ; i++ ) 
    {
      printf("%c%d ",A[i].str[0],A[i].num);
    }
  printf("%c%d\nStable\n",A[i].str[0],A[i].num);

 for( i = 0 ; i < N-1 ; i++ ) 
    {
      printf("%c%d ",B[i].str[0],B[i].num);
    }
 printf("%c%d\n%s\n",B[i].str[0],B[i].num,moji);

  return 0;
}