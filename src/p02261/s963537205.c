#include <stdio.h>
#include <stdlib.h> 
#define MAX 36

typedef struct card{
  char mark;
  int value;
}CARD;
 
void swap(CARD *x,CARD *y){
  CARD temp;
  temp=*x;
  *x=*y;
  *y=temp;
}
 
 
void bubbleSort(CARD *A,int n){
  int i,j;
  for(i=0; i<n-1; i++){
    for(j=n-1; j>i; j--){
      if(A[j].value < A[j-1].value) swap(&A[j],&A[j-1]);
    }
  }
}
 
void selectionSort(CARD *A,int n){
  int i,j,minj,flag;
    for ( i = 0 ; i < n ; i++ ) {
        minj = i;
        flag = 0;
        for ( j = i ; j < n ; j++ ) {
            if ( A[j].value < A[minj].value ) {
                minj = j;
                flag = 1;
            }
        }
        if (flag) {
            swap(&A[i], &A[minj]);
        }
    }
}

void printStable(CARD *A1, CARD *A2, int N)
{
  int i,cnt=0;
  for ( i = 0 ; i < N ; i++ ) {
    if (A1[i].mark == A2[i].mark) {
      cnt++;
    }
  }
  printf("%s\n", ((cnt == N) ? "Stable" : "Not stable"));
}
 
int main(){
  CARD R1[MAX];
  CARD R2[MAX];
  int i,j,n;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf(" %c%d",&R1[i].mark,&R1[i].value);
    R2[i]=R1[i];
  }
  bubbleSort(R1,n);
  for(i=0; i<n; i++){
    printf("%c%d",R1[i].mark,R1[i].value);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  printf("Stable\n");
  selectionSort(R2,n);
  for(i=0; i<n; i++){
    printf("%c%d",R2[i].mark,R2[i].value);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  printStable(R1, R2, n);
  return 0;
}