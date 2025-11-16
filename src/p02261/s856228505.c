#include<stdio.h>

typedef struct{
  char c;
  int value;
  }card;

int main(){
  char space;
  int i,j,n,min,flag;
  card x[36],y[36],z;
  scanf("%d\n",&n);
  for(i=0;i<n;i++){
    scanf("%c%d%c",&x[i].c,&x[i].value,&space);
    y[i]=x[i];
  }

  for(j=0;j<n;j++){
    flag=0;
    for(i=n-1;i>j;i--){
      if(x[i].value<x[i-1].value){
        z=x[i];
        x[i]=x[i-1];
        x[i-1]=z;
        flag=1;
      }
    }
    if(flag==0)break;
  }

  for(j=0;j<n;j++){
    min=j;
    for(i=j;i<n;i++){
      if(y[i].value<y[min].value)
      min=i;
    }
    if(min!=j){
      z=y[j];
      y[j]=y[min];
      y[min]=z;
    }
  }

  for(i=0;i<n-1;i++){
    printf("%c%d ",x[i].c,x[i].value);
  }

  printf("%c%d\n",x[n-1].c,x[n-1].value);
  printf("Stable\n");

  for(i=0;i<n-1;i++){
    printf("%c%d ",y[i].c,y[i].value);
    if(x[i].c!=y[i].c)flag=2;
  }

  printf("%c%d\n",y[n-1].c,y[n-1].value);

  if(flag==2)printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}

