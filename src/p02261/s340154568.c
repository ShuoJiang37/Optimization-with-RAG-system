#include<stdio.h>
#include<string.h>

struct Card{
  char s[3], v;
};

void bubble(struct Card A[], int N){
  int i,j;
  for(i = 0 ; i < N ; i++){
    for(j = N - 1 ; j >= i ; j--){
      if(A[j].v < A[j - 1].v){
        struct Card t = A[j];
        A[j] = A[j - 1];
        A[j - 1] = t;
      }
    }
  }
}

void selection(struct Card A[], int N){
  int i, j;
  for(i = 0 ; i < N ; i++){
    int minj = i;

    for(j = i ; j < N ; j++){
      if(A[j].v < A[minj].v) minj = j;
    }
    struct Card t = A[i];
    A[i] = A[minj];
    A[minj] = t;
  }
}

void print(struct Card A[], int N){
  int i;
  for(i = 0 ; i < N - 1 ; i++){
    if(i >= 0){
      printf("%s ", A[i].s);
    }
  }
  printf("%s", A[N-1].s);
}

int isStable(struct Card c1[], struct Card c2[],int N){
  int i;
  for(i = 0 ; i < N ; i++){
    if(strcmp(c1[i].s, c2[i].s) != 0) return 0;
  }
  return 1;
}

int main(){
  struct Card c1[100], c2[100];
  int N, i;
  char ch;

  scanf("%d", &N);
  for(i = 0 ; i < N ; i++){
    scanf("%s", c1[i].s);
    c1[i].v = c1[i].s[1];
    c2[i] = c1[i];
  }



    bubble(c1, N);
    selection(c2, N);

    print(c1, N);
    printf("\nStable\n");

    print(c2, N);
    if(isStable(c1, c2, N) == 1){
      printf("\nStable\n");
    }
    else{
      printf("\nNot stable\n");
  }

    return 0;
}
