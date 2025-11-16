#include<stdio.h>
#define N 100
void swap(int *, int *);

int main(){
  int n, flag=0, i, j;
  int A[N];
  int key;

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  for(i=0; i<n; i++){
    for(j=n-1; j>=0; j--){
      if(A[j] < A[j-1]){
      swap(&A[j],&A[j-1]);
      flag++;
      }
    }
  }

  for(i=0; i<n; i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }

  printf("\n%d\n",flag);

  return 0;
}

void swap(int *a,int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}