#include<stdio.h>
typedef struct{
  char c;
  int value;
}Trump;

int isStable(Trump in[],Trump out[],int n){
  int i,j,a,f,p,flag=0;
  for(i=0;i<n;i++){
    if(in[i].value==out[i].value && in[i].c==out[i].c)continue;
    f=0;
    for(j=0;j<n;j++){
      if(in[i].value==out[j].value){
        f=1;
        p=0;
        for(a=i-1;a>=0;a--)
          if(in[a].c==out[j].c)p=1;
        if(in[i].c!=out[j].c && p==0){
          flag=1;
        }
      }
      if(f==1)break;
    }
    if(flag==1)return 0;
  }
  return 1;
}

int main(){
  int i,j,minj,n,flag=0,f,p,a;
  char m;
  Trump C[36],D[36],E[36],t;
  scanf("%d%c",&n,&m);
  for(i=0;i<n;i++){
    scanf("%c%d%c",&C[i].c,&C[i].value,&m);
    E[i]=D[i]=C[i];
  }

  
  for(i=0;i<n;i++)
    for(j=n-1;j>i;j--)
      if(C[j].value<C[j-1].value){
        t=C[j-1];
        C[j-1]=C[j];
        C[j]=t;
      }

  for(i=0;i<n-1;i++)printf("%c%d ",C[i].c,C[i].value);
  printf("%c%d\n",C[i].c,C[i].value);
  
  
  if(isStable(E,C,n))printf("Stable\n");
  else printf("Not stable\n");
  


  int d;
  flag=0;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i+1;j<n;j++)
      if(D[j].value<D[minj].value){
        minj=j;
      }
    t=D[minj];
    D[minj]=D[i];
    D[i]=t;
  }
  for(i=0;i<n-1;i++)printf("%c%d ",D[i].c,D[i].value);
  printf("%c%d\n",D[i].c,D[i].value);
  

  if(isStable(E,D,n))printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}


