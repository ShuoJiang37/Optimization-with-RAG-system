#include <stdio.h>

#define N 36

typedef struct{
  char suit;
  int value;
}Card;

int main(){

  int i,j,n,min,flag=0;
  Card a[N],b[N],a1,a2;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&a[i].suit,&a[i].value);
    b[i].suit=a[i].suit;
    b[i].value=a[i].value;
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j].value<a[j-1].value){
	a1=a[j];
	a2=a[j-1];
	a[j]=a2;
	a[j-1]=a1;
      }
    }
  }

    

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(b[j].value<b[min].value){
	min=j;
      }
    }
    a1=b[i];
    a2=b[min];
    b[i]=a2;
    b[min]=a1;
  }


  for(i=0;i<n-1;i++){
    printf("%c%d ",a[i].suit,a[i].value);
  }
  printf("%c%d\n",a[n-1].suit,a[n-1].value);
  printf("Stable\n");
 
  for(i=0;i<n-1;i++){
    printf("%c%d ",b[i].suit,b[i].value);
  }
  printf("%c%d\n",b[n-1].suit,b[n-1].value);
   
  for(i=0;i<=n-1;i++){
    if(a[i].suit!=b[i].suit){
      flag=1;
    }
  }
 
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}