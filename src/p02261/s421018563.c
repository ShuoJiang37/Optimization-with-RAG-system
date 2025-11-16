#include<stdio.h>
#include<stdlib.h>

#define MAX 36
#define TRUE 1
#define FALSE 0

typedef struct{
  char mark;
  int num;
}trump;

void BubbleSort(trump *,int);
void SelectionSort(trump *,int);
int isStable(trump *,trump *,int);

int main(){
  trump card1[MAX],card2[MAX];
  int i,N;
  char data[MAX][MAX];

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%s",data[i]);
    card1[i].mark = data[i][0];
    card2[i].mark = data[i][0];
    card1[i].num = atoi(&data[i][1]);
    card2[i].num = atoi(&data[i][1]);
  }

  BubbleSort(card1,N);
  printf("Stable\n");
  SelectionSort(card2,N);
  if(isStable(card1, card2, N) == TRUE) printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}

void BubbleSort(trump *card,int N){
  int i,flag,swap;
  char temp[MAX];


  flag = 1;
  while(flag){
    flag = 0;
    for(i=N-1; i>=1; i--){
      if(card[i].num < card[i-1].num){
	*temp = card[i].mark;
	card[i].mark = card[i-1].mark;
	card[i-1].mark = *temp;
	swap = card[i].num;
	card[i].num = card[i-1].num;
	card[i-1].num = swap;
	flag = 1;
      }
    }
  }

  for(i=0; i<N; i++){
    printf("%c%d",card[i].mark,card[i].num);
    if(i==N-1) break;
    printf(" ");
  }
  printf("\n");

}

void SelectionSort(trump *card, int N){
  int i,j,minj,swap;
  char temp[MAX];

  for(i=0; i<N; i++){
    minj = i;
    for(j=i; j<N; j++){
      if(card[j].num < card[minj].num) minj = j;
    }
    if(i!=minj){
      *temp = card[i].mark;
      card[i].mark = card[minj].mark;
      card[minj].mark = *temp;
      swap = card[i].num;
      card[i].num = card[minj].num;
      card[minj].num = swap;
    }
  }
  for(i=0; i<N; i++){
    printf("%c%d",card[i].mark,card[i].num);
    if(i==N-1) break;
    printf(" ");
  }
  printf("\n");

}

int isStable(trump *card_bef, trump *card_aft, int N){
  int i,j; 
  for(i=0; i<N; i++){
    if(card_bef[i].mark != card_aft[i].mark || card_bef[i].num != card_aft[i].num) return FALSE;
    }
  return TRUE;
}

