#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 36

struct cards{
  char Name;
  char Value;
};

void bubble(struct cards p[],int n){
  int i,j;
  struct cards tmp;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i;j--){
      if(p[j].Value<p[j-1].Value){
	tmp=p[j];
	p[j]=p[j-1];
	p[j-1]=tmp;
      }
    }
  }
}

void selection(struct cards p[],int n){
  int i,j,minj;
  struct cards tmp;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(p[j].Value<p[minj].Value) minj=j;
    }
    tmp=p[i];
    p[i]=p[minj];
    p[minj]=tmp;
  }
}

int main(){
  int i,j,n,flag=0,a1[N],a2[N];
  scanf("%d",&n);
  struct cards p1[N],p2[N];
  for(i=0;i<n;i++){
    scanf(" %c%c",&p1[i].Name,&p1[i].Value);
  }
  for(i=0;i<n;i++){
    p2[i]=p1[i];
  }
  
  bubble(p1,n);
  selection(p2,n);
  
  for(i=0;i<n;i++){
    if(i==n-1)printf("%c%c\nStable\n",p1[i].Name,p1[i].Value);
    else printf("%c%c ",p1[i].Name,p1[i].Value);
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%c%c\n",p2[i].Name,p2[i].Value);
    else printf("%c%c ",p2[i].Name,p2[i].Value);
  }
  for(i=0;i<n;i++){
    if(p1[i].Name != p2[i].Name){
      printf("Not stable\n");
      flag=1;
      break;
    }
  }
  if(flag==0)printf("Stable\n");
  return 0;
}

