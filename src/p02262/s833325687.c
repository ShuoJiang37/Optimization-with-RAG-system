#include <stdio.h>
#define N 1000000
int insertionSort(int *A, int n, int g){
int i;
 int j;
 int v;
 int cnt=0;
 for(i=g;i<n;i++){
   v = A[i];
   j = i - g;
   while( j >= 0 && A[j] > v){
     A[j+g] = A[j];
     j = j - g;
     cnt++;
   }
   A[j+g] = v;
 }
 return cnt;
}
 
void shellSort(int *A, int n){
  int  i;
  int  m=5;
  int  cnt=0;
  int  m_cnt=0;
  int  G[5]={1000,100,10,4,1};
  for(i=0;i<m;i++){
    if(G[i]<=n){
      cnt += insertionSort(A, n, G[i]);
      m_cnt++;
    }
  }
  printf("%d\n",m_cnt);
     
  for(i=0;i<m-1;i++){
    if(G[i]<=n){
      printf("%d ",G[i]);
    }
  }
  printf("%d\n",G[i]);
  printf("%d\n",cnt);
  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }
}
 
int main(){
  int g=1;
  int i;
  int j;
  int n;
  int data[N];
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  shellSort(data,n);
   
  return 0;
}