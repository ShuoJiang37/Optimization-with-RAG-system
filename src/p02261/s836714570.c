#include<stdio.h>
struct Card {
  char suit[3];
  char value;
  int i;
};

void BubbleSort(struct Card[], int);
void SelectionSort(struct Card[], int);
void Stable(struct Card[], int);

int main(){
  int N, i;
  struct Card C1[36];
  struct Card C2[36];

  scanf("%d",&N);
  for( i = 0 ; i < N ; i++ ){
    scanf("%s",&C1[i].suit);
    C1[i].value = C1[i].suit[1];
    C1[i].i = i;
    C2[i] = C1[i];
  }

  BubbleSort(C1, N);
  SelectionSort(C2, N);

  printf("%s",C1[0].suit);
  for( i = 1 ; i < N ; i ++ ){
    printf(" %s",C1[i].suit);
  }
  printf("\n");

  Stable(C1, N);

  printf("%s",C2[0].suit);
  for( i = 1 ; i < N ; i ++ ){
    printf(" %s",C2[i].suit);
  }
  printf("\n");

  Stable(C2, N);

  return 0;
}

void BubbleSort(struct Card C[], int N){
  int i, j;
  struct Card tmp;
  for( i = 0 ; i < N ; i++ ){
    for( j = N-1 ; j >= i+1 ; j-- ){
      if( C[j].value < C[j-1].value ){
        tmp = C[j];
        C[j] = C[j-1];
        C[j-1] = tmp;
      }
    }
  }
}

void SelectionSort(struct Card C[], int N){
  int i, j, minj;
  struct Card tmp;
  for( i = 0 ; i < N ; i++ ){
    minj = i;
    for( j = i ; j < N ; j++ ){
      if( C[j].value < C[minj].value ) minj = j;
    }
    tmp = C[i];
    C[i] = C[minj];
    C[minj] = tmp;
  }
}

void Stable(struct Card C[], int N){
  int i, flag=0;
  for( i = 0 ; i < N-1 ; i++ ){
    if( C[i].value == C[i+1].value ){
      if( C[i].i > C[i+1].i ){
        printf("Not stable\n");
        flag = 1;
        break;
      }
    }
  }
  if( flag == 0  )printf("Stable\n");
}

