#include <stdio.h>
#define N 1000000



void insert(int *,int ,int );

int cnt;

int main(){
  int i,j,n,a[N],m=0,g[N];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  //shellsort
  cnt=0;
  g[0]=1;
  m++;
  for(i=1;n>=(3*g[i-1]+1);i++){
    g[i]=3*g[i-1]+1;
    m++;
  }
  for(i=0;i<m/2;i++){
    j=g[i];
    g[i]=g[m-i-1];
    g[m-i-1]=j;
  }
  //出力
  for(i=0;i<m;i++)
    insert(a,n,g[i]);

  printf("%d\n",m);
  for(i=0;i<m;i++){
    printf("%d",g[i]);
    if(i<m-1)printf(" ");
  }
  printf("\n%d\n",cnt);
  for(i=0;i<n;i++){
    printf("%d\n",a[i]);
  
  }

  return 0;
}

void insert(int a[],int n,int g){
  int i,j,v;
  for(i=g;i<n;i++){
    v=a[i];
    j=i-g;
    while(j>=0&&a[j]>v){
      a[j+g]=a[j];
      j=j-g;
      cnt++;
    }
    a[j+g]=v;
  }
}

