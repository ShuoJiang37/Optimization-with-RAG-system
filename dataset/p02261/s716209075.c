#include<stdio.h>
#include<stdlib.h>

void swap(char *x,char *y){
  char temp;
  temp=*x;
  *x=*y;
  *y=temp;
  }

int main(void){
  int i,j,mini,N;
  char C[36][3];
  char D[36][3];
  char E[36][3];
  char key[2];
  char p,q,r,s;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%s",C[i]);
    D[i][0]=C[i][0];
    D[i][1]=C[i][1];
  }

  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if((int)C[j][1]<(int)C[j-1][1]){
	key[0]=C[j][0];
	key[1]=C[j][1];
	C[j][0]=C[j-1][0];
	C[j][1]=C[j-1][1];
	C[j-1][0]=key[0];
	C[j-1][1]=key[1];
      }
    }
  }

  for(i=0;i<N;i++){
    if(i!=0)printf(" ");
    printf("%c%c",C[i][0],C[i][1]);
    E[i][0]=C[i][0];
    E[i][1]=C[i][1];
  }
  printf("\n");

  for(i=0;i<N;i++){
    if(C[i][0]!=E[i][0])break;
  }
  if(i==N)printf("Stable\n");
  else printf("Not stable\n");


  
  for(i=0;i<N;i++){
    mini=i;
    for(j=i;j<N;j++){
      if(D[j][1]<D[mini][1]){
	mini=j;
      }
    }
    p=D[i][0];
    q=D[i][1];
    r=D[mini][0];
    s=D[mini][1];
    swap(&p,&r);
    swap(&q,&s);
    D[i][0]=p;
    D[i][1]=q;
    D[mini][0]=r;
    D[mini][1]=s;
  }

  for(i=0;i<N;i++){
    if(i!=0)printf(" ");
    printf("%c%c",D[i][0],D[i][1]);
  }
  printf("\n");

  for(i=0;i<N;i++){
    if(D[i][0]!=E[i][0])break;
  }
  if(i==N)printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;
}