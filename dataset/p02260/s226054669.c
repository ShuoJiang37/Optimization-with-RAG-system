#include <stdio.h>

int selectionSort(int A[], int N){
  int i, j, t, sw=0, min;
  for(i=0; i<N-1; i++){
    min = i;
    for(j=i; j<N; j++){
      if(A[j]<A[min]) min=j;
    }
    t = A[i];
    A[i] = A[min];
    A[min] = t;
    if(i!=min) sw++;
  }
  return sw;
}

int main(){
  int N, i, A[100], sw;

  scanf("%d", &N);
  
  for(i=0; i<N; i++) scanf("%d", &A[i]);

  sw = selectionSort(A, N);

  for(i=0; i<N; i++){
    printf("%d", A[i]);
    if(i!=N-1) printf(" ");
  }
  
  printf("\n");
  printf("%d\n", sw);
  return 0;
}

