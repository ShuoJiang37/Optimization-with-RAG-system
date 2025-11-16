#include<stdio.h>

struct Card{
  char suit;
  char value;
  int x;
};

void Bubble(struct Card* , int );
void Selection(struct Card*, int );
void Print(struct Card* , int );

int main(){
  struct Card C1[100], C2[100];
  int n, i;
  char ch;

  scanf("%d%c", &n, &ch);
  for ( i = 0; i < n; i ++){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
    C1[i].x = i;
    C2[i] = C1[i];
  }

  Bubble(C1, n);
  Print(C1, n);
  
  Selection(C2, n);
  Print(C2, n);

  return 0;
}

void Bubble(struct Card* A, int n){
  int i, j;
  struct Card tmp;
  for( i = 0; i < n; i++ ){
    for( j = n-1; j > i; j-- ){
      if( A[j-1].value > A[j].value ){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1]= tmp;
      }
    }
  }
  return;
}

void Selection(struct Card* B, int n){
  int i, j, min;
  struct Card tmp;
  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(B[j].value < B[min].value){
	min = j;
      }
    }
    if(min != i){
      tmp = B[i];
      B[i] = B[min];
      B[min] = tmp;
    }
  }
  return;
}

void Print(struct Card* array, int n){
  int i, flg=1;
  for(i = 0; i < n; i++){
    if(i > 0) printf(" ");
    printf("%c%c", array[i].suit, array[i].value);
  }
  printf("\n");
  
  for(i = 0; i < n; i++){
    if((array[i].value == array[i+1].value) && (array[i].x > array[i+1].x)){
      flg = 0;
      break;
    }
  }

  if(flg == 1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
  return;
}