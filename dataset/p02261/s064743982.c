#include <stdio.h>
#include <stdlib.h>

typedef struct tp{
  char suit;
  int value;
}TP;

void BubbleSort(TP *,int);
void SelectionSort(TP *,int);
void output(TP *,int);
int hantei(TP *,TP *,int);
  
int main()
{
  int N,i;
  TP C1[36],C2[36];

  scanf("%d",&N);
  if(N<1 || N>36) exit(1);
  for(i=0;i<N;i++){
    scanf(" %c%d",&C1[i].suit,&C1[i].value);
    C2[i] = C1[i];
  }
  
  BubbleSort(&C1[0],N);
  SelectionSort(C2,N);
 
  output(C1,N);
  printf("Stable\n"); /*バブルソートは絶対に安定*/
  output(C2,N);
  if(hantei(C1,C2,N) == 0) printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}

void BubbleSort(TP C[],int N)
{
  int i,j,flag=1;
  TP tmp;
  
  /*
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(C[j].value < C[j-1].value){
	tmp = C[j];
	C[j] = C[j-i];
	C[j-1] = tmp;
      }
    }
  }
  */

  while(flag)
    {
      flag=0;
      for(i=N-1;i>0;i--)
	{
	  if(C[i].value < C[i-1].value)
	    {
	      tmp = C[i];
	      C[i] = C[i-1];
	      C[i-1] = tmp;
	      flag=1;
	    }
	}
    }
}

void SelectionSort(TP C[],int N)
{
  int i,j,minj;
  TP tmp;

  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(C[j].value < C[minj].value)
	minj = j;
    }
    tmp = C[i];
    C[i] = C[minj];
    C[minj] = tmp;
  }
}

void output(TP C[],int N)
{
  int i;
  
  for(i=0;i<N;i++){
    if(i) printf(" ");
    printf("%c%d",C[i].suit,C[i].value);
  }
  printf("\n");
}

int hantei(TP C1[],TP C2[],int N)
{

  int i;
  
  for(i=1;i<N;i++){
      if(C1[i].suit != C2[i].suit) return 0;
  }
  return 1;
				  
}

