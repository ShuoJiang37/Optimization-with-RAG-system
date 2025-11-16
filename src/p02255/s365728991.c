#include <stdio.h>

int main(){
  int N;
  int A[1000];
  int i,j,v;

  scanf("%d", &N);
  for ( i = 0; i < N; i++) {
    /* code */
    scanf("%d", &A[i]);
  }
  for (i = 0; i < N; i++)
    {
        if (i == N - 1){
            printf("%d\n", A[i]);
        }
        else printf("%d ", A[i]);
    }
  for ( i = 1; i <= N-1; i++) {
    /* code */
    v=A[i];
    j=i-1;
    while (j>=0 && A[j]>v) {
      /* code */
      A[j+1] = A[j];
       j--;
      A[j+1] = v;
    }
    //表示
    for ( j = 0; j < N; j++) {
      /* code */
      if(j == N-1){printf("%d\n",A[j]);
      }else{
        printf("%d ", A[j]);
     }
    }
  }
  return 0;
}

