#include<stdio.h>
#define N 36


typedef struct{
  int value;
  char wd;
}card;


int main(){

  int i,j,n,minj,c=0,a,b;
  card B[N],C[N],D[N],temp;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c%d",&C[i].wd,&C[i].value);
    D[i]=B[i]=C[i];
  }
  
  for (i = 0 ;i<=n-1;i++){
    for (j = n-1;j>= i+1;j--){
      if (C[j].value < C[j-1].value){
	temp=C[j];
        C[j]=C[j-1];
        C[j-1]=temp;
      }
      
    }
  }

  for(i=0;i<n;i++){
    printf("%c%d",C[i].wd,C[i].value);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  
  for(i=0;i<=n-1;i++){
    for(j=i+1;j<=n-1;j++){
      for(a=0;a<=n-1;a++){
	for(b=a+1;b<=n-1;b++){
	  if(B[i].value==B[j].value && (B[i].value==C[b].value && B[i].wd==C[b].wd) && (B[j].value==C[a].value && B[j].wd== C[a].wd)){
	    printf("Not stable\n");
	    c=1;
	  }
	}
      }
    }
  }
  if(c==0)printf("Stable\n");
 
  for(i = 0;i<=n-1;i++){
    minj = i;
    for (j = i;j<= n-1;j++){
      if(D[j].value < D[minj].value)
	minj = j;
    }
    temp=D[i];
    D[i]=D[minj];
    D[minj]=temp;
  }

  for(i=0;i<n;i++){
    printf("%c%d",D[i].wd,D[i].value);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  
  c=0;
  for(i=0;i<=n-1;i++){
    for(j=i+1;j<=n-1;j++){
      for(a=0;a<=n-1;a++){
	for(b=a+1;b<=n-1;b++){
	  if(c==0 && B[i].value==B[j].value &&( B[i].value==D[b].value &&B[i].wd==D[b].wd )&&( B[j].value==D[a].value && B[j].wd==D[a].wd)){
	    printf("Not stable\n");
	    c=1;
	  }
	}
      }
    }
  }
  if(c==0)printf("Stable\n");
  
  return 0;
}



