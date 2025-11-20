
  #include<stdio.h>
#include<stdlib.h>
 
#define MAX 10000

void countSort(short *,short *,int);
 
int main(){

  unsigned short *A, *B;
  int i,n;
 
  scanf("%d",&n);
   
  A = malloc(sizeof(int) * n + 1);
  B = malloc(sizeof(int) * n + 1);
 
  for(i = 1;i <= n;i ++)scanf("%hd",&A[i]);
   
  countSort(A,B,n);
 
  for(i = 1;i < n;i ++)
    {
    printf("%hd ",B[i]);
    }
  
  printf("%hd\n",B[n]);
  
  free(A);
  free(B);
  
  return 0;
}
     
void countSort(short *A,short *B,int n){

  int i,j;
  int C[MAX+1];
 
  for(i = 0;i <= MAX;i ++)
    {
      C[i] = 0;
    }
  
  for(j = 1;j <= n;j ++)
    {
      C[A[j]]++;
    }
  
  for(i = 1;i <= MAX;i ++)
    {
	C[i] = C[i] + C[i-1];
    }
  
  for(j = n;j >= 1;j --)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
}