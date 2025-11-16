#include <stdio.h>

static long cnt=0;

void insertionSort(long* A, long n, long g){
  int i;
  for (i=g;i<n;i++) {
    int k=A[i];
    int j=i-g;
    while((j>=0)&&(A[j]>k)) {
      A[j+g]=A[j];
      j-=g;
      cnt++;
      A[j+g]=k;
    }
  }
}

void shellSort(long *A, long n){
  long G[100];
  long m,i;
  G[0]=1;
  for(m=1; m<100; m++){
    long g=G[m-1]*3+1;
    if(g<=n)
      G[m]=g;
    else
      break;
  }
  cnt=0;
  for(i=m-1;i>=0;i--)
    insertionSort(A,n,G[i]);
  printf("%ld\n",m);
  for(i=m-1; i>0; i--)
    printf("%ld ", G[i]);
  printf("%ld\n",G[0]);
  printf("%ld\n",cnt);
}

int main(void){
  long N,n;
  long A[1000000];
  scanf("%ld\n",&N);
  for(n=0;n<N;n++)
    scanf("%ld\n",&A[n]);
  shellSort(A,n);
  for(n=0;n<N;n++)
    printf("%ld\n",A[n]);
  return 0;
}