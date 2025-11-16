#include <stdio.h>

void insertionSort(int *,int,int);
void shellSort(int *,int);

static int cnt=0;


int main(void){
  int A[1000000],m,n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  shellSort(A,n);
  printf("\n%d\n",cnt);

  for(i=0;i<n;i++)
    printf("%d\n",A[i]);
  return 0;
}

void insertionSort(int *A,int n,int g){
  int i,j,v;
  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0 && A[j]>v){
      A[j+g]=A[j];
      j=j-g;
      cnt++;
    }
    A[j+g]=v;
  }
}

void shellSort(int *A,int n){
  int i,m,h;
  int G[100];
  cnt=0;
  for(h=1,i=0;;i++){
    if(h>n)break;
    G[i]=h;
    h=3*h+1;
  }
  m=i;
  printf("%d\n",m);
  for(i=m-1;i>=0;i--){
    insertionSort(A,n,G[i]);
    printf("%d",G[i]);
    if(i!=0)printf(" ");
  }
}
