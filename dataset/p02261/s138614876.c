#include<stdio.h>

typedef struct model{
  char suit;
  int num;

}Card;

int BubbleSort(Card [], int);
int SelectionSort(Card [], int);
int Compare(Card [], Card[], int);

int main()
{
  int n;
  int i;
  Card A[40]={};
  Card B[40]={};
  char card[3];
  
  scanf("%d",&n);

  for(i=0;i < n;i++){
    scanf("%s",card);
    A[i].suit = card[0];
    A[i].num = (int)(card[1]-'0');

    B[i] = A[i];
  }

  BubbleSort(A,n);
  for(i=0;i < n;i++){
    if(i) printf(" ");
    printf("%c%d",A[i].suit, A[i].num);
  }
  printf("\n");
  printf("Stable\n");

  SelectionSort(B,n);
  for(i=0;i < n;i++){
    if(i) printf(" ");
    printf("%c%d",B[i].suit, B[i].num);
  }
  printf("\n");
  
  if( Compare(A,B,n) ){
    printf("Stable\n");
  }
  else printf("Not stable\n");

  return 0;
}

int BubbleSort(Card A[],int n)
{
  int i,j;
  Card temp;
  
  for(i=0;i < n;i++){
    for(j=n-1;j > i;j--){
      if(A[j-1].num > A[j].num){
	temp = A[j-1];
	A[j-1] = A[j];
	A[j] = temp;
      }
    }
  }
  return 0; 
}

int SelectionSort(Card A[],int n)
{
  int i,j;
  
  int mini;
  Card temp;
  
  for(i=0;i < n;i++){
    mini = i;
    
    for(j = i+1;j < n;j++){
      if(A[j].num < A[mini].num) mini = j;
    }
    
    temp = A[mini];
    A[mini] = A[i];
    A[i] = temp;
  }
  return 0; 
}

int min(int a, int b)
{
  if(a < b) return a;
  else return b;
}

int Compare(Card A[], Card B[], int n)
{
  int i;

  for(i=0;i < n;i++){
    if(A[i].suit != B[i].suit){
      return 0;
    }
  }
  return 1;
}

