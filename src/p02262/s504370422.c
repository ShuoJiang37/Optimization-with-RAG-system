#include <stdio.h>

int A[1000000],G[1000000];
int n,count,glen;

void insertionSort(int *A,int n,int g){
  int v,j,i;
  for(i = g;i < n;i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j + g] = A[j];
      j -= g;
      count++;
    }
    A[j + g] = v;
  }
}

void shellSort(int *A,int n){
  int h=1,i=0;
  while(1){
    if(h > n) break;
    G[i] = h;
    h = 3*h + 1;
    i++;
  }
  glen = i;
  for(i = glen-1;i >= 0;i--) insertionSort(A,n,G[i]);
}

int main(){
  int i;
  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&A[i]);
  count = 0;
  shellSort(A,n);

  printf("%d\n",glen);
  for(i = glen - 1;i >= 0;i--){
    printf("%d",G[i]);
    if(i) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  for(i = 0;i < n;i++) printf("%d\n",A[i]);

  return 0;
}