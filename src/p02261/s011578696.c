#include<stdio.h>
#include<stdlib.h>
#define MAX 36
#define N 36
int main(){
  int n,i,j,k,n1[37],n2[37],minj,tmp;
  char c1[37],c2[37],esc,l;
  int flag=0;
  scanf("%d",&n);
  if(n>N){
    end(1);
  }
  for(i=0;i<n;i++){
    scanf(" %c%d",&c1[i],&n1[i]);
    n2[i]=n1[i];
    c2[i]=c1[i];
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(n1[j]<n1[j-1]){
	tmp=n1[j];
	n1[j]=n1[j-1];
	n1[j-1]=tmp;
	
	esc=c1[j];
	c1[j]=c1[j-1];
	c1[j-1]=esc;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%c%d",c1[i],n1[i]);
    if(i!=n-1){
      printf(" ");
    }
    else printf("\n");
  }
  printf("Stable\n");

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(n2[j]<n2[minj]){
	minj=j;
      }
    }
    tmp=n2[i];
    n2[i]=n2[minj];
    n2[minj]=tmp;
	
    esc=c2[i];
    c2[i]=c2[minj];
    c2[minj]=esc;
  }
   for(i=0;i<n;i++){
    printf("%c%d",c2[i],n2[i]);
    if(i!=n-1){
      printf(" ");
    }
    else printf("\n");
    if(c1[i]!=c2[i] || n1[i]!=n2[i]){
      flag=1;
    }
   }
   if(flag==0){
     printf("Stable\n");
   }
   else if(flag==1){
     printf("Not stable\n");
   }
   return 0;
}

