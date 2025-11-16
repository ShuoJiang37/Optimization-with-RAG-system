#include<stdio.h>
#define N 1000000

void insertionSort(int *,int ,int);
void shellSort(int *,int);

int cnt=0;
 
int main(){
  int i,A[N],n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  shellSort(A,n);
  printf("%d\n",cnt);
 
  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }
  return 0;
}


void insertionSort(int *A,int n, int g){
int i,v,j;
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
  int i,m=0,S[n];
  S[0] = 0;
  for(i=0;i<n;i++){
    S[i+1] = 3*S[i]+1;
    m++; 
    if(S[i+1]>N) break;
  }
  while(S[m]>n){
    m--;
  }
  printf("%d\n",m);
  
  for(i=m;i>1;i--){
    printf("%d ",S[i]);
  }
  printf(" %d\n",S[1]);
  for(i=m ; i>=0 ; i--){
    insertionSort(A,n,S[i]);
  }
}

