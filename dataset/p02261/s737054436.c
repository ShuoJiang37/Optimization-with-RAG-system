#include <stdio.h>
#define MAX 36

typedef struct{
  char suit;
  int value;
}card;

void BubbleSort(card *,int);
void SelectionSort(card *,int);

int main(){
  int i,j,n,judge=0;
  card C[MAX],C1[MAX],C2[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%c",&C[i].suit);
    scanf("%c",&C[i].suit);
    scanf("%d",&C[i].value);

    C1[i] = C[i];
    C2[i] = C[i];
  }

  
  BubbleSort(C1,n);
  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%c",C1[i].suit);
    printf("%d",C1[i].value);
  }
  printf("\nStable\n");

  SelectionSort(C2,n);
  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%c",C2[i].suit);
    printf("%d",C2[i].value);
    if(C1[i].suit != C2[i].suit)judge = 1;
  }
  if(judge)printf("\nNot stable\n");
  else printf("\nStable\n");
  
  
  
  
  return 0;
}

void BubbleSort(card *C,int n){
  int i,j;
  card tmp;
  for(i=0;i<n;i++){
    for(j = n-1;j>i;j--){
      if(C[j].value < C[j-1].value){
	tmp = C[j];
	C[j] = C[j-1];
	C[j-1] = tmp;
      }
    }
  }
}

void SelectionSort(card *C,int n){
  int i,j,minj;
  card tmp;
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(C[j].value < C[minj].value){
	minj = j;
      }
    }
    tmp = C[i];
    C[i] = C[minj];
    C[minj] = tmp;
  }
}

