#include <stdio.h>
#include <string.h>
typedef struct {
  char mark;
  int value;
  int prev;
}Card;
   
void swap(Card *in,Card *out)
{
  Card temp;
  int i,j;
  temp.mark = out->mark;
  temp.value = out->value;
  temp.prev = out->prev;
  out->mark = in->mark;
  out->value = in->value;
  out->prev = in->prev;
  in->mark = temp.mark;
  in->value = temp.value;
  in->prev = temp.prev;
}
   
void Print(Card *in,int num)
{
  int i;
  for(i=0;i<num;i++)
    {
      printf("%c%d",in[i].mark,in[i].value);
      //     printf("%d",in[i].prev);
      if (i<num-1) printf(" ");
    }
  printf("\n");
}
int hantei(Card *kai,int num) 
{
  int i;
  for (i=0;i<num;i++)
    {
      if(kai[i].value == kai[i+1].value)
        {
	  if (kai[i].prev < kai[i+1].prev) continue;
	  else return 1;
	}
    }
  return 0;
}
  
int main()
{
  int i,j;
  int num,mini;
  int stable=0;
  Card A[36],B[36],C[36];
   
  scanf("%d",&num);
  for (i=0;i<num;i++)
    {
      scanf(" %c%d",&A[i].mark,&A[i].value);
      B[i].mark = A[i].mark;
      B[i].value = A[i].value;
      C[i].mark = A[i].mark;
      C[i].value = A[i].value;
      A[i].prev = i;
      B[i].prev = i;
      C[i].prev = i;
    }

  /*bubble sort*/
  for (i=0;i<num;i++)
    {
      for (j=num-1;j>i;j--)
	{
	  if ( A[j].value < A[j-1].value) swap(&A[j],&A[j-1]);
	}
    }
  Print(A,num);
  stable=hantei(A,num);
  if(stable == 1) printf("Not stable\n");
  else printf("Stable\n");
   
  /*select sort*/
  for(i=0;i<num;i++)
    {
      mini=i;
      for(j=i;j<num;j++)
	{
	  if (B[j].value < B[mini].value ) mini=j;
	}
      swap(&B[i],&B[mini]);
    }
  Print(B,num);
  stable = hantei(B,num);
  if(stable == 1) printf("Not stable\n");
  else printf("Stable\n");
  return 0;
}