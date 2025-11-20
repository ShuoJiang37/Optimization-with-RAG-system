#include <stdio.h>
#define N 100

int main (){
  int n,i,j,c,a,minj,count;
  int b[N];  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    b[i]=a;
    //printf("%d",b[i]);
  }

  for(i=0;i<=n-1;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(b[j]<b[minj]){
	minj = j;
      }
    }
    if(b[minj]!=b[i]){
    c = b[i];
    b[i]=b[minj];
    b[minj]=c;
    count++;
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",b[i]);
  }
  printf("%d\n",b[i]);
  printf("%d\n",count);
  
  return 0;
}

