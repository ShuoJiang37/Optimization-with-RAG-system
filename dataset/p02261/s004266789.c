#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char c;
  int d;
}O;





int n,i,j,a[100],minj,flag=0;
int main () {
  O ok[36],hoke[36],b;
  char z[2];
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%s",z);
    ok[i].c=z[0];
    ok[i].d=atoi(&z[1]);
    hoke[i].c=ok[i].c;
    hoke[i].d=ok[i].d;
    
  }


  //bubble//
  for(i=0;i<n;i++){
  
    for(j=n-1;j>=1+i;j--){
      if(ok[j].d<ok[j-1].d)
	{
	  b=ok[j];
	  ok[j]=ok[j-1];
	  ok[j-1]=b;

	}
    }
  }
 






  //selection//
  for (i=0;i<n;i++){
    minj = i;
    for (j=i;j<n;j++){
      if( hoke[j].d < hoke[minj].d){
	minj = j;
      }
    }
    if(hoke[i].d!=hoke[minj].d){
      b=hoke[i];
      hoke[i]=hoke[minj];
      hoke[minj]=b;
    }
  }
     

 
  for (i=0;i<n;i++){
    printf("%c%d",ok[i].c,ok[i].d);
    if (i<n-1)
      printf(" ");
  }
  printf("\nStable\n");
  for (i=0;i<n;i++){
    printf("%c%d",hoke[i].c,hoke[i].d);
    if (i<n-1)
      printf(" ");
  }
  for (i=0;i<n;i++){
    if(ok[i].c!=hoke[i].c)flag=1;
  }
  if(flag) printf("\nNot stable\n");
  else 
    printf("\nStable\n");
  return 0;
}

