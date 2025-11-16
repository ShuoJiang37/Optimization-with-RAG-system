#include<stdio.h>
#define N 36
struct Card{
  char suit;
  char value;
};

main(){
  struct Card R1[N], R2[N],key;
  int i,j,y,f,l=0,mini;
  scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf(" %c%c",&R1[i].suit,&R1[i].value);
  }
  for(i=0;i<y;i++){
    R2[i]=R1[i];
  }

  /*B*/
  for(i=0;i<y;i++){
    for(j=y-1;j>i;j--){
      if(R1[j].value<R1[j-1].value){
	key=R1[j];
	R1[j]=R1[j-1];  
	R1[j-1]=key;
      }
    }
  }
 for(i=0;i<y-1;i++){
   printf("%c%c ",R1[i].suit,R1[i].value);
 }
 printf("%c%c\n",R1[i].suit,R1[i].value);
 printf("Stable\n");

 /*S*/ 
 for(i=0;i<y;i++){
    mini=i;
    f=0;
    for(j=i+1;j<y;j++){
      if(R2[j].value==R2[mini].value) f=1;
      if(R2[j].value<R2[mini].value){
	mini=j;
	if(f==1) l=1;
      }
    }
    if(mini!=i){
    key=R2[i];
    R2[i]=R2[mini];
    R2[mini]=key;
    }
  }
 for(i=0;i<y-1;i++){
   printf("%c%c ",R2[i].suit,R2[i].value);
 }
 printf("%c%c\n",R2[i].suit,R2[i].value);
 if(l==1) printf("Not stable\n"); 
 else
   printf("Stable\n");
  return 0;
}