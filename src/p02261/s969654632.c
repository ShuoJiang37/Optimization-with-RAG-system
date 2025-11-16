#include <stdio.h>

struct Card{
  char suit;
  char value;
};


void bubble(struct Card A[], int num){
  int i,j;
  struct Card tmp;
  for(i=0;i<num-1;i++){
    for(j=num-1;j>=i+1;j--){
      if(A[j].value < A[j-1].value){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
      }
    }
  }
}

void Selection(struct Card A[], int num){
  int i,j,min;
  struct Card tmp;
  for(i=0;i<num-1;i++){
    min=i;
    for(j=i;j<num;j++){
      if(A[j].value < A[min].value) {
	min=j;
    }
    }
    if(A[i].value != A[min].value){
    tmp=A[i];
    A[i]=A[min];
    A[min]=tmp;
    }
  }
}

void print(struct Card A[], int num){
  int i;
  for(i=0;i<num;i++){
    if(i) printf(" ");
    printf("%c%c", A[i].suit, A[i].value);
  }
  printf("\n");
}

int isStable(struct Card C1[], struct Card C2[], int num){
  int i;
  for(i=0;i<num;i++){
    if(C1[i].suit != C2[i].suit) return 0;
  }
  return 1;
}

int main ()
{
  struct Card C1[101],C2[101];
  int num,i;
 

  scanf("%d\n",&num);
  for(i=0;i<num;i++){
    scanf(" %c%c",&C1[i].suit, &C1[i].value);
  }
  for(i=0;i<num;i++) C2[i]=C1[i];
  
  bubble(C1,num);
  Selection(C2,num);
  
  print(C1,num);
  printf("Stable\n");
  print(C2,num);
  if(isStable(C1,C2,num)){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }

  return 0;
}