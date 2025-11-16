#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char c;
  int num;
  int id;
}Card;

Card *B,*S;
int n;

void BubbleSort(){
  int i,j;
  //char ckey;
  Card key;

  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      //printf("i:%d j:%d\n",i,j);
      if(B[j-1].num > B[j].num){
        key=B[j];
        //printf("key:%c%d ",key.c,key.num);
        B[j]=B[j-1];
        B[j-1]=key;
        //printf("B[%d]:%c%d\n",j-1,B[j-1].c,B[j-1].num);
        //turn++;
      }
    }
  }
}

void SelectionSort(){
  int i,j,minj;
  Card key;

  for(i=0; i<n-1; i++){
    minj=i;
    for(j=i; j<=n-1; j++){
      if(S[j].num < S[minj].num){
        minj = j;
      }
    }
    key=S[i];
    S[i]=S[minj];
    S[minj]=key;
    //if(i!=minj)dif++;
  }
}

void judge(Card *T){
  int i,j;
  for(i=1; i<n; i++){
    if((T[i-1].num==T[i].num)&&(T[i-1].id > T[i].id)){
      printf("Not stable\n");
      return;
    }
  }
  printf("Stable\n");
}

void printer(){
  int i;
  for(i=0; i<n; i++){
    printf("%c%d",B[i].c,B[i].num);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  judge(B);
  for(i=0; i<n; i++){
    printf("%c%d",S[i].c,S[i].num);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  judge(S);
}

int main() {
  int i,num;
  char c;

  scanf("%d",&n);
  B = malloc(sizeof(Card) * n);
  S = malloc(sizeof(Card) * n);
  for(i=0; i<n; i++){
    scanf(" %c%d",&c,&num);
    B[i].c = c;
    B[i].num = num;
    B[i].id = i;
    S[i].c = c;
    S[i].num = num;
    S[i].id = i;
    //printf("%c%d",B[i].c,B[i].num);
  }
  //printf("\n");
  BubbleSort();
  SelectionSort();
  printer();

  return 0;
}

