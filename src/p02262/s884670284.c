#include<stdio.h>
#define M 1000000

void insertionSort(int [], int, int);
void shellSort(int [],int);

int cnt = 0;

main(){
  int i,j,n,a[M];

    scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  shellSort(a, n);
  printf("%d\n",cnt);
  for(i=0;i<n;i++){
    printf("%d\n",a[i]);
  }
  return 0;
}

void insertionSort(int a[], int n, int g){
  
  int i,j,v;
  for(i=g;i<n;i++){
    v=a[i];
    j=i-g;
    while(j>=0 && a[j]>v){
      a[j+g]=a[j];
      j=j-g;
      cnt++;
    }
    a[j+g]=v;
  }
}


void shellSort(int a[],int n){
  
  int i,m = 0;
  
  int G[n];

  G[0]=0;
  for(i=0;i<n;i++){
    G[i+1]=3*G[i]+1;
    m++;
    if(G[i+1]>M){
      break;
    }
  }
  while(G[m] > n){
    m--;
  }
  printf("%d\n",m);
  for(i=m;i>1;i--){
    printf("%d ",G[i]);
  }
  printf("%d\n", G[1]);
  for(i=m;i>=0;i--){
    insertionSort(a, n, G[i]);
  }
}