#include<stdio.h>

typedef struct{
  char fig;
  int num;
  }Card;

void bubblesort(Card *,int);
void selectionsort(Card *,int);
void print(Card *,int);
int judge(Card *,Card *,int);
void change1(char *,char *);
void change2(int *,int *);

void bubblesort(Card *A,int N)
{
  int i,j;

  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--) {
        if(A[j].num < A[j-1].num) {
       change1(&A[j].fig,&A[j-1].fig);
       change2(&A[j].num,&A[j-1].num);
      }
    }
  }
}


void selectionsort(Card *A,int N)
{
  int minj,i,j;

  for(i=0;i<N;i++) {
    minj = i;
    for(j=i;j<N;j++){
      if(A[j].num < A[minj].num) 
	minj = j;
    }
      change1(&A[i].fig,&A[minj].fig);
      change2(&A[i].num,&A[minj].num);
  }
}

void change1(char *a,char *b)
{
  char ex = *a;
  *a = *b;
  *b = ex;
}

void change2(int *a,int *b)
{
  int ex = *a;
  *a = *b;
  *b = ex;
}

void print (Card *A,int N)
{
  int i;

  for(i=0;i<N;i++) {
    if(i) printf(" ");
    printf("%c%d",A[i].fig,A[i].num);
  }
  printf("\n");
}


int judge (Card *A,Card *B,int N)
{
  int i;
  for(i=0;i<N;i++)
    if(A[i].fig != B[i].fig) {
      return 0;
    }
      return 1;
}
  

int main()
{
  Card A[40],B[40];
  int N,i;
  char ch;
  
  scanf("%d%c",&N,&ch);
  for(i=0;i<N;i++)
    scanf("%c%d%c",&A[i].fig,&A[i].num,&ch);

  for(i=0;i<N;i++) {
    B[i].fig = A[i].fig;
    B[i].num = A[i].num;
  }

  bubblesort(A,N);
  selectionsort(B,N);

  print(A,N);
  printf("Stable\n");
  print(B,N);
  if(judge(A,B,N)) {
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  return 0;
}

