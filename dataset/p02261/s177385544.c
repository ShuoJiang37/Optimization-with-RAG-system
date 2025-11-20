#include <stdio.h>
#include <string.h>
#define M 36

typedef struct {
  char mark;
  int value;
}Card;

void BubbleSort(Card *, int);
void SelectionSort(Card *, int);
void disply(Card *, int);
int isStable(Card *, Card *, int);

int main(){
  Card C1[M+1], C2[M+1];
  int i, N;

  scanf("%d",&N);

//文字列と数字をそれぞれ格納
  for(i = 0; i < N; i++){
    scanf(" %c%d", &C1[i].mark, &C1[i].value);
  }

  for(i = 0 ;i < N; i++) C2[i] = C1[i];

  BubbleSort(C1, N);
  disply(C1, N);
  printf("Stable\n");

  SelectionSort(C2, N);
  disply(C2, N);

  if( isStable(C1, C2, N) == 0 ) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

/*1 BubbleSort(C, N)
2   for i = 0 to N-1
3     for j = N-1 downto i+1
4       if C[j].value < C[j-1].value
5         C[j] と C[j-1] を交換*/
void BubbleSort(Card C1[], int N){
  int i, j;
  Card tmp;
  for(i = 0;i < N; i++){
    for(j = N-1; j > i; j--){
      if(C1[j].value < C1[j-1].value){
        tmp = C1[j];
        C1[j] = C1[j-1];
        C1[j-1] = tmp;
      }
    }
  }
}

/*7 SelectionSort(C, N)
8   for i = 0 to N-1
9     minj = i
10    for j = i to N-1
11      if C[j].value < C[minj].value
12        minj = j
13    C[i] と C[minj] を交換*/
void SelectionSort(Card C2[], int N){
  int i, j, minj;
  Card tmp;
  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(C2[j].value < C2[minj].value) minj = j;
    }
    tmp = C2[i];
    C2[i] = C2[minj];
    C2[minj] = tmp;
  }
}

void disply(Card C[], int N)
{
  int i;

  for( i = 0 ; i < N ; i++ ){
    if( i > 0 ) printf(" ");
    printf("%c%d", C[i].mark, C[i].value);
  }
  printf("\n");
}

/*1 isStable(in, out)
2   for i = 0 to N-1
3     for j = i+1 to N-1
4       for a = 0 to N-1
5         for b = a+1 to N-1
6           if in[i] と in[j] の数字が等しい && in[i] == out[b] && in[j] == out[a]
7             return false
8 return true*/
int isStable(Card C1[], Card C2[], int N){
  int i;

  for(i = 0; i < N; i++)
  if(C1[i].mark != C2[i].mark ) return 1;
  return 0;
}

