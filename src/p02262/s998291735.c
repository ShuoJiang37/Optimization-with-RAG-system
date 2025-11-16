#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *,int,int);
void shellSort(int *,int);

int cnt;

int main(int argc, char const *argv[]) {

  int num;
  int i;
  int line[1000000];

  scanf("%d",&num);

  for( i = 0 ; i < num ; i++ ){
    scanf("%d",&line[i]);
  }

  shellSort(line,num);

  for( i = 0 ; i < num ; i++ ){
    printf("%d\n",line[i]);
  }


  return 0;
}

void insertionSort(int *A, int n, int g){

  int i,j;
  int v;

  for( i = g ; i < n ; i++ ){

    v = A[i];
    j = i - g;

    while( j >= 0 && A[j] > v ){

      A[j+g] = A[j];
      j -= g;
      cnt++;

    }

    A[j+g] = v;

  }

}

void shellSort(int *A, int n){

  int i;
  int G[14] = {1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391584};
  int m = 14;
  int count = 0;

  for( i = m-1 ; i >= 0 ; i-- ){
    insertionSort(A,n,G[i]);
  }

  for( i = m-1 ; i >= 0 ; i-- ){
    if( n >= G[i] ){
      count++;
    }
  }

  m = count;

  printf("%d\n",m);

  for( i = m-1 ; i >= 0 ; i-- ){
    if( n >= G[i] ){
      printf("%d",G[i]);
      if( i ){
        printf(" ");
      }
    }
  }

  printf("\n%d\n",cnt);

}