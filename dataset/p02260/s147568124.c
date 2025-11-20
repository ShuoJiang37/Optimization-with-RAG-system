#include<stdio.h>
int main(){
  int n,b,a[100],c,i,j,m,k=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for (  i=0;i <n;  i++) {
  m=i;
  b=0;
  for(j=i;j<n;j++){
    if(a[j]<a[m]){
      m=j;
    b=1;
    }
  }
  if(b==1){
      c=a[i];
      a[i]=a[m];
      a[m]=c;
      k++;
    }
  }
  for(i=0;i<n-1;i++){
  printf("%d ",a[i]);
}
printf("%d\n%d\n",a[n-1],k);
return 0;
}