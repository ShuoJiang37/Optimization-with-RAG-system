#include<stdio.h>
 
int main(){
  int n,a[100];
  int i,j,flag,tmp,sum;

  scanf("%d",&n);
  for(j=0;j<n;j++)scanf("%d",&a[j]);

  flag=1;
  i=0;
  while(flag){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	sum++;
      }
      flag=1;
    }
    i++;
  }

  for(j=0;j<n;j++){
    printf("%d",a[j]);
    if(j!=n-1)printf(" ");
  }

  printf("\n%d\n",sum);
  return 0;
}