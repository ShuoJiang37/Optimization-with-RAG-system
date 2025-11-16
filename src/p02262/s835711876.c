#include<stdio.h>

int insertionSort(int *A,int n,int g){

  int i,cnt=0,v,j;


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

  return cnt;
}


void shellSort(int *A,int n){

  int cnt=0,m=0,G[n],i,cnt1;

  //printf("wa-i\n");
  
  for(i=1;i<=n;i=3*i+1){

    G[m]=i;
    m++;

  }
  
  // for(i=0;i<m;i++){
  //    printf("%d",G[i]);
  // }
  
  for(i=0;i<m;i++){
    cnt1=insertionSort(A,n,G[m-i-1]);
    cnt+=cnt1;
    // printf("%d\n",cnt);
  }
  
  printf("%d\n",m);

  for(i=0;i<m;i++){
    
    printf("%d ",G[m-i-1]);
    
  }
  printf("\n");
  printf("%d\n",cnt);

}


int main( ){

  int i,n,A[1000000];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  shellSort(A,n);
  
  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }

  return 0;


}