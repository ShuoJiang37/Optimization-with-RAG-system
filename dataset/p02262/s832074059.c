#include<stdio.h>
int cnt;
void insertionSort(int*,int,int);

int main(){
  int n,A[1000000],i,m=1,hn=1;
  int G[100];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  
  //shellSort
  cnt=0;
  for(i=0; i<100; i++){
    hn=hn*3+1;
    if(n<=hn){
      break;
    }
    m++;
  }

  G[m-1]=1;
  for(i=m-2; i>=0; i--){
    G[i]=G[i+1]*3+1;
  }
  /*for(i=0; i<=m; i++){
    printf("G[%d]:%d\n",i,G[i]);
  }*/
  for(i=0; i<=m; i++){
    insertionSort(A, n, G[i]);
  }

  printf("%d\n",m);
  for(i=0; i<m; i++){
    if(i){
      printf(" ");
    }
    printf("%d",G[i]);
  }
  printf("\n%d\n",cnt);
  for(i=0; i<n; i++){
    printf("%d\n",A[i]);
  }

  return 0;
}

void insertionSort(int* A,int n,int g){
  int i,v,j;
  for(i=g; i<n; i++){
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

