#include<stdio.h>

int l,cnt,gcount;
int ary[1000000];
int n;
int G[100];

void insertsort(int ary[],int n,int g){
  for(int i=g;i<n;i++){
    int v=ary[i];
    int j=i-g;
    while(j>=0 && ary[j]>v){
      ary[j+g]=ary[j];
      j-=g;
      cnt++;
    }
    ary[j+g]=v;
  }
}

void shellsort(int ary[],int n){
  int i,h=1;
  gcount=0;
  while(1){
    if(h>n)break;
    G[gcount]=h;
    h=3*h+1;
    gcount++;
  }
  for(i=gcount-1;i>=0;i--){
    insertsort(ary,n,G[i]);
  }
}

int main(){
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ary[i]);
  }
  cnt=0;

  shellsort(ary,n);

  printf("%d\n",gcount);
  for(i=gcount-1;i>=0;i--){
    printf("%d",G[i]);
    if(i>0)printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  for(i=0;i<n;i++)printf("%d\n",ary[i]);
  return 0;
}

