#include <stdio.h>

struct Card {
  char suit;
  int value;
};

void Bubble(struct Card A[], int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j].value < A[j-1].value){
	struct Card swap = A[j];
	A[j] = A[j-1];
	A[j-1] = swap;
      }
    }
  }
}

void Selection(struct Card A[],int n){
  int i,j,min;
  for(i=0;i<n;i++){
    min = i;
    for(j=i;j<n;j++){
      if(A[j].value < A[min].value) min = j;
    }
    struct Card change = A[i];
    A[i] = A[min];
    A[min] = change;
  }
}


void print(struct Card A[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%c%d",A[i].suit,A[i].value);
  }
  printf("\n");
}

int Stable(struct Card C1[],struct Card C2[],int n){
  int i;
  for(i=0;i<n;i++){
    if(C1[i].suit != C2[i].suit) return 0;
  }
  return 1;
}


int main(){
  struct Card C1[100],C2[100];
  int n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&C1[i].suit,&C1[i].value);
  }

  for(i=0;i<n;i++)
    C2[i] = C1[i];

  Bubble(C1,n);
  Selection(C2,n);

  print(C1,n);
  printf("Stable\n");
  print(C2,n);
  if( Stable(C1,C2,n) == 1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  return 0;
}





