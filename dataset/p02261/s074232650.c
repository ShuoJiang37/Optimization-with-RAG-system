
 
 
#include<stdio.h>
#include<stdlib.h>
 
typedef struct{
  char m;
  int v;
} c;
 
#define MAX 36
 
int N;
int isStable(c *in, c*out){
  int i;
 
  for(i=0;i<N;i++){
    if(in[i].m!=out[i].m){
      return 0;
    }
  }
 
  return 1;
}
 
int main(){
  int i,j,min,is;
  c c1[MAX],c2[MAX],t;
 
  scanf("%d",&N);
  if(N<1 || N>MAX){
    exit(1);
  }
  for(i=0;i<N;i++){
    scanf(" %c%d",&c1[i].m,&c1[i].v);
  }
 
  for(i=0;i<N;i++){
    c2[i]=c1[i];
  }
 
  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(c1[j].v<c1[j-1].v){
    t=c1[j];
    c1[j]=c1[j-1];
    c1[j-1]=t;
      }
    }
  }
 
  for(i=0;i<N;i++){
    min=i;
    for(j=i;j<N;j++){
      if(c2[j].v<c2[min].v){
    min=j;
      }
    }
    t=c2[i];
    c2[i]=c2[min];
    c2[min]=t;
  }
 
  for(i=0;i<N-1;i++){
    printf("%c%d ",c1[i].m,c1[i].v);
  }
  printf("%c%d\n",c1[N-1].m,c1[N-1].v);
  printf("Stable\n");
 
  is=isStable(c1,c2);
 
  for(i=0;i<N-1;i++){
    printf("%c%d ",c2[i].m,c2[i].v);
  }
  printf("%c%d\n",c2[N-1].m,c2[N-1].v);
  if(is==1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
 
  return 0;
}