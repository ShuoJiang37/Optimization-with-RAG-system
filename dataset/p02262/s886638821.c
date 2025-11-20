#include<stdio.h>

int cnt;
int l;
int A[1000000];
int n;
int G[1000000];
int buf;

void insertionSort(int A[], int n, int g){
  int i, j, v;
  for(i = g; i < n; i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void shellSort(int A[], int n){
  int h = 1, i = 0;
  while(1){
    if(h > n) break;
    G[i++] = h;
    h = 3 * h + 1;
  }
  buf = i;

  for(i = buf - 1; i >= 0; i--) insertionSort(A, n, G[i]);
}

int main(){
  int i, n;
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&A[i]);
  cnt = 0;

  shellSort(A, n);

  printf("%d\n",buf);
  for(i = buf - 1; i >= 0; i--){
    printf("%d",G[i]);
    if(i) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  for(i = 0; i < n; i++) printf("%d\n",A[i]);

  return 0;
}