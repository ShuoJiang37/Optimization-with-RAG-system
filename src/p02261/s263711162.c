#include<stdio.h>
#include<stdbool.h>
#define MAX 100

typedef struct card{
  char suit,value;
}Card;

void bubble(Card *,int);
void selection(Card *,int);
void print(Card *,int);
bool isStable(Card *,Card *,int);

void bubble(Card A[], int N)
{
  int i,j;
  Card t;
 for(i=0;i<N;i++){
   for(j=N-1;j>=i+1;j--){
     if(A[j].value<A[j-1].value){
       t= A[j];
       A[j]=A[j-1];
       A[j-1]=t;
     }
   }
  }
}

void selection(Card A[], int N)
{
  int i, j, minj;
  Card t;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j].value<A[minj].value)
	minj=j;
    }
    t=A[i];
    A[i]=A[minj];
    A[minj]=t;
  }
}

void print(Card A[],int N)
{
  int i;
  for(i=0;i<N;i++){
    if(i>0)
      printf(" ");
    printf("%c%c",A[i].suit,A[i].value);
  }
  printf("\n");
}

bool isStable(Card C1[],Card C2[], int N){
  int i;
  for(i=0;i<N;i++){
    if(C1[i].suit != C2[i].suit)
      return false;
  }
  return true;
}



int main(){
 Card C1[MAX],C2[MAX];
  int i, N;
  char A[2],ch;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%c%c%c",&ch,&C1[i].suit,&C1[i].value);
    /*scanf("%s",A);
    C1[i].suit=A[0];
    C2[i].value=A[1];
    */
  }

  /*
  printf("C1.suit: ");
  for(i=0;i<N;i++)
    printf("%c ", C1[i].suit);
  printf("\n");
  printf("C1.value: ");
  for(i=0;i<N;i++)
    printf("%c ", C1[i].value);
  printf("\n");
  */
  
  for (i=0;i<N;i++)
    C2[i]=C1[i];
  
  bubble(C1,N);
  selection(C2,N);
  
  print(C1,N);
  printf("Stable\n");
  print(C2,N);
  if(isStable(C1,C2,N))
    printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;

}
    

