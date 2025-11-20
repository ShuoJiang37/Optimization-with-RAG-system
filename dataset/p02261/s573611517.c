#include <stdio.h>

#define N 36

int main(){
  int n,i,j,t,min;
  char ac1[N],ac2[N],tc;
  int a1[N],a2[N];

  //input
  scanf("%d\n",&n);
  for(i=0; i<n; i++){
    scanf("%c%d ",&ac2[i],&a2[i]);
  }

  for(i=0; i<n; i++){
    a1[i]=a2[i];
    ac1[i]=ac2[i];
  }
  
  //bubble
  for(i=0; i<n-1; i++){
    for(j=n-1; j>i; j--){
      if(a1[j]<a1[j-1]){
	 t=a1[j];  a1[j]=a1[j-1];  a1[j-1]=t;
	tc=ac1[j];ac1[j]=ac1[j-1];ac1[j-1]=tc;
      }
    }
  }
  for(i=0; i<n-1; i++){
    printf("%c%d ",ac1[i],a1[i]);
  }
  printf("%c%d\n",ac1[i],a1[i]);
  printf("Stable\n");

  //selection
  for(i=0; i<n-1; i++){
    min=i;
    for(j=i+1; j<n; j++){
      if(a2[j]<a2[min]) min=j;
    }
    if(i!=min){
       t=a2[i];  a2[i]=a2[min];  a2[min]=t;
      tc=ac2[i];ac2[i]=ac2[min];ac2[min]=tc;
    }
  }
  for(i=0; i<n-1; i++){
    printf("%c%d ",ac2[i],a2[i]);
  }
  printf("%c%d\n",ac2[i],a2[i]);
  //check
  t=0;
  for(i=0; i<n; i++){
    if(ac1[i]!=ac2[i]){
      t=1;
      break;
    }
  }
  if(t==0) printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}

