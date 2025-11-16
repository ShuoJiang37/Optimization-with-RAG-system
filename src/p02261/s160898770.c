#include<stdio.h>

typedef struct Card{
  char nam;
  int number;
}card;

int isStable(card [],card [],int);
void bubbleSort(card [],int);
void selection(card [],int);
void phyouzi(card [],int);

int main(){
  card c[100], c1[100];
  int i,n;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf(" %c%d", &c[i].nam, &c[i].number);
    c1[i] = c[i];
  }

  bubbleSort(c,n);
  selection(c1,n);

  for(i=0; i<n; i++){

    if(i==n-1){
      printf("%c%d", c[i].nam, c[i].number);
    }
    else{
      printf("%c%d ", c[i].nam, c[i].number);
    }

  }
  printf("\n");

  printf("Stable\n");
  for(i=0; i<n; i++){
    if(i==n-1){
      printf("%c%d", c1[i].nam, c1[i].number);
    }
    else{
      printf("%c%d ", c1[i].nam, c1[i].number);
    }
  }
  printf("\n");

  if(isStable(c,c1,n)){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  return 0;
}

void bubbleSort(card x[],int n){
   int i, j;
  card tmp;

  for(i=0; i<n; i++){
    for(j=n-1; j>=i+1; j--){
      if(x[j].number < x[j-1].number){
    tmp = x[j];
    x[j] = x[j-1];
    x[j-1] = tmp;
      }
    }
  }
}

void selection(card x[],int n){
  int i,j, min;
  card tmp;

  for(i=0; i<n; i++){
    min=i;
    for(j=i; j<n; j++){
      if(x[j].number < x[min].number) min=j;
    }
    tmp=x[i];
    x[i] = x[min];
    x[min] = tmp;
  }
}
void phyouzi(card x[],int n){
  int i;

  for(i=0; i<n; i++){
    if(i>0){
      printf(" ");
    }
    printf("%c%d", x[i].nam, x[i].number);
  }
  printf("\n");
}

int isStable(card c[],card c1[],int n){
  int i;
  for(i=0; i<n; i++){
    if(c[i].nam != c1[i].nam)
      return 0;
  }
  return 1;
}

