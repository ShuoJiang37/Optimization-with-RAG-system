#include<stdio.h>

int cnt=0;

void insertionSort(int A[],int n, int g);
void shellsort(int A[],int n);
int main(void){

  int n,i;
  scanf("%d",&n);
  int a[n];

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  shellsort(a,n);

  return 0;
}

void insertionSort(int A[],int n, int g){
  int i,v,j;

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

void shellsort(int A[],int n){
  int G[10000],m,i;
  cnt=0;

  G[0]=0;
  for(i=1;i<n+1;i++){
    G[i]=G[i-1]*4+1;
    if(G[i]>=n/4){
      m=i;
      break;
    }
  }
  printf("%d\n",m);


  for(i=0;i<m;i++){
    if(i==0){
      printf("%d",G[m-i]);
    }
    else{
      printf(" %d",G[m-i]);
    }
    insertionSort(A,n,G[m-i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }
}

