#include<stdio.h>
#include<stdlib.h>
struct CARD
{
  char suit;
  int value;
};

int main(){
  int n,i,j,minj,flag=0,t;
  struct CARD c[36],c2[36],cr,vr;
  char k;
  

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf(" %c%c",&c[i].suit,&k);
    c[i].value=atoi(&k);
  }

  for(i=0; i<n; i++){
  c2[i]=c[i];
  }
  
//BubbleSort
  for(i=0; i<=n-1; i++){
    for(j=n-1; j>=i+1; j--){
      if(c[j].value<c[j-1].value){
	vr=c[j];
	c[j]=c[j-1];
	c[j-1]=vr;
      }
    }
  }

  for(i=0; i<n; i++){
    if(i)printf(" ");
    printf("%c%d",c[i].suit,c[i].value);
  }
  printf("\nStable\n");    
  
//SelectonSort
  for(i=0; i<=n; i++){
    minj=i;
    for(j=i; j<n; j++){
      if(c2[j].value<c2[minj].value){
	minj=j;
      }
    }
    cr=c2[i];
    c2[i]=c2[minj];
    c2[minj]=cr;

    /*
    for(t=0; t<n; t++){
    if(t)printf(" ");
    printf("%c%d",c2[t].suit,c2[t].value);
    }
    printf("\n");
    */
    
  }

  for(i=0; i<n; i++){
    if(i)printf(" ");
    printf("%c%d",c2[i].suit,c2[i].value);
  }
  printf("\n");

  for(i=0; i<n; i++){
    if(c[i].suit!=c2[i].suit || c[i].value!=c2[i].value){
      printf("Not stable\n");
      flag=1;
      break;
    }
  }
  if(flag==0){
    printf("Stable\n");
  }
  

  return 0;
}

