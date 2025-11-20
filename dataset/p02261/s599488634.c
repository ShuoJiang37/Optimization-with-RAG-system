#include<stdio.h>

typedef struct{
  char num;
  char pattern;
}Card;

int isStable(Card[],Card[],int);
void selection(Card[],int);
void bubble(Card[],int);


int main(){
  Card car1[100];
  Card car2[100];
  int i,n;

  scanf("%d\n",&n);
  for(i=0;i<n;i++){
    scanf("%c%c ",&car1[i].pattern,&car1[i].num);
    car2[i]=car1[i];
  }

  bubble(car1,n);
  selection(car2,n);

  for(i=0;i<n;i++){
    if(i){
      printf(" ");
    }
    printf("%c%c",car1[i].pattern,car1[i].num);
  }
  printf("\n");
  
  printf("Stable\n");
  
  for(i=0;i<n;i++){
    if(i){
      printf(" ");
    }
    printf("%c%c",car2[i].pattern,car2[i].num);
  }
  printf("\n");

  if(isStable(car1,car2,n)){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }

  return 0;
}

void bubble(Card A[], int n){
  int i, j;
  Card t;
  for (i=0;i<n;i++){
    for (j=n-1;j>=i+1;j--){
      if (A[j].num < A[j-1].num){
	t = A[j];
	A[j] = A[j-1];
	A[j-1] = t;
      }
    }
  }
}

void selection(Card A[], int n){
  int i, j, mini;
  Card t;
  for(i=0;i<n;i++){
    mini = i;
    for(j=i;j<n;j++){
      if(A[j].num<A[mini].num){
	mini = j;
      }
    }
    t = A[i];
    A[i] = A[mini];
    A[mini] = t;
  }
}

int isStable(Card A1[],Card A2[],int n){
  int i;
  for(i=0;i<n;i++){
    if(A1[i].pattern != A2[i].pattern){
      return 0;
    }
  }
  return 1;
}

