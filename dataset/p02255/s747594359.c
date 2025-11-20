#include<stdio.h>
int main(){
  int i,j,a[100],v,n,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(k=0;k<n;k++){
    printf("%d",a[k]);
    if(k!=n-1)printf(" ");
  }

  printf("\n");

  for(i=1;i<n;i++){
    v=a[i];
    j=i-1;
    while(j>=0&&v<a[j]){
      a[j+1]=a[j];
      j--;  
    }
    a[j+1]=v;
    
    for(k=0;k<n;k++){
      printf("%d",a[k]);
      if(k!=n-1)printf(" ");
    }

    printf("\n");
    
  }
  
  return 0;
}

