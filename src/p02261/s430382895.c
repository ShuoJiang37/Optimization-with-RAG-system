#include <stdio.h>
  
#define N 36
  
typedef struct{
  char a;
  int value;
}Card;
  
int main(){
  
  int i,j,n,min,flag=0;
  Card c[N],b[N],n1,n2;
    
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&c[i].a,&c[i].value);
    b[i].a=c[i].a;
    b[i].value=c[i].value;
  }
  
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(c[j].value<c[j-1].value){
 
    n1=c[j];
    n2=c[j-1];
      c[j]=n2;
    c[j-1]=n1;
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
 
 
    n1=b[i];
    n2=b[min];
    b[i]=n2;
    b[min]=n1;
  }
  
  
  for(i=0;i<n-1;i++){
    printf("%c%d ",c[i].a,c[i].value);
  }
  printf("%c%d\n",c[n-1].a,c[n-1].value);
  printf("Stable\n");
   
  for(i=0;i<n-1;i++){
    printf("%c%d ",b[i].a,b[i].value);
  }
  printf("%c%d\n",b[n-1].a,b[n-1].value);
     
  for(i=0;i<=n-1;i++){
    if(c[i].a!=b[i].a){
      flag=1;
    }
  }
   
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");
    
  return 0;
}