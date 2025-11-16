#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int num;
  char cha;
} Card;
  
int main(){

  int N,i,j,minj,flag = 0;
  Card *C[2],dummy;

  scanf("%d",&N);
  C[0] = (Card *)malloc(N * sizeof(Card));
  C[1] = (Card *)malloc(N * sizeof(Card));
  for(j = 0;j < N;j++) {
    scanf(" %c %d",&C[0][j].cha,&C[0][j].num);
  }

  for(i = 0;i < N;i++){
    C[1][i].cha = C[0][i].cha;
    C[1][i].num = C[0][i].num;
  }
  for(i = 0;i < N;i++){ //bubble sort
    for(j = N - 1;j != i;j--){
      if(C[1][j].num < C[1][j - 1].num){
	dummy.cha = C[1][j].cha;
	dummy.num = C[1][j].num;
	C[1][j].cha = C[1][j - 1].cha;
	C[1][j].num = C[1][j - 1].num;
	C[1][j - 1].cha = dummy.cha;
	C[1][j - 1].num = dummy.num;
      }
    }
  }
  
  for(i = 0;i < N;i++){  //selection sort
    minj = i;
    for(j = i;j < N;j++){
      if(C[0][j].num < C[0][minj].num){
	minj = j;
      }
    }
    dummy.cha = C[0][i].cha;
    dummy.num = C[0][i].num;
    C[0][i].cha = C[0][minj].cha;
    C[0][i].num = C[0][minj].num;
    C[0][minj].cha = dummy.cha;
    C[0][minj].num = dummy.num;
  }

  for(j = 0;j < N;j++){
    printf("%c%d",C[1][j].cha,C[1][j].num);
    if(j != N - 1) printf(" ");
  }
  printf("\n");
  printf("Stable\n");
  
  for(j = 0;j < N;j++){
    printf("%c%d",C[0][j].cha,C[0][j].num);
    if(j != N - 1) printf(" ");
  }
  printf("\n");
  for(i = 0;i < N;i++){
    if(C[1][i].num != C[0][i].num || C[0][i].cha != C[1][i].cha) flag = 1;
  }
  if(flag == 1) printf("Not stable\n");
  else printf("Stable\n");
  return 0;
}

