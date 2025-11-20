#include<stdio.h>
void insert(int [],int,int);
void shell(int [],int);
int cnt;
#define max 1000000
int main(){
  int number;
  int i;
  int list[max];
  scanf("%d",&number);
  for(i=0;i<number;i++){
    scanf("%d",&list[i]);
  }
  shell(list,number);
  printf("%d\n",cnt);
  for(i=0;i<number;i++){
    printf("%d\n",list[i]);
  }
  return 0;
}
void insert(int l[],int n,int g){
  int i;
  int j;
  int v;
  for(i=g;i<n;i++){
    v=l[i];
    j=i-g;
    while(j>=0&&l[j]>v){
      l[j+g]=l[j];
      j=j-g;
      cnt++;
    }
    l[j+g]=v;
  }
}
void shell(int l[],int n){
  int i;
  int m=1;
  int G[max];
  int g=1;
  cnt=0;
  G[0]=g;
  while((1+g*3)<n){
    g=1+g*3;
    G[m]=g;
    m++;
  }
  printf("%d\n",m);
  for(i=m-1;i>=0;i--){
    printf("%d",G[i]);
    if(i==0)printf("\n");
    else printf(" ");
  }
  for(i=m-1;i>=0;i--){
    insert(l,n,G[i]);
  }
}

