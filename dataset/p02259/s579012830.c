#include <stdio.h>
#define N 100

int bubble(int *, int);

int main(){

  int i, n, a[N], cnt;
  
  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  cnt=bubble(a, n);

  printf("%d",a[0]);
  for(i=1;i<n;i++)
    printf(" %d",a[i]);
  printf("\n%d\n",cnt);
  return 0;
}
int bubble(int *a, int n){
  int i, j, tmp, cnt=0;

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	tmp=a[j-1];
	a[j-1]=a[j];
	a[j]=tmp;
	cnt++;
      }}}
  return cnt;
}