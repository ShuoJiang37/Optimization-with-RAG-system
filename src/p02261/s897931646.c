#include <stdio.h>
#define false -1
#define true 1
typedef struct{
  char design;
  int number;
}card;
int bubbleSort(card[],int);
int SelectionSort(card[],int);
int isStable(card[],card[],int);
int main(){
  int i,N = 0;
  scanf("%d",&N);
  card Card[N];
  for(i = 0; i < N; i++){
    scanf(" %c%d",&Card[i].design,&Card[i].number);
  }
  bubbleSort(Card,N);
  SelectionSort(Card,N);
  return 0;
}

int bubbleSort(card Card[],int N){
  int i,j;
  int count=0;
  card Ans[N],tmp;
  card Card2[N]; /*card change*/
  for(i = 0; i <= N-1; i++){
    Card2[i] = Card[i];
  }
  for(i =0; i <= N-1; i++){
    for(j = N-1; j>= i+1; j--){
    //printf("%d %d\n",i,j);
      if(Card2[j].number < Card2[j-1].number){
        tmp = Card2[j];
        Card2[j] = Card2[j-1];
        Card2[j-1] = tmp;
        count++;
      }
    }
  }
  for(i = 0; i <= N-1; i++){//
    if(0 < i){
      printf(" ");
    }
    printf("%c%d",Card2[i].design,Card2[i].number);/*??????*/
  }
  printf("\n");
  isStable(Card,Card2,N);
}

int SelectionSort(card Card[], int N){
  int i,j,minj;
  card tmp,Ans[N];
  for(i = 0; i <= N-1; i++){
    Ans[i] = Card[i];
    //printf("%c %d\n",Card[i].design,Card[i].number);
  }
  for(i = 0; i <= N-1; i++){
    minj = i;
    for(j = i; j <= N-1; j++){
      if(Card[j].number < Card[minj].number){
        minj = j;
      }
    }
    if(Card[i].number != Card[minj].number){
      tmp = Card[i];
      Card[i] = Card[minj];
      Card[minj] = tmp;
    }
  }
  for(i = 0; i <= N-1; i++){
    if(0 < i){
      printf(" ");
    }
    printf("%c%d",Card[i].design,Card[i].number);/*??????*/
  }
  printf("\n");
  isStable(Ans,Card,N);
}

int isStable(card in[],card out[],int N){
  int a,b,i,j;
  
  for(i = 0; i <= N-1; i++){
    for(j = i+1; j < N-1; j++){
      for(a = 0;a < N-1; a++){
        for(b = a+1; b < N-1; b++){
          if(in[i].number == in[j].number &&
             in[i].number == out[b].number &&
             in[j].number == out[a].number &&
             in[i].design == out[b].design &&
             in[j].design == out[a].design){
            printf("Not stable\n");
            return false;
          }
        }
      }
    }
  }
  printf("Stable\n");
  return true;
}