#include<stdio.h>
#include<stdlib.h>
#define N 2000000
#define MAX 10000

int main(){
  int a[N];
  int n,i,c[MAX+1];
  
  scanf("%d",&n);

  int b[n];
  
  for(i=1;i<=n;i++) scanf("%d",&a[i]);

  for(i=0;i<=MAX;i++){
    c[i]=0;
  }

  for(i=0;i<n;i++){
    c[a[i+1]]++;
  }

  for(i=1;i<MAX;i++){
    c[i]=c[i]+c[i-1];
  }

  for(i=n;i>0;i--){
    b[c[a[i]]]=a[i];
    c[a[i]]--;
  }
  
  for(i=1;i<n;i++) printf("%d ",b[i]);
  printf("%d\n",b[i]);
  
  return 0;
}

