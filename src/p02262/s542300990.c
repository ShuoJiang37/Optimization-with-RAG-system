#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Insertion(int*, int, int);
void Shell(int*, int);
int cnt=0, m, *G;

int main(){
  int i, n, *A;
  scanf("%d",&n);
  A = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);
  Shell(A, n);
  printf("%d\n",m);
  for(i=0; i<m; i++){
    printf("%d",G[i]);
    printf(i != m-1 ? " " : "\n");
  }
  printf("%d\n",cnt);
  for(i=0; i<n; i++){
    printf("%d",A[i]);
    printf("\n");
  }
  free(A);
  free(G);
  return 0;
}

void Insertion(int* A, int n, int g){
  int i, j, v;
  for(i=g; i<n; i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void Shell(int* A, int n){
  int i;
  cnt = 0;
  for(i=0; i<n; i++)
    if(n < (pow(3,i+1)-1) / 2) break;
  m = i;
  G = (int *)malloc(sizeof(int) * m);
  for(i=0; i<m; i++)
    G[i] = (pow(3,m-i)-1) / 2;
  for(i=0; i<m; i++)
    Insertion(A, n, G[i]);
}