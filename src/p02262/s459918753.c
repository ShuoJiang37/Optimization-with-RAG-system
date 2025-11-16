#include <stdio.h>

void insertionSort(int *,int,int);
void shellSort(int *,int);

int m=1;
int cnt;
int G[100]={1};

int main(){
  int i,j,N,k;
  int A[1000000];

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  cnt=0;

  for(i=1,j=0;i<=N;i=i*3+1,j++){G[j]=i;}
  for(i=0;i*2<j;i++){
    k=G[j-i-1];
    G[j-i-1]=G[i];
    G[i]=k;
  }
  m=j;
  
  shellSort(A,N);

  printf("%d\n",m);
  for(i=0;i<m;i++){
    if(i)printf(" ");
    printf("%d",G[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  for(i=0;i<N;i++){
    printf("%d\n",A[i]);
  }

  return 0;
}

void insertionSort(int A[],int N,int g){
  int i,j,v;

  for(i=g;i<N;i++){
    v = A[i];
    j = i - g;

    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(int A[],int N){
  int i;

  for(i=0;i<m;i++)insertionSort(A,N,G[i]);
}


