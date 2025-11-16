#include <stdio.h>

void insertionsort(int [], int,int);
void shellsort(int [], int);

int count = 0;

int main(void){
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  shellsort(a, n);
  return 0;

}

void insertionsort(int temp[],int n, int g){

  for(int i=g; i<n; i++){
    int v = temp[i];
    int j = i - g;
    while((j>=0)&&(temp[j]>v)){
      temp[j+g]=temp[j];
      j=j-g;
      count++;

    }
    temp[j+g]=v;
  }


}

void shellsort(int temp[], int n){

  int cnt = 0;

  int m = n/2;
  int x = n/2;
  if(n==1){
    m = 1;
    x = 1;
  }

  


  int G[m];

  for(int i=0;;i++){
    if(x<1){
      break;
    }
    G[i]=x;

    x/=2;
    cnt++;

  }

  printf("%d\n", cnt);
  for(int i=0; i<cnt; i++){
    printf("%d ", G[i]);
  }
  printf("\n");



  for(int i=0; i<cnt; i++){
    insertionsort(temp,n,G[i]);
  }

  printf("%d\n", count);
  for(int i=0; i<n; i++){
    printf("%d\n",temp[i]);
  }


}

