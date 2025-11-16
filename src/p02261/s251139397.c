#include<stdio.h>
#include<stdlib.h>
void BubbleSort(char**, int);
void SelectionSort(char**, int);
char C[36],D[36];
int main(){
  int i, N, flag;
  char **A, *B;
  scanf("%d",&N);
  A = (char **)malloc(sizeof(char*) * N);
  for(i=0; i<N; i++)
    A[i] = (char *)malloc(sizeof(char) * 2);
  for(i=0; i<N; i++)
    scanf("%s",A[i]);
  
  BubbleSort(A, N);
  SelectionSort(A, N);
  for(i=0,flag=1; i<N; i++)
    if(D[i] != C[i]){
      flag = 0;
      break;
    }
  flag ? printf("Stable\n"):printf("Not stable\n");
  free(A);
  return 0;
}

void BubbleSort(char* A[], int N){
  int n, i, j;
  char B[N][2];
  char x[2];
  n = N;
  for(i=0;i<N;i++)
    B[i][0]=A[i][0],B[i][1]=A[i][1];

  for(i=0; i<N-1; i++){
    for(j=N-1; j>i; j--)
      if(B[j][1] < B[j-1][1]){
	x[0] = B[j-1][0];
	x[1] = B[j-1][1];
	B[j-1][0] = B[j][0];
	B[j-1][1] = B[j][1];
	B[j][0] = x[0];
	B[j][1] = x[1];
      }
  }
  for(i=0; i<N; i++){
    printf("%c%c",B[i][0],B[i][1]);
    i < N-1 ? printf(" "):printf("\n");
    C[i] = B[i][0];
  }
  printf("Stable\n");
}

void SelectionSort(char* A[], int N){
  int i, j, min;
  char x[2];
  for(i=0; i<N-1; i++){
    min = i;
    for(j=i; j<N; j++){
      if(A[j][1] < A[min][1])
	min = j;
    }
    x[0] = A[i][0];
    x[1] = A[i][1];
    A[i][0] = A[min][0];
    A[i][1] = A[min][1];
    A[min][0] = x[0];
    A[min][1] = x[1];
  }
  for(i=0; i<N; i++){
    printf("%c%c",A[i][0],A[i][1]);
    i < N-1 ? printf(" "):printf("\n");
    D[i] = A[i][0];
  }
}