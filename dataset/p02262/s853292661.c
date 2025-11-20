#include <stdio.h>
#include <math.h>
#define Z 1000000
void insertionsort(int *,int,int);
void shellsort(int *,int);
void swap(int *,int *);

int cnt=0;
int g[Z];
int main(){

  int A[Z],i,j,n;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  shellsort(A,n);
  printf("\n%d\n",cnt);
  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }


  return 0;
}
void insertionsort(int a[],int n,int g){
  int i,v,j;
  
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


void shellsort(int a[],int n){
  int i,j,m=0,c=2;
  cnt=0;
  g[0]=1;    
  for(i=1;g[i-1]<=n;i++){
    g[i]=g[i-1]*3+1;
    m++;
  }
  printf("%d\n",m);
  for(j=0;j<m;j++){
    printf("%d",g[m-1-j]);
    if(j<m)printf(" ");
  }

  for(i=0;i<m;i++)
    insertionsort(a,n,g[m-i-1]);
}


