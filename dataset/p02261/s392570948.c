#include <stdio.h>

typedef struct{
  char mark;
  int num;
}Card;


int main(){
  Card card1[36], card2[36], temp;
  int i, j, a, b, status = 1, flag, minj, cnt = 0;
  int n;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf(" %c%d", &card1[i].mark, &card1[i].num);
    card2[i] = card1[i];
  }


  flag = 1;

  while(flag){
    flag = 0;

    for(i = n - 1; i > 0; i--){
      if(card1[i].num < card1[i-1].num){
	temp = card1[i];
	card1[i] = card1[i-1];
	card1[i-1] = temp;
	
	cnt++;
	flag = 1;
      }
    }
  }


  for(i = 0; i < n; i++){
    minj = i;

    for(j = i; j < n; j++){
      if(card2[j].num < card2[minj].num){
	minj = j;
      }
    }

    temp = card2[i];
    card2[i] = card2[minj];
    card2[minj] = temp;
    if(i != minj) cnt++;
  }


  for(i = 0; i < n - 1; i++){
    printf("%c%d ", card1[i].mark, card1[i].num);
  }

  printf("%c%d\n", card1[n-1].mark, card1[n-1].num);
  printf("Stable\n");

  for(i = 0; i < n - 1; i++){
    printf("%c%d ", card2[i].mark, card2[i].num);
  }

  printf("%c%d\n", card2[n-1].mark, card2[n-1].num);

  
  for(i = 0; i < n; i++){
    for(j = i+1; j < n; j++){
      for(a = 0; a < n; a++){
	for(b = a+1; b < n; b++){
	  if(card1[i].num == card1[j].num && card2[i].mark == card1[b].mark && card2[i].num == card1[b].num &&
	     card1[j].mark == card2[a].mark && card1[j].num == card2[a].num){
	    status=0;
	  }
	}
      }
    }
  }

  
  if(status == 0) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}

