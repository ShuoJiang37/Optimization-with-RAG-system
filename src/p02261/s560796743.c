#include <stdio.h>
#define N 36
struct A{
  char key;
  char key2;
};
int main() {
  int i,j,n,min,flag=1;
  char c;
  struct A C1[N],C2[N],temp;
  scanf("%d%c",&n,&c);
  for(i=0;i<n;i++)scanf("%c%c%c",&C1[i].key2,&C1[i].key,&c);
  for(i=0;i<n;i++)C2[i]=C1[i];
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(C2[j].key < C2[j-1].key){
	temp=C2[j];
	C2[j]=C2[j-1];
	C2[j-1]=temp;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%c%c",C2[i].key2,C2[i].key);
  }
  printf("\nStable\n");
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(C1[j].key<C1[min].key)min=j;
    }
    temp=C1[i];
    C1[i]=C1[min];
    C1[min]=temp;
  }
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%c%c",C1[i].key2,C1[i].key);
    if(C1[i].key2!=C2[i].key2 || C1[i].key != C2[i].key)flag=0;
  }
  printf("\n");
  if(flag==0)printf("Not stable\n");
  else printf("Stable\n");
  return 0;
}

