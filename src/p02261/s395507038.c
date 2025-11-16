#include<stdio.h>
#define N 36
struct Card{
  char suit;
  char value;
};

main(){
  struct Card p1[N], p2[N],key;
  int i,j,y,f,l=0,mini;
  scanf("%d",&y);
  for(i = 0 ; i < y ; i++){
    scanf(" %c%c",&p1[i].suit,&p1[i].value);
  }
  for(i = 0 ; i < y ; i++){
    p2[i] = p1[i];
  }

  /*B*/
  for(i = 0 ; i < y ; i++){
    for(j = y-1 ; j > i ; j--){
      if(p1[j].value<p1[j-1].value){
	key=p1[j];
	p1[j]=p1[j-1];  
	p1[j-1]=key;
      }
    }
  }
 for(i = 0 ; i < y-1 ; i++){
   printf("%c%c ",p1[i].suit,p1[i].value);
 }
 printf("%c%c\n",p1[i].suit,p1[i].value);
 printf("Stable\n");

 /*S*/ 
 for(i = 0 ; i < y ; i++){
    mini = i;
    f = 0;
    for(j = i+1 ; j < y ; j++){
      if(p2[j].value==p2[mini].value) f=1;
      if(p2[j].value<p2[mini].value){
	mini = j;
	if(f == 1) l=1;
      }
    }
    if(mini!=i){
    key=p2[i];
    p2[i]=p2[mini];
    p2[mini]=key;
    }
  }
 for(i =0  ;i < y-1 ; i++){
   printf("%c%c ",p2[i].suit,p2[i].value);
 }
 printf("%c%c\n",p2[i].suit,p2[i].value);
 if(l == 1) printf("Not stable\n"); 
 else
   printf("Stable\n");
  return 0;
}