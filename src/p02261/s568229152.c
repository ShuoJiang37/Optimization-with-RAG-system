#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct card{
  char suit;
  int num;
};

void swap(struct card *A, struct card *B);

int main()
{

  struct card A_Bub[36],A_Sel[36];
    
  int N,i,j,min,count=0;
  char num,str1[4],str2[3],temp_c;
  
  scanf("%d",&N);
  
  for(i=0;i<N;i++)
    {
      scanf("%s",str1);
      strncpy(str2,str1+1,strlen(str1)-1);
      num=atoi(str2);
    
      A_Bub[i].suit = A_Sel[i].suit=str1[0];
      A_Bub[i].num = A_Sel[i].num=num; 
    }

  //bubble sort
  for(i=0;i<N;i++)
    {
      for(j=N-1;j>i;j--)
	{
	  if(A_Bub[j].num<A_Bub[j-1].num) swap(&A_Bub[j],&A_Bub[j-1]);	 
	}
    }

  //print
  for(i=0;i<N;i++)
    {
      printf("%c%d",A_Bub[i].suit,A_Bub[i].num);
      if(i!=N-1) printf(" ");
    }
  printf("\n");

  //stability
  printf("Stable\n"); //バブルソートでは安定

  
  //selection sort
  for(i=0;i<N;i++)
    {
      min=i;
      for(j=i;j<N;j++)
	{
	  if(A_Sel[j].num < A_Sel[min].num) min=j;
	  count++;
	}
      swap(&A_Sel[i],&A_Sel[min]); 
    }

  //print
  for(i=0;i<N;i++)
    {
      printf("%c%d",A_Sel[i].suit,A_Sel[i].num);
      if(i!=N-1) printf(" ");
    }
  printf("\n");

  //stability
  for(i=0;i<N;i++)
    {
      if(A_Sel[i].suit!=A_Bub[i].suit && A_Sel[i].num==A_Bub[i].num)
	{
	printf("Not stable\n");
	return 0;
	}
    }

  printf("Stable\n");
  return 0;
}

void swap(struct card *A, struct card *B){

  struct card temp;
  temp = *B;
  *B = *A;
  *A = temp;

  return;
}

