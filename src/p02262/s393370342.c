#include<stdio.h>
void insertionSort(int *a,int n,int g);
int count = 0;

int main(){
  int a[1100000],g[110]={};
  int n,m=1;
  int i,j,x;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  x=n;
  while(x/2!=0){
    x/=2;
    m++;
  }
  g[0]=n;
  for(i=1;i<m;i++){
    if(g[i-1]/2!=0)  g[i]=g[i-1]/2;
    else g[i]=1;
  }
  for(i=0;i<m;i++) insertionSort(a,n,g[i]);
  printf("%d\n",m);
  for(i=0;i<m;i++){
    printf("%d",g[i]);
    if(i!=m-1) printf(" ");
    else printf("\n");
  }
  printf("%d\n",count);
  for(i=0;i<n;i++) printf("%d\n",a[i]);
  
    return 0;
}

void insertionSort(int *a,int n,int g){
  int v;
  int i,j;
  
  for(i=g;i<n;i++){
    v=a[i];
    j=i-g;
    while(j>=0 && a[j]>v){
      a[j+g] = a[j];
      j = j-g;
      count++;
    }
    a[j+g] = v;
  }
}

