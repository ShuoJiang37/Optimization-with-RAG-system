#include <stdio.h>

int sort(int *A,int n){
  int i,j,min,ans=0,t;

  for(i=0;i<n-1;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[j]<A[min])min=j;
    }
    t=A[i];
    A[i]=A[min];
    A[min]=t;
    if(i!=min)ans++;
  }
  return ans;
}

int main(){
  int i,n,ans;
  int A[100];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  ans=sort(A,n);

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",ans);

  return 0;
}