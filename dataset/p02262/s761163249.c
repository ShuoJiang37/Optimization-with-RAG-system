#include<stdio.h>

void insertionSort(int [], int, int);
void shellSort(int [],int);

int c=0;

main() {
  int i,j,n;
  int A[1000000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  shellSort(A, n);
  printf("%d\n",c);
  for(i=1;i<=n;i++){
    printf("%d\n",A[i-1]);
  }
  return 0;
}

void insertionSort(int A[], int n, int g){

  int i,j,v;
  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0 && A[j]>v){
      A[j+g]=A[j];
      j=j-g;
      c++;
    }
    A[j+g]=v;
  }
}


void shellSort(int A[],int n){

  int i,m=0;
  int B[n];

  B[0]=0;
  for(i=0;i<n;i++){
    B[i+1]=3*B[i]+1;
    m++;
    if(B[i+1]>1000000){
      break;
    }
  }
  while(B[m] > n){
    m--;
  }
  printf("%d\n",m);
  for(i=m;i>1;i--){
    printf("%d ",B[i]);
  }
  printf("%d\n", B[1]);
  for(i=m;i>=0;i--){
    insertionSort(A, n, B[i]);
  }
}

