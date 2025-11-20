#include <stdio.h>
void shellSort(int*,int);
void insertionSort(int*,int,int);
int cnt = 0;

int main(){
  int i,A[1000000],n;
    scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  
  shellSort(A,n);
  for(i = 0; i < n; i++){
    printf("%d\n",A[i]);
  }
  
  return 0;
  
}

void insertionSort(int* A, int n, int g){
  int i,j,k;
  for(i = g; i < n; i++){
    k = A[i];
    j = i - g;
    while(j >= 0 && A[j] > k){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
      A[j+g] = k;
    }
  }
}

void shellSort(int* A, int n){
  int m=1,i,G[1000000];
  G[0] = 1;
  for(i = 0;;i++){
    G[i+1] = 3*G[i] + 1;
    if(G[i+1] > n) break;
    m++;
  }
  
  for(i = m-1; i >= 0; i--){
    insertionSort(A,n,G[i]);
  }
  
  printf("%d\n",m);
  for(i = m-1; i > 0; i--){
    printf("%d ",G[i]);
  }
  
  printf("%d\n",G[i]);
  printf("%d\n",cnt);
  
}


