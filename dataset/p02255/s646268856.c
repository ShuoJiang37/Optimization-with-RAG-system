#include <stdio.h>
#include <stdlib.h>

int main(){
int N,i,j,v,a;
int *A;


scanf("%d",&N);
A = (int *)malloc(N * sizeof(int));
for(i=0;i<N;i++)
scanf(" %d",&A[i]);






// insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
  for (i=0; i<=N-1;i++ ){
    v = A[i];
    j = i - 1;

     while( j >= 0 && A[j] > v){
           A[j+1] = A[j];
           j--;
           A[j+1] = v;
     

     }
   a = i;
   for(i=0;i<N;i++){
   printf("%d",A[i]);
        if(i != N-1) printf(" ");
               
   }
   printf("\n");
   i = a;
  }



free(A);
return 0;

}
