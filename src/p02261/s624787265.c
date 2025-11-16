#include<stdio.h>
#define N 36

typedef struct{
  char a;
  int b;
}tt;

int main(){
  int n,min;
  int i,j;
  tt H[N],x[N],y;

  scanf("%d" , &n);
  for(i = 0; i < n;i++){
    scanf(" %c%d",&H[i].a,&H[i].b);
    x[i] = H[i];
  }
  for(i = 0;i<n;i++){
    for(j = n-1;j>i;j--){
      if(H[j].b <H[j-1].b){
	y = H[j];
	H[j]=H[j-1];
	H[j-1]=y;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%c%d ",H[i].a,H[i].b);
  }
  printf("%c%d\n",H[n-1].a,H[n-1].b);
  printf("Stable\n");

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){

      if(x[j].b<x[min].b)min = j;
    }
    if(i != min){
      y = x[i];
      x[i] = x[min];
      x[min] = y;
    }
  }

  for(i=0;i<n-1;i++){
    printf("%c%d ", x[i].a,x[i].b);
  }
  printf("%c%d\n", x[n-1].a,x[n-1].b);


  for(i=0;i<n;i++){
    if(H[i].a != x[i].a){
      j=0;
      break;
    }
    else if(H[i].a == x[i].a){
      j=1;
    }
  }

  if(j==0)printf("Not stable\n");
  else if(j ==1)printf("Stable\n");
  return 0;
}