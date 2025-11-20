#include <stdio.h>

int G[10000];
int cnt=0,c=0;

void insertionSort(long A[],int n,int g){
  int v,i,j;
  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0&&A[j]>v){
      A[j+g]=A[j];
      j=j-g;
      cnt++;
    }
    A[j+g]=v;
  }
}

void shellSort(long A[],int n){
  int m,i;
  m=1;
  while(1){
    if(m>n)break;
    G[c]=m;
    m=m*3+1;
    c++;
  }
  for(i=c-1;i>=0;i--){
    insertionSort(A,n,G[i]);
  }
}

int main(){
  int i,n;
  long A[1000000];
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%ld",&A[i]);
  }

  shellSort(A,n);

  printf("%d\n",c);
  for(i=c-1;i>=0;i--){
    printf("%d",G[i]);
    if(i>0)printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  for(i=0;i<n;i++){
    printf("%ld\n",A[i]);
  }
  return 0;
}

