#include<stdio.h>
  
static const int N = 1000000;
 
int cnt;
  
int main(){
  int n, i, j, k, key,m=6;
  int A[N+1],G[6]={2500, 150, 40, 13, 4, 1};
 
  scanf("%d", &n);
  
  cnt = 0;
 
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
    
  for(i = 0;i<m;i++){
    if(G[i]<=n){
      k = i;
      break;
    }
  }
  for(i = k; i < m; i++){
    insertionSort(A, n, G[i]);
 
  }
  printf("%d\n",m - k);
 
  for(i = k; i<m; i++){
    if(i!=k)printf(" ");
    printf("%d",G[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
 
  trace(A, n);
 
  return 0;
}

void insertionSort(int A[], int n, int g){
  int i,j,v;
 
  for(i = g; i<n; i++){
    v = A[i];
    j = i-g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j-g;
      cnt++;
    }
      A[j+g] = v;
  }
}
 
void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    printf("%d\n", A[i]);
  }
}