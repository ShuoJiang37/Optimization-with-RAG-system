//Stable Sort
//2019-01-19
//Ebitani Akira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 36

char char1[N][4], char2[N][4];
char temp[4];
int n;

void BubbleSort();
void SelectionSort();
void Print();

int main(){
  int i;

  scanf("%d", &n);
  if(n < 1 || n > N){
    printf("カードの枚数が適当ではありません。\n");
    exit(1);
  }

  for(i = 0 ; i < n ; i++){
    scanf("%s", char1[i]);
    strcpy(char2[i], char1[i]);
  }

  BubbleSort();
  SelectionSort();
  Print();

  return 0;
}

void BubbleSort() {
  int i, j;

  for(i = 0 ; i < n-1 ; i++){
    for(j = n-1 ; j > i ; j--){
      if(char1[j][1] < char1[j-1][1]){
        strcpy(temp, char1[j]);
        strcpy(char1[j], char1[j-1]);
        strcpy(char1[j-1], temp);
      }
    }
  }
}

void SelectionSort(){
  int i, j, min;

  for(i = 0 ; i < n ; i++){
    min = i;
    for(j = i ; j < n ; j++){
      if(char2[j][1] < char2[min][1])
        min = j;
      }
    if(i != min){
      strcpy(temp, char2[i]);
      strcpy(char2[i], char2[min]);
      strcpy(char2[min], temp);
    }
  }
}

void Print(){
  int i;

  for(i = 0 ; i < n ; i++){
    printf("%s", char1[i]);
    if(i == n-1)
      break;
    printf(" ");
  }
  printf("\nStable\n");

  for(i = 0 ; i < n ; i++){
    printf("%s", char2[i]);
    if(i == n-1)
      break;
    printf(" ");
  }

  int mark = 1;
  for(i = 0 ; i < n ; i++){
    if(strcmp(char1[i], char2[i]) == 0){
      mark = 1;
    }
    else if(strcmp(char1[i], char2[i]) != 0){
      mark = 0;
      break;
    }
  }
  if(mark == 1){
    printf("\nStable\n");
  }
  else if(mark == 0){
      printf("\nNot stable\n");
  }
}

