#include <stdio.h>
#include<string.h>
#define N 36
#define TRUE 1
#define FALSE 0

typedef struct{
  char mark;
  short number;
  short tag;
}Card;


void SwapCard(Card *C, int i, int j){
  Card tmp;
  tmp = C[i];
  C[i] = C[j];
  C[j] = tmp;
}

int IsStable(Card *C,int n){
  int i;

  for(i=1; i<n; i++){
    if(C[i].number == C[i-1].number){
      if(C[i].tag < C[i-1].tag){
	      return FALSE;
      }
    }
  }
  return TRUE;
}
  
void BubbleSort(Card *C, int n){
  int i,j;
  Card copy[N];

  for(i=0; i<n; i++){
    copy[i] = C[i];
  }

  for(i=0; i<n-1; i++){
    for(j=n-1; j>i; j--){
      if(copy[j].number < copy[j-1].number){
      	SwapCard(copy,j,j-1);
      }
    }
  }

  for(i=0; i<n; i++){
    printf("%c%d",copy[i].mark, copy[i].number);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  
  if(IsStable(copy,n))printf("Stable\n");
  else printf("Not Stable\n");
  
}

void SelectionSort(Card *C, int n){
  int i,j,min;
  Card copy[N];

  for(i=0; i<n; i++){
    copy[i] = C[i];
  }

  for(i=0; i<n; i++){
    min = i;
    for(j=i; j<n; j++){
      if(copy[min].number > copy[j].number){
	      min = j;
      }
    }
    SwapCard(copy,i,min);
  }

  for(i=0; i<n; i++){
    printf("%c%d",copy[i].mark, copy[i].number);
    if(i!=n-1) printf(" ");
  }
  printf("\n");

  if(IsStable(copy,n)) printf("Stable\n");
  else printf("Not stable\n");
  
}

int main(){
  int i,n;
  char input[3];
  Card C[N];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%s",input);
    C[i].mark = input[0];
    C[i].number = input[1] - 48;
    C[i].tag = i;
  }

  BubbleSort(C,n);
  SelectionSort(C,n);

  return 0;
}

