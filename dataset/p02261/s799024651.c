#include <stdio.h>
#include <stdlib.h>
#define N 36

char t[N][2];
int n ,i ,j ,m ,l ,min ,num[N] ,o[N] ,o2[N];

int main(){

  scanf("%d" ,&n);
  

  for(i=0;i<n;i++){
    scanf(" %s",&t[i][0]);
    o[i]=i;
    o2[i]=i;
    num[i]=atoi(&t[i][1]);

    ;
  }
    
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(num[o[j]]<num[o[j-1]]){
	m=o[j];
	o[j]=o[j-1];
	o[j-1]=m;
      }
    }
  }
  
  for(i=0;i<n;i++){
    if(i==n-1) printf("%c%d" ,t[o[i]][0] ,num[o[i]]);
    else printf("%c%d " ,t[o[i]][0] ,num[o[i]]);
  }
  printf("\nStable\n");

  for(i=0;i<n;i++){
    min=o2[i];
    l=-0;
    for(j=i;j<n;j++){
      if(num[o2[j]]<num[min]) {
	min=o2[j];
	m=j;
	l++;
      }
    }
    if(l!=0){
    o2[m]=o2[i];
    o2[i]=min;
    }
  }
  m=0;

  for(i=0;i<n;i++){
    if(i==n-1) printf("%c%d" ,t[o2[i]][0] ,num[o2[i]]);
    else printf("%c%d " ,t[o2[i]][0] ,num[o2[i]]);
    if(o2[i]!=o[i]) m++;
  }
  if(m==0) printf("\nStable\n");
  else if(m!=0) printf("\nNot stable\n");
  
  return 0;
}

