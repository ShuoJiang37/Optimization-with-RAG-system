#include<stdio.h>
struct card_data{
  int value;
  char suit;

};

int main(void){
  int n;
  scanf("%d", &n);
  struct card_data card1[n];
  struct card_data card2[n];
  for(int i=0; i<n; i++){
    scanf(" %c%d", &card1[i].suit, &card1[i].value);
    card2[i].value=card1[i].value;
    card2[i].suit=card1[i].suit;

  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){


    }
  }

  //バブル
  int flag = 1;
  int temp;
  char temp_c;
  int i =0;
  while(flag==1){
    flag=0;
    for(int j=n-1; j>=i+1; j--){
      if(card1[j].value<card1[j-1].value){
        temp=card1[j].value;
        temp_c=card1[j].suit;
        card1[j].value=card1[j-1].value;
        card1[j].suit=card1[j-1].suit;
        card1[j-1].value=temp;
        card1[j-1].suit=temp_c;
        flag=1;
      }
    }
    i++;
  }

  for(int i=0; i<n-1; i++){
    printf("%c%d ", card1[i].suit,card1[i].value);
  }
  printf("%c%d\n", card1[n-1].suit,card1[n-1].value);
  printf("Stable\n");



  //選択

  for(int i=0; i<n; i++){
    int minj = i;
    for(int j=i; j<n; j++){
      if(card2[j].value<card2[minj].value){
          minj = j;
      }


    }
    if(i!=minj){
      temp =card2[i].value;
      temp_c =card2[i].suit;
      card2[i].value=card2[minj].value;
      card2[i].suit=card2[minj].suit;
      card2[minj].value=temp;
      card2[minj].suit=temp_c;


    }

  }

  for(int i=0; i<n-1; i++){
    printf("%c%d ", card2[i].suit,card2[i].value);
  }
  printf("%c%d\n", card2[n-1].suit,card2[n-1].value);
  int count = 0;
  for(int i=0; i<n; i++){
    if(card1[i].suit!=card2[i].suit){
      printf("Not stable\n");
      break;
    }
    count++;
    if(count==n){
      printf("Stable\n");
    }
  }

  return 0;



}

