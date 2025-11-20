#include<stdio.h>

typedef struct{
  char suit;
  int number;
}Card;


void print(int N,Card A[]){
  for(int i = 0; i < N; i++){
    if(i < (N - 1) ){
      printf("%c%d ",A[i].suit,A[i].number);
    }else{
      printf("%c%d",A[i].suit,A[i].number);
    }
  }
  putchar('\n');
}


void bubble(int N,Card A[]){
  int flag = 1;
  while(flag==1){
    flag = 0;
    for(int j = N - 1; j > 0; j--){
      if(A[j].number < A[j - 1].number){
        Card temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
        flag = 1;
      }
    }
  }
}

void selection(int N,Card A[]){
  for(int i = 0; i < N; i++){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A[j].number < A[minj].number){
        minj = j;
      }
    }
    Card temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
  }
}

int isStable(Card C1[],Card C2[],int N){
  for(int i = 0; i < N; i++){
    if(C1[i].suit != C2[i].suit)return 0;
  }
  return 1;
}

int main(){
  Card C1[100],C2[100];
  int n;
  scanf("%d",&n);

  for(int i = 0; i < n; i++){
    scanf(" %c%d",&C1[i].suit ,&C1[i].number);//前に空白を入れないと読み込みがおかしくなる
  }
  
  for(int i = 0; i < n; i++){
    C2[i] = C1[i];
  }
  

  bubble(n,C1);
  selection(n,C2);

  print(n,C1);
  printf("Stable\n");

  print(n,C2);
  if(isStable(C1,C2,n)){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

}

