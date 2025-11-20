#include<stdio.h>
#define true 1
#define false 0
typedef struct{ 
  char suit;
  char value;
} card;



void bubblesort(card A[], int N){
  int i, j;
  card temp;
  
  for( i = 0; i < N; i++){
    for(j = N -1; j >= i+1; j--){
      if(A[j].value < A[j-1].value){
      	temp = A[j];
      	A[j] = A[j-1];
      	A[j-1]=temp;
      }
    }
  }

}

void selectionsort(card A[], int N){
  int i,j,minj;
  card temp;
  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j].value < A[minj].value) minj = j;
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
 }
}

void Print(card A[], int N){
  int i;
    for(i = 0; i < N-1 ; i++){
      printf("%c%c ",A[i].suit,A[i].value);
    }
    printf("%c%c\n",A[N-1].suit,A[N-1].value);
  
 }

int isStable(card c1[], card c2[], int N){
  int i = 0;
  for (i = 0; i < N; i++){
    if(c1[i].suit != c2[i].suit){
      return false;
    }
  }
  return true;
}

int main(){
  card c1[100],c2[100];
  int N;
  char ch;
  int i;

  scanf("%d",&N);
  for(i=0; i < N; i++){
    scanf(" %c",&c1[i].suit);
    scanf("%c",&c1[i].value);
  }

  for(i=0; i < N; i++){
    c2[i] = c1[i];
  }
  /*
  for(i=0;i<N;i++){
    printf("c1:%c%c\n",c1[i].suit,c1[i].value);
    printf("c2:%c%c\n",c2[i].suit,c2[i].value);
  }
*/

  bubblesort(c1,N);
  selectionsort(c2,N);

  Print(c1,N);
  printf("Stable\n");

  Print(c2,N);
  if(isStable(c1,c2,N) == 1){
    printf("Stable\n");
  }
  else {
    printf("Not stable\n");
  }
  
  return 0;
}


