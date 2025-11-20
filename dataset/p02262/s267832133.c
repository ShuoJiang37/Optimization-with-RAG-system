#include <stdio.h>

void insertion(int *,int ,int );
int cnt;

  int main (){
    int i,j,m=0,a[1000000],G[1000000],n;


  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  cnt=0;
  G[0]=1;
  m=m+1;
  for(i=0;n>3*G[i]+1;i++){
    G[i+1]=3*G[i]+1;
    m++;
  }

  for(i=0;i<m;i++){
    insertion (a,n,G[m-i-1]);
  }


  printf("%d\n",m);

  for(i=0;i<m;i++){
    printf("%d",G[m-i-1]);
    if(i<m-1)
      printf(" ");
  }

  printf("\n%d\n",cnt);
  for(i=0;i<n;i++)
    printf("%d\n",a[i]);
}
void insertion(int a[],int n,int g)
{
  int v,j,i;
  for(i=g;n>i;i++){
    v=a[i];
    j = i - g;
    while (j >= 0 && a[j] > v){
      a[j+g]=a[j];
      j =j-g;
      cnt++;
      a[j+g]=v;
    }
  }
  
}

