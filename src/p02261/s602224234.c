#include<stdio.h>
#define N 36
struct Card{
  char length;
  char value;
};

int main(){
  struct Card C1[N], C2[N],key;
  int i,j,y,f,l=0,mini;
  scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf(" %c%c",&C1[i].length,&C1[i].value);
  }
  for(i=0;i<y;i++){
    C2[i]=C1[i];
  }

  /*BubbleSort*/
  for(i=0;i<y;i++){
    for(j=y-1;j>i;j--){
      if(C1[j].value<C1[j-1].value){
	key=C1[j];
	C1[j]=C1[j-1];  
	C1[j-1]=key;
      }
    }
  }
 for(i=0;i<y-1;i++){
   printf("%c%c ",C1[i].length,C1[i].value);
 }
 printf("%c%c\n",C1[i].length,C1[i].value);
 printf("Stable\n");

 /*SelectionSort*/ 
 for(i=0;i<y;i++){
    mini=i;
    f=0;
    for(j=i+1;j<y;j++){
      if(C2[j].value==C2[mini].value) f=1;
      if(C2[j].value<C2[mini].value){
	mini=j;
	if(f==1) l=1;
      }
    }
    if(mini!=i){
    key=C2[i];
    C2[i]=C2[mini];
    C2[mini]=key;
    }
  }
 for(i=0;i<y-1;i++){
   printf("%c%c ",C2[i].length,C2[i].value);
 }
 printf("%c%c\n",C2[i].length,C2[i].value);
 if(l==1) printf("Not stable\n"); 
 else
   printf("Stable\n");
  return 0;
}