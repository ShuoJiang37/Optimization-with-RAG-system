#include <stdio.h>
#define N 1000000
void sellSort(int *A,int n);
void insertionSort(int *A,int n, int g);
int cnt;
int m=7;
int main(){
  int i,j,n,A[N];
  scanf("%d",&n);
   
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
   
   
  sellSort(A,n);
   
  
   
  return 0;
   
}
 
void sellSort(int *A,int n){
  int i,j=0,G[]={1093,364,121,40,13,4,1};
   
  cnt = 0;
  if(n<1093)j++;
  if(n<364)j++;
  if(n<121)j++;
  if(n<40)j++;
  if(n<13)j++;
  if(n<4)j++;
   
  for(i=j;i<m;i++){
     
    insertionSort(A,n,G[i]);
  }
  printf("%d\n",m-j);
   
  for(i=j;i<m;i++){
    if(i<m-1)
      printf("%d ",G[i]);
    else
      printf("%d\n",G[i]);
  }
  printf("%d\n",cnt);
  for(i=0;i<n;i++)printf("%d\n",A[i]);
   
   
}
 
 
void insertionSort(int *A,int n, int g){
  int i,j,v;
   
  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0 && A[j]>v){
      A[j+g] = A[j];
      j=j-g;
      cnt++;
       
    }
    A[j+g] = v;
  }
}