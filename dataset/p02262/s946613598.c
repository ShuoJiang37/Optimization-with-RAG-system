#include <stdio.h>

void insertionsort(int*,int,int);
void shellsort(int*,int);

long cnt = 0;

int main(){

  int n,i,j;
  int a[1000024] = {};

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }

  shellsort(a,n);

  for(i = 0;i < n;i++){
    printf("%d\n",a[i]);
  }
  return 0;
}
void insertionsort(int *a,int n,int g){

  int i,v,j;
  for(i = g;i < n;i++){
    v = a[i];
    j = i - g;
    while(j >= 0 && a[j] > v){
      a[j + g] = a[j];
      j = j - g;
      cnt++;
    }
    a[j + g] = v;
  }
}

void shellsort(int *a,int n){
  int i,m,c = 0;
  long g[32] = {1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484};

  for(i = 0;i < 14;i++){
    if(g[i] > n){
      m = c;
      break;
    }
      c++;
  }

  for(i = m - 1;i >= 0;i--){
    insertionsort(a,n,g[i]);
  }

  printf("%d\n",m);
  for(i = m - 1;i >= 0;i--){  
    if(i != 0) printf("%ld ",g[i]);
    else  printf("%ld\n",g[i]);
  }
  printf("%ld\n",cnt);
}