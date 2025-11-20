#include <stdio.h>
#include <string.h>

struct card{
  int num;
  char mark;
};

struct card card_i[40], card_j[40];

void BubbleSort(int n);
void SelectionSort(int n);
void write(int n);
void stable(int n);

int main(void){
  int n, i, j;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    while(1){
      scanf("%c", &card_i[i].mark);
      if((card_i[i].mark == ' ') || (card_i[i].mark == '\n')) continue;
      scanf("%d", &card_i[i].num);
      card_j[i] = card_i[i];
      break;
    }
  }
  BubbleSort(n);
  stable(n);
  SelectionSort(n);
  stable(n);

  return 0;
}

void BubbleSort(int n){
  int i, j;
  struct card k;
  for(i = 0; i < n-1; i++){
    for(j = n-1; j > i; j--){
      if(card_j[j].num < card_j[j-1].num){
	k = card_j[j];
	card_j[j] = card_j[j-1];
	card_j[j-1] = k;
      }
    }
  }
  write(n);
  return;
}

void SelectionSort(int n){
  int i, j, minj;
  struct card k;

  for(i = 0; i < n-1; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(card_j[j].num < card_j[minj].num) minj = j;
    }
    k = card_j[minj];
    card_j[minj] = card_j[i];
    card_j[i] = k;
  }
  write(n);
  return;
}

void write(int n){
  int i, j;
  for(i = 0; i < n; i++){
    printf("%c%d", card_j[i].mark, card_j[i].num);
    if(i+1 != n) printf(" ");
  }
  printf("\n");
  return;
}

void stable(int n){
  int i, j, k[4], kk[4], co1 = 0, co2 = 0, co = 0, l;
  for(i = 1; i < 10; i++){
      for(j = 0; j < n; j++){
	if(card_j[j].num == i){
	  k[co1] = card_j[j].mark;
	  co1++;
	  co++;
	}
      }
      for(j = 0; j < n; j++){
	if(card_i[j].num == i){
	  kk[co2] = card_i[j].mark;
	  co2++;
	}
      }
      for(j = 0; j < co; j++){
	if(co == 0) break;
	if(k[j] != kk[j]){
	  for(l = 0; l < n; l++){
	    card_j[l] = card_i[l];
	  }
	  printf("Not stable\n");
	  return;
	}
      }
      co1 = 0;
      co2 = 0;
      co = 0;
  }
  for(l = 0; l < n; l++){
    card_j[l] = card_i[l];
  }
  printf("Stable\n");
  return;
}