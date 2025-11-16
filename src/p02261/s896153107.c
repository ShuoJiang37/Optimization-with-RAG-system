#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char mark;
  int num;
}Card;

void BubbleSort(Card [], int);
void SelectionSort(Card [], int);
int compareArray(Card **, Card [], int [], int, int);
void printResult(Card [], Card [], int, int, int);

int main(){
  int n, pair=0;
  Card *A, *B;
  Card **order;
  int *idxnum;
  int number[9]={0};
  int Astable, Bstable;
  int ind, ex;
  int i, j;

  scanf("%d",&n);

  A = (Card *)malloc(n*sizeof(Card));
  B = (Card *)malloc(n*sizeof(Card));
 
  for(i=0; i<n; i++){
    scanf(" %c%d",&A[i].mark ,&A[i].num);
    B[i] = A[i];
    number[A[i].num - 1]++;
  }

  for(i=0; i<9; i++){
    if(number[i]>=2)
      pair++;
  }

  order = (Card **)malloc(pair*sizeof(Card *));
  idxnum = (int *)malloc(pair*sizeof(int));

  ind = 0;
  for(i=0; i<9; i++){
    if(number[i]>=2){
      order[ind] = (Card *)malloc(number[i]*sizeof(Card));

      ex = 0;
      for(j=0; j<n; j++){
	if(A[j].num == (i+1)){
	  order[ind][ex] = A[j];
	  ex++;
	}
      }
      idxnum[ind] = ex;
      ind++;
    }

    if(ind>=pair)
      break;
  }
  
  BubbleSort(A,n);
  SelectionSort(B,n);

  Astable = compareArray(order, A, idxnum, pair, n);
  Bstable = compareArray(order, B, idxnum, pair, n);
 
  printResult(A,B,n,Astable,Bstable);
  
  free(A);
  free(B);
  for(i=0; i<pair; i++)
    free(order[i]);
  free(order);
  free(idxnum);
  return 0;
}

void BubbleSort(Card C[], int n){
  Card tmp;
  int i, j;

  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      if(C[j].num < C[j-1].num){
	tmp = C[j];
	C[j] = C[j-1];
	C[j-1] = tmp;
      }
    }
  }
}

void SelectionSort(Card C[], int n){
  int minj;
  Card tmp;
  int i, j;

  for(i=0; i<n; i++){
    minj = i;

    for(j=i; j<n; j++){
      if(C[j].num < C[minj].num)
	minj = j;
    }

    tmp = C[i];
    C[i] = C[minj];
    C[minj] = tmp;
  }
}

int compareArray(Card **order, Card C[], int idx[], int pair, int n){
  int i, j, k;
  int cnt=0;

  for(i=0; i<n; i++){
    for(j=0; j<pair; j++){
      if(order[j][0].num == C[i].num){
	for(k=0; k<idx[j]; k++){
	  if(order[j][k].mark != C[i++].mark)
	    return 0;
	}
      }
    }
  }

  return 1;
}

void printResult(Card A[], Card B[], int n, int Astable, int Bstable){
  int i;
  
  for(i=0; i<n; i++){
    printf("%c%d",A[i].mark ,A[i].num);
    if(i<n-1)
      printf(" ");
  }
  printf("\n");

  if(Astable==1)
    printf("Stable\n");
  else
    printf("Not stable\n");
  
  for(i=0; i<n; i++){
    printf("%c%d",B[i].mark ,B[i].num);
    if(i<n-1)
      printf(" ");
  }
  printf("\n");

  if(Bstable==1)
    printf("Stable\n");
  else
    printf("Not stable\n");
}

