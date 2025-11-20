#include <stdio.h>

typedef struct {
  int value;              //数字(1~9)
  char shape;              //形(S,H,C,D)
} card;

void BubbleSort(card C[], int N)
{
  int i = 0, j, flag;
  card tmp;

  for(i = 0; i < N; i++){
    flag = 0;
    for(j = N - 1; j >= i + 1; j--){
      if(C[j].value < C[j-1].value){
        tmp = C[j];
        C[j] = C[j-1];
        C[j-1] = tmp;
        flag = 1;
      }
    }
  }
}

void SelectionSort(card C[], int N)
{
  int i, j, minj;
  card tmp;
  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(C[j].value < C[minj].value){
        minj = j;
      }
    }

    if(minj != i){      //iとminjが異なり実際に交換が行われた回数
      tmp = C[i];
      C[i] = C[minj];
      C[minj] = tmp;
    }
  }
}

int main(void)
{
  int n, i, flag = 0;
  card c1[36], c2[36];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf(" %c%d", &c1[i].shape, &c1[i].value);
  	c2[i] = c1[i];
  }

  BubbleSort(c1 ,n);
  SelectionSort(c2, n);

  for(i = 0; i < n; i++){
      printf("%c%d", c1[i].shape, c1[i].value);
      if(i < n-1){
        printf(" ");
      }
      if(c1[i].shape != c2[i].shape){
        flag++;
      }
  }
  printf("\n");
  printf("Stable\n");

  for(i = 0; i < n; i++){
      printf("%c%d", c2[i].shape, c2[i].value);
      if(i < n-1){
        printf(" ");
      }
  }


  if(flag == 0){
    printf("\n");
    printf("Stable\n");
  }
  else{
    printf("\n");
    printf("Not stable\n");
  }

  return 0;

}

