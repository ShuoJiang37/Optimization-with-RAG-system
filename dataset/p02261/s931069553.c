#include <stdio.h>

typedef struct {
  char mark;
  int number;
}card;

void BubbleSort(card C[], int N);
void SelectionSort(card C[], int N);

int main(){
  int N,i;
  card C[36];
  card D[36];

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf(" %c",&C[i].mark);
    scanf("%d",&C[i].number);
    D[i] = C[i];
  }

  BubbleSort(C,N);
  SelectionSort(D,N);

    for(i=0;i<N-1;i++){
      printf("%c%d ",C[i].mark,C[i].number);
    }
    printf("%c%d\n",C[N-1].mark,C[N-1].number);
    printf("Stable\n");

    for(i=0;i<N-1;i++){
      printf("%c%d ",D[i].mark,D[i].number);
    }
    printf("%c%d\n",D[N-1].mark,D[N-1].number);

    for(i=0;i<N;i++){
      if(i == N-1){
        printf("Stable\n");
      }
      if((C[i].number != D[i].number) || (C[i].mark != D[i].mark)){
          printf("Not stable\n");
          break;
        }
    }
    return 0;
}


void BubbleSort(card C[], int N){
  int i,j;
  card tmp;

  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(C[j].number < C[j-1].number){
        tmp = C[j];
        C[j] = C[j-1];
        C[j-1] = tmp;
      }
    }
  }
}

void SelectionSort(card C[],int N){
  card tmp;
  int minj,i,j;

  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(C[j].number < C[minj].number){
        minj = j;
      }
    }
    tmp = C[i];
    C[i] = C[minj];
    C[minj] = tmp;
  }

  return;
}


