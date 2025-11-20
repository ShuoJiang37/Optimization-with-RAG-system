#include<stdio.h>
#define N 36

typedef struct{
  char a;
  int b;
}Tru;

main(){

  int i,j,n,e,min;
  Tru c[N],d[N],s,t;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&c[i].a,&c[i].b);
    d[i]=c[i];
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(c[j].b<c[j-1].b){
	s=c[j];
	c[j]=c[j-1];
	c[j-1]=s;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%c%d ",c[i].a,c[i].b);
  }
  printf("%c%d\n",c[n-1].a,c[n-1].b);
  printf("Stable\n");

 for(i=0;i<n;i++){
   min=i;
   for(j=i;j<n;j++){
     if(d[j].b<d[min].b){ 
	min=j;
      }    
    }
    if(i!=min){
    t=d[i];
    d[i]=d[min];
    d[min]=t;
    }
 }

 for(i=0;i<n-1;i++){
     printf("%c%d ",d[i].a,d[i].b);
 }
  printf("%c%d\n",d[n-1].a,d[n-1].b);
  for(i=0;i<n;i++){
    if(c[i].a!=d[i].a){ 
      e=0; break;
    }
    else if(c[i].a==d[i].a) e=1;
  }
  if(e==0)  printf("Not stable\n");
  else if(e==1)  printf("Stable\n");
  return 0;
}