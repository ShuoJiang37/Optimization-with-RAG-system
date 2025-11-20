#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

int k =VMAX;
for ( i= 0; i < n;i++){
	scanf("%d",&A[i]);
}
for ( i =0; i <= k;i++){
	C[i] = 0;
}
for ( j = 0; j< n; j++){
	C[A[j]]++;
}
for ( i = 0; i <  k ; i++){
C[i+1]+= C[i];
}
for ( j = n-1 ; j >= 0; j--){
	B[C[A[j]]] = A[j];
	C[A[j]]--;
}
for ( i = 1;i <= n;i++){
printf("%d" ,B[i]);
if ( i != n){ printf(" ");}
}
printf("\n");
  return 0;
}

  /* your code 
  1 CountingSort(A, B, k)
2     for i = 0 to k
3         C[i] = 0
4
5     /* C[i] に i の出現数を記録する 
6     for j = 1 to n
7         C[A[j]]++
8
9     /* C[i] に i 以下の数の出現数を記録する
10    for i = 1 to k
11        C[i] = C[i] + C[i-1]
12
13    for j = n downto 1
14        B[C[A[j]]] = A[j]
15        C[A[j]]--*/

