#include<stdio.h>
#define N 100
int main(){
  int i,j,n,A[N],flag,a,b=0,m;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }flag=1;
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(A[j]<A[j-1]){
        a=A[j];
        A[j]=A[j-1];
        A[j-1]=a;
        flag=1;
        b++;
      }
    }
  }for(m=0;m<n-1;m++){
    printf("%d",A[m]);
    printf(" ");
  }printf("%d\n",A[n-1]);
  printf("%d\n",b);
}

