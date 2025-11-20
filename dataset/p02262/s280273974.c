#include <stdio.h>
#define N 1000005
#define SIZE 14
 
void insertionSort(int n,int g);
void shellSort(int n);
 
int A[N];
int G[SIZE] = {1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484};
int cnt=0,m;
 
int main(){
  int i,j,n;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
     
  shellSort(n);
     
  printf("%d\n",m);
  for(i=m-1; i>=0; i--){
    printf("%d",G[i]);
    if(i) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  for(i=0; i<n; i++) printf("%d\n",A[i]);
 
  return 0;
 
}
 
 
void insertionSort(int n,int g){
  int v,i,j;
  for(i=g; i<n; i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
}
 
 
void shellSort(int n){
  int i,h;
  for(h=1; ; ){
    if(h > n) break;
    h = 3*h +1;
  }
  for(i=0; i<SIZE; i++){
    if(h == G[i]) m = i;
  }
  for(i=m-1; i>=0; i--){
    insertionSort(n,G[i]);
  }
}