#include <stdio.h>
#include <string.h>
#define N 100

int main (){
  int i,j,n,a1[N],a[N],tmp,k;
  char c0[N+1],c[N+1],c1[N+1],tmpc,A[2][11]={"Stable","Not stable"};
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&c0[i],&a[i]);
    a1[i] =a[i];
  }
  strcpy(c,c0);
  strcpy(c1,c0);

  for(i=0;i<n;i++){

    for(j=n-1;j>i;j--){

      if(a[j]<a[j-1]){
	tmp=a[j];
	tmpc=c[j];
	a[j]=a[j-1];
	c[j]=c[j-1];
	a[j-1]=tmp;
	c[j-1]=tmpc;
      }
    }
  }
    for(i=0;i<n;i++){
      if(i==n-1) printf("%c%d\n",c[i],a[i]);
      else printf("%c%d ",c[i],a[i]);
  }
  printf("%s\n",A[0]);

 
  for(i=0;i<n;i++){
    k=i;
    for(j=i;j<n;j++){
      if(a1[j]<a1[k])k=j;
    }
    if(k!=i){
      tmp=a1[k];
      tmpc=c1[k];
      a1[k]=a1[i];
      c1[k]=c1[i];
      a1[i]=tmp;
      c1[i]=tmpc;
    }
  }
    for(i=0;i<n;i++){
      if(i==n-1) printf("%c%d\n",c1[i],a1[i]);
      else printf("%c%d ",c1[i],a1[i]);
    }
    if(strcmp(c1,c)==0)printf("%s\n",A[0]);
    else printf("%s\n",A[1]);
    
    



  return 0;
}