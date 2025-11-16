#include <stdio.h>

#define MAX_M 100
#define MAX_N 1000000
#define min(a,b) (a < b ? a : b)

void insertionSort(int*,int,int,int*);
void shellSort(int*,int);
void print(int*,int*,int,int,int);

int main(){
  int n,A[MAX_N],i;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }
  shellSort(A,n);
  return 0;
}

void insertionSort(int *A,int n,int g,int *cnt){
  int i,j,v;
  for(i = g ; i < n ; i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      (*cnt)++;
    }
    A[j+g] = v;
  }
}

void shellSort(int *A,int n){
  int G[MAX_M],i,m = 1,cnt = 0;
  
  while(m*5+1 < n){ m = m*5+1; }
  for(i = 0 ; m > 0 ; m /= 5,i++){
    G[i] = m;
  }
  m = min(i,MAX_M);
  for(i = 0 ; i < m ; i++){
    insertionSort(A,n,G[i],&cnt);
  }
  print(A,G,n,m,cnt);
}

void print(int *A,int *G,int n,int m,int cnt){
  int i;
  printf("%d\n",m);
  for(i = 0 ; i < m ; i++){
    printf("%d%c",G[i],(i < m-1 ? ' ' : '\n'));
  }
  printf("%d\n",cnt);
  for(i = 0 ; i < n ; i++){
    printf("%d\n",A[i]);
  }
}