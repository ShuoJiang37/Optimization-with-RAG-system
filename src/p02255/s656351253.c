#include<stdio.h>
int s[110];
void shunxushuchu(int a[],int n){
   int i;
   for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
   }printf("\n");
}
void charupaixu(int a[],int n){
  int j,i,v;
  for(i=1;i<n;i++){
    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
        a[j+1]=a[j];
        j--;
    }a[j+1]=v;
    shunxushuchu(a,n);
  }
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&s[i]);
    shunxushuchu(s,n);
    charupaixu(s,n);
return 0;
}