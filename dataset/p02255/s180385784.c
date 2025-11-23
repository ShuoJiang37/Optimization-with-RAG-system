#include<stdio.h>
#define N 101

int main(){
  int a[N],i,j,n,p,t,q,m;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(p=0;p<n;p++){
    printf("%d",a[p]);
  if(p!=n-1){
      printf(" ");
    }
  }printf("\n");

  for(i=1;i<n;i++){
    t=a[i];
    j=i-1;
    while(j>=0&&a[j]>t){
      a[j+1]=a[j];
      j--;
    }a[j+1]=t;
    for(p=0;p<n;p++){
      printf("%d",a[p]);
    if(p!=n-1){
        printf(" ");
      }
    }printf("\n");
  }
}

