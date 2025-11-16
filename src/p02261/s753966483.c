#include <stdio.h>

#define MAX 36

typedef struct{
  char pic;
  int num;
}TRUMP;

void input(TRUMP [], int);
void display(TRUMP [], int);
void swap(TRUMP *, TRUMP *);
void copy(TRUMP [], TRUMP [], int);
int isSame(TRUMP [], TRUMP [], int);
void selectionSort(TRUMP[], int);
void bubbleSort(TRUMP[], int);

int main(){
  int N;
  TRUMP A[MAX];
  TRUMP B[MAX];
  
  scanf("%d", &N);
  
  input(A, N);
  copy(A, B, N);

  bubbleSort(A, N);
  selectionSort(B, N);

  display(A, N);

  printf("Stable\n");
  
  display(B, N);

  if(isSame(A, B, N)) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

void input(TRUMP A[], int N) {
  int i;

  for (i = 0; i < N; i++) {
    scanf(" %c%d", &A[i].pic, &A[i].num);
  }
}

void display(TRUMP A[], int N) {
  int i;
  for (i = 0; i < N; i++) {
    if (i) printf(" ");
    printf("%c%d",A[i].pic, A[i].num);
  }
  printf("\n");
}

void swap(TRUMP *x, TRUMP *y) {
  TRUMP temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void copy(TRUMP A[], TRUMP B[], int N) {
  int i;
  for (i = 0; i < N; i++) {
    B[i] = A[i];
  }
}

int isSame(TRUMP A[], TRUMP B[], int N) {
  int i;
  for (i = 0; i < N; i++) {
    if(B[i].num != A[i].num) return 0;
    if(B[i].pic != A[i].pic) return 0;
  }
  return 1;
}

void selectionSort(TRUMP A[], int N) {
  int i, j, tmp, cnt = 0;
  int minj;
  
  for (i = 0; i < N; i++) {
    minj = i;
    for (j = i; j < N; j++) {
      if (A[j].num < A[minj].num) {
	minj = j;
      }
    }
    if (i != minj) {
      swap(&A[i], &A[minj]);
      cnt++;
    }
  }
}

void bubbleSort(TRUMP A[], int N) {
  int i, cnt = 0;
  int flag = 1;
  
  while (flag) {
    flag = 0;
    for (i = N - 1; 0 < i; i--) {
      if (A[i].num < A[i - 1].num) {
	swap(&A[i], &A[i - 1]);
	cnt++;
	flag = 1;
      }
    }
  }
}

