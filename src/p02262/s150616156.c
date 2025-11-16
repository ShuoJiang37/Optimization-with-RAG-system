#include<stdio.h>

int cnt=0;
int main(){
  int i,j,N,A[1000000],ii,ij,ikey;
  int m=0,G[100],d=3;
  //array input
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);
  //shellsort
  G[0]=1;m++;
  //Make G
  while((G[m]=G[m-1]+d)<N&&m<100){
    m++;
    d*=3;
  }
  printf("%d\n",m);
  //---------
  
  for(i=m-1;i>=0;i--){
    printf("%d ",G[i]);
   
    //insertionSort
    ii=0,ikey=0,ij=0;
    for(ii=G[i];ii<N;ii++){
      ikey=A[ii];
      ij=ii-G[i];
      while(ij>=0&&A[ij]>ikey){
	A[ij+G[i]]=A[ij];
	ij=ij-G[i];
	cnt++;
      }
      A[ij+G[i]]=ikey;
    }
    //-------------
  }
  //------------------
  printf("\n");
  printf("%d\n",cnt);
  
  for(j=0;j<N;j++)printf("%d\n",A[j]);
  
  return 0;
}

