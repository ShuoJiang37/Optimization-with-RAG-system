#include <stdio.h>

long long cnt;
int l;
int A[1000000];
int n;
int G[1000000];
int size;

void insertionSort(int *A,int n,int g){
  int i,v,j;

  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;

    while(j>=0&&A[j]>v){
      A[j+g]=A[j];
      j-=g;
      cnt++;
    }

    A[j+g]=v;

  }

}

void shellSort(int *A,int n){
  int h,i;

  for(h=1,i=0;;i++){
    if(h>n) break;

    G[i]=h;
    h=3*h+1;
  }
  size=i;

  for(i=size-1;i>=0;i--){
    insertionSort(A,n,G[i]);
  }

}

int main(){
  int i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  cnt=0;

  shellSort(A,n);

  printf("%d\n",size);

  for(i=size-1;i>=0;i--){
    printf("%d",G[i]);
    if(i!=0) printf(" ");
  }
  printf("\n");
  printf("%lld\n",cnt);

  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }

  return 0;
}
