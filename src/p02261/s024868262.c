#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
  char mozi;
  int value;
}card;

void printkansu(card *);
void BubbleSort(card *);
void SelectionSort(card *);
int inStable(card *,card *);
int length; 
card key; 
card S[36];
int i=0,j=0;


int main(){
  
  scanf("%d",&length);//長さ入力
  card C[36];
  card M[36];
  while(i < length){//柄と数の入力
    scanf(" %c%d",&C[i].mozi,&C[i].value);
    M[i] = C[i];
    S[i] = C[i];
    i++;
  }
  
  BubbleSort(C) ;
  SelectionSort(M);
  return 0;
}


void BubbleSort(card *C)
{
  for(i = 0;i < length-1;i++){//BubbleSort(C, N)
    for(j = length-1;j >= 1;j--){
      
      if(C[j].value < C[j-1].value){
	key = C[j];
	C[j] = C[j-1];
	C[j-1] = key;
      }
    }
  }
  printkansu(C);
}
void SelectionSort(card *C)
{
  int min;

  for(i = 0;i < length-1;i++){//SelectionSort(C, N)
    min = i;
    for(j = i;j <= length-1;j++){
      if(C[j].value < C[min].value){
	min = j;
      }
    }
    key = C[i];
    C[i] = C[min];
    C[min] = key;
  }
  printkansu(C);
}

void printkansu(card *C)
{
  for(i = 0;i < length-1;i++){//表示
    printf("%c%d ",C[i].mozi,C[i].value);
  }
  printf("%c%d\n",C[i].mozi,C[i].value);
  if(inStable(S,C)==1)printf("Stable\n");
  else printf("Not stable\n");
}
int inStable(card *in ,card *out)
{
  int a, b;
  for(i = 0;i < length-1;i++){
    for(j = i+1;j < length-1;j++){
      for(a = 0;a < length-1;a++){
	for(b = a+1;b < length-1;b++){

	  if(in[i].value == in[j].value && in[i].value == out[b].value && in[i].mozi == out[b].mozi && in[j].value == out[a].value && in[j].mozi == out[a].mozi) return 0;
	}
      }
    }
  }
  return 1;
}