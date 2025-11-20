#include<stdio.h>
#define N 36

struct kazu {
  int value;
  char mozi;
};

main(){
  int i,j,n,m,minj;
  struct kazu a[N],d[N],b,e;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&a[i].mozi,&a[i].value);
    d[i] = a[i];
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j].value < a[j-1].value){
      b = a[j];
      a[j] = a[j-1];
      a[j-1] = b;
      }
    }
  }
  
  printf("%c%d",a[0].mozi,a[0].value);
  for(i=1;i<n;i++){
    printf(" %c%d",a[i].mozi,a[i].value);
  }
  printf("\n");
  printf("Stable\n");
  
  
  
  
  
  
  
  for(i=0;i<n-1;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(d[j].value < d[minj].value){
	minj = j;
      }
    }
    e = d[i];
    d[i] = d[minj];
    d[minj] = e;
  }

  printf("%c%d",d[0].mozi,d[0].value);  
  for(i=1;i<n;i++){
    printf(" %c%d",d[i].mozi,d[i].value);
  }

  for(i=0;i<n;i++){
    if(a[i].mozi != d[i].mozi){
      m=0;
      break;
    }
    else if(a[i].mozi == d[i].mozi){
      m=1;
    }
  }
  printf("\n");
    if(m==1)printf("Stable\n");
    if(m==0)printf("Not stable\n"); 
    return 0;
}

   