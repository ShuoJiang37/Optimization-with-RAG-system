#include<stdio.h>
#define N 36

typedef struct{
  char form;
  int num;
}inf;

int main(){
  inf x[N],y[N],z[N],tmp;
  int i,j,n,flag=1,minj,a,b,f=1;
  char c;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&x[i].form,&x[i].num);
    z[i]=y[i]=x[i];

  }



  while(flag==1){
    flag=0;

    for(i=n-1;i>0;i--){
      if(x[i].num<x[i-1].num){
        tmp=x[i];
        x[i]=x[i-1];
        x[i-1]=tmp;
        flag=1;
      }
    }
  }

 for(i=0;i<n-1;i++) printf("%c%d ",x[i].form,x[i].num);
  printf("%c%d\n",x[i].form,x[i].num);

  for(i=0;i<n-1;i++){
    if(f==0) break;
    for(j=i+1;j<n-1;j++){
      if(f==0) break;
      for(a=0;a<n-1;a++){
        if(f==0) break;
        for(b=a+1;b<n-1;b++){
          if(z[i].num==z[j].num&&z[i].form==x[b].form&&z[j].form==x[a].form&&z[i].num==x[b].num&&z[j].num==x[a].num){
            printf("Not stable\n");
            f=0;
            break;
          }
        }
      }
    }
  }
  if(f==1) printf("Stable\n");

   for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(y[j].num<y[minj].num) minj=j;
      }
        tmp=y[i];
        y[i]=y[minj];
        y[minj]=tmp;
    }

 for(i=0;i<n-1;i++) printf("%c%d ",y[i].form,y[i].num);
  printf("%c%d\n",y[i].form,y[i].num);

  f=1;

  for(i=0;i<n-1;i++){
    if(f==0) break;
    for(j=i+1;j<n-1;j++){
      if(f==0) break;
      for(a=0;a<n-1;a++){
        if(f==0) break;
        for(b=a+1;b<n-1;b++){
          if(z[i].num==z[j].num&&z[i].form==y[b].form&&z[j].form==y[a].form&&z[i].num==y[b].num&&z[j].num==y[a].num){
            printf("Not stable\n"); 
                        f=0;
            break;
          }
        }
      }
    }
  }
  if(f==1) printf("Stable\n");

  return 0;
}
