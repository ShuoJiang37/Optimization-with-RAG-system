#include <stdio.h>
struct card{
  char mark;
  char  num;
};
void bubble (struct card [],int );
void  selection( struct card [] , int);
int judge (struct card [],struct card [],int );
void print (struct card [],int);

int main()
{
  struct card A[100],B[100];
  int n,i;
  
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf(" %c",&A[i].mark);
      scanf("%c",&A[i].num);
      
    }
  for(i= 0; i<n; i++)
    {
     
      B[i]=A[i];
    }
  
  bubble(A,n);
  selection(B,n);
  print(A,n); 
  printf("\n");     
  printf("Stable\n");
  print(B,n);
  if(judge(A,B,n) )
    {
      printf("\n");
      printf("Stable\n");
    }
  else{
    printf("\n");
    printf("Not stable\n");
  }
  
  return 0;
}

void bubble (struct card A[],int n )
{
  int i,j;
  struct card tmp;
  for(i=0;i<n;i++)
    {
      for(j=n-1;j>=i+1;j--)
	{
	  if(A[j].num < A[j-1].num ){
	    tmp=A[j];
	    A[j]=A[j-1];
	    A[j-1]=tmp;
	  }
	}
    }
}

void  selection(struct card B[], int n){
  int i,j,minj;
  struct card tmp;
  for(i=0;i<n;i++)
    {
      minj=i;
      for(j=i;j<n;j++)
	{
	  if(B[j].num < B[minj].num) minj=j;
	}
      tmp =B[minj];
      B[minj] =B[i];
      B[i] =tmp;
    }
}
int judge (struct card A[],struct card B[],int n )
{
  int i,flag =1;
  for(i=0;i<n;i++)
    {
      if(A[i].mark !=B[i].mark || A[i].num != B[i].num) flag =0;

    }
  return  flag;
}
void print (struct card A[] ,int n){
  int i;
  for(i=0;i<n;i++)
    {
      if(i!=0)printf(" ");
      printf("%c%c",A[i].mark,A[i].num);
    }
}

