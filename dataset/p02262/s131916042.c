#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cnt = 0;

void insertSort(int *A,int n,int g);

int main(){
  int n;
  int m = 0;
  int i,j;
  int *A;
  int G[20];

  scanf("%d", &n);
  A = malloc(sizeof(int) * n);
  for(i=0; i<n; i++) scanf("%d", &A[i]);

  G[0] = 0;
  
  while(1){
    if(n < 3*G[m]+1) break;
    G[m+1] = 3*G[m] + 1;
    m++;
 }

 for(i=m; i>0; i--)
   insertSort(A,n,G[i]);

  printf("%d\n", m);
  
  for(i=m; i>=1; i--)
    printf("%d ", G[i]);

  printf("\n");
  printf("%d\n", cnt);

  for(i=0; i<n; i++)
    printf("%d\n", A[i]);

  return 0;
}

void insertSort(int *A,int n,int g){
  int i,j;
  int key;
  for(i=g; i<n; i++){
    j = i;
    key = A[i];
    while(0 <= j-g){
      if(A[j-g] <= key) break;
      A[j] = A[j-g];
      j = j-g;
      cnt++;
    }
   A[j] = key;
 }
}

