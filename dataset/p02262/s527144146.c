#include<stdio.h>
int insertionSort(int[], int, int);
void shellSort(int[],int);

int main(){
  int n, i;
  int A[1000000];

  scanf("%d",&n);
  for( i = 0 ; i < n ; i++ ){
    scanf("%d",&A[i]);
  }

  shellSort(A, n);

  for( i = 0 ; i < n ; i++ ){
    printf("%d\n",A[i]);
  }

  return 0;
}

int insertionSort(int A[], int n, int g){
  int i, j, cnt=0, v;
  for( i = g ; i < n ; i++ ){
    v = A[i];
    j = i - g;
    while( j >= 0 && A[j] > v ){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
  return cnt;
}

void shellSort(int A[], int n){
  int i=0, m, cnt=0, a=1;
  int G[100];

  while(1){
    if( a > n ) break;
    G[i++] = a;
    a = 3 * a + 1;
  }
  m = i;

  printf("%d\n",m);
  for( i = m-1 ; i > 0 ; i-- ){
    printf("%d ",G[i]);
  }
  printf("%d\n",G[0]);

  for( i = m-1 ; i >= 0 ; i-- ){
    cnt += insertionSort(A, n, G[i]);
  }
  printf("%d\n",cnt);
}

