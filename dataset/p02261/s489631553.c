#include <stdio.h>

typedef struct{
  char mark;
  int value;
}Card;

void BubbleSort(Card *, int );
void SelectionSort(Card *, int);
int isStable(Card *,Card *,int);

int main(){
  int n=0;
  int i=0;
  char space;
  scanf("%d%c",&n,&space);
  Card card[n];
  Card card_b[n];
  Card card_s[n];
  for(i=0;i<n;i++){
    scanf("%c%d%c",&card[i].mark,&card[i].value,&space);
    card_b[i].mark=card[i].mark;
    card_b[i].value=card[i].value;
    card_s[i].mark=card[i].mark;
    card_s[i].value=card[i].value;
  }
  
  BubbleSort(card_b,n);
  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%c%d",card_b[i].mark,card_b[i].value);
  }
  printf("\n");
  
  printf("Stable\n");
  
  SelectionSort(card_s,n);
  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%c%d",card_s[i].mark,card_s[i].value);
  }
  printf("\n");

  if(isStable(card_b,card_s,n)==-1) printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}

void BubbleSort(Card *C, int n){
  int i=0;
  int j=0;
  Card change;
  for(i=0;i<n-1;i++)
    {
      for(j=n-1;i<j;j--)
	{
	  if(C[j].value < C[j-1].value){
	    change=C[j];
	    C[j]=C[j-1];
	    C[j-1]=change;
	  } 
	}
    }
}

void SelectionSort(Card *C, int n){
  int i=0;
  int j=0;
  int min=0;
  Card change;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i;j<n;j++){
      if(C[j].value<C[min].value)
	min=j;
    }
    change=C[i];
    C[i]=C[min];
    C[min]=change;
  }
}

int isStable(Card *B,Card *S,int n){
  int i=0;
  for(i=0;i<n;i++){
    if(B[i].mark!=S[i].mark) return -1;
  }
  return 1;
}

