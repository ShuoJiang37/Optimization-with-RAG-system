#include<stdio.h>
#define N 36
 
typedef struct{
  char a;
  int b;
}trump;
 
int main(){
 
  int n,minnn,i,j;
  trump Hira[N],d[N],s;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&Hira[i].a,&Hira[i].b);
    d[i]=Hira[i];
  }
 
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(Hira[j].b<Hira[j-1].b){
	s=Hira[j];
	Hira[j]=Hira[j-1];
	Hira[j-1]=s;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%c%d ",Hira[i].a,Hira[i].b);
  }
  printf("%c%d\n",Hira[n-1].a,Hira[n-1].b);
  printf("Stable\n");
 
  for(i=0;i<n;i++){
    minnn=i;
    for(j=i;j<n;j++){
      if(d[j].b<d[minnn].b){ 
	minnn=j;
      }    
    }
    if(i!=minnn){
      s=d[i];
      d[i]=d[minnn];
      d[minnn]=s;
    }
  }
 
  for(i=0;i<n-1;i++){
    printf("%c%d ",d[i].a,d[i].b);
  }
  printf("%c%d\n",d[n-1].a,d[n-1].b);
  for(i=0;i<n;i++){
    if(Hira[i].a!=d[i].a){ 
      j=0; break;
    }
    else if(Hira[i].a==d[i].a) j=1;
  }
  if(j==0)  printf("Not stable\n");
  else if(j==1)  printf("Stable\n");
  return 0;
}