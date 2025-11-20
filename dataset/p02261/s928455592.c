#include<stdio.h>
#define N 101
struct card{
  char suit;
  char value;
};

int main()
{
  struct card C1[N],C2[N],C;
  int i,j,n,min,flag=0;
  char cha;

  scanf("%d%c",&n,&cha);

  for(i=0;i<n;i++){
    scanf("%c%c%c",&C1[i].suit,&C1[i].value,&cha);
  }
  for(i=0;i<n;i++){
    C2[i]=C1[i];
  }
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(C2[j].value<C2[j-1].value){
	C=C2[j];
	C2[j]=C2[j-1];
	C2[j-1]=C;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%c%c",C2[i].suit,C2[i].value);
  }
  printf("\n");

  printf("Stable\n");

  for(i=0;i<=n-1;i++){
    min=i;
    for(j=i;j<=n-1;j++){
      if(C1[j].value<C1[min].value){
	min=j;
      }
    }
    C=C1[i];
    C1[i]=C1[min];
    C1[min]=C;
  }
  for(i=0;i<n;i++){
    if(i>0)
      printf(" ");
    printf("%c%c",C1[i].suit,C1[i].value);
    
    if(!(C1[i].suit==C2[i].suit&&C1[i].value==C2[i].value)) flag=1;
    
  }
  printf("\n");

  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}