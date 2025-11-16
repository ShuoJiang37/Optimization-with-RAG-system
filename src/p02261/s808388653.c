#include<stdio.h>
#include<stdlib.h>

#define CARD_NUM 36

typedef struct {

  int value;
  char mark;

} card ;

void print_card(int N,card *card){

  int i;

  for(i = 0;i < N-1;i++){
    printf("%c",card[i].mark);
    printf("%d ",card[i].value);

  }
  printf("%c",card[N-1].mark);
  printf("%d\n",card[N-1].value);

}

void copy(int N,card _Source[],card *_Dest){

  int i;

  for(i = 0;i < N;i++){
    _Dest[i] = _Source[i];
  }
}

void isStable(int N,card *in,card *out){

  int i;
  int j;
  int a;
  int b;

  for(i = 0;i < N;i++){
    for(j = i+1;j < N;j++){
      for(a = 0;a < N;a++){
	for(b = a+1;b < N;b++){
	  if(in[i].value == in[j].value && 
	     in[i].value == out[b].value && 
	     in[i].mark == out[b].mark &&
	     in[j].value == out[a].value &&
	     in[j].mark == out[a].mark){
	    printf("Not stable\n");
	    return;
	  }
	}
      }
    }
  }
  printf("Stable\n");
}

void Bubble(int N,card C[]){

  int i;
  int j;
  int cnt = 0;
  card temp;
  card CC[N];

  copy(N,C,CC);

  for(i = 0;i < N;i++){
    for(j = N-1;j > i;j--){
      if(CC[j].value < CC[j-1].value){
	temp = CC[j];
	CC[j] = CC[j-1];
	CC[j-1] = temp;
      }
    }
  }

  print_card(N,CC);
  isStable(N,C,CC);
}

void Selection(int N,card *C){

  int i;
  int j;
  int min;
  int flag = 0;
  card temp;
  card CC[N];

  copy(N,C,CC);

  for(i = 0;i < N;i++){
    min = i;
    for(j = i;j < N;j++){
      if(CC[j].value < CC[min].value){
	min = j;
      }
    }
    temp = CC[i];
    CC[i] = CC[min];
    CC[min] = temp;
  }
  print_card(N,CC);
  isStable(N,C,CC);
}

int main(){

  int i;
  int num;
  char temp[4];
  card card1[CARD_NUM];

  scanf("%d",&num);

  for(i = 0;i < num;i++){
    scanf("%s",temp);
    card1[i].mark = *temp;
    card1[i].value = atoi(&temp[1]);
  }

  Bubble(num,card1);
  Selection(num,card1);

  return 0;
}