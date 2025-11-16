#include<stdio.h>

typedef struct {
  char mark[5];
  int  num;
}card;

int bubble(int kosuu, card trump[])
{
 int i, j, box1 ;
 char box2; 
  
 
 for(i = 1;i <= kosuu;i++) {
   for(j = kosuu;j > i;j--) {
     if (trump[j].num < trump[j-1].num) {
       box1  = trump[j-1].num;
       box2  = trump[j-1].mark[0];      
       trump[j-1].num     = trump[j].num;
       trump[j-1].mark[0] = trump[j].mark[0];
       trump[j].num     = box1;
       trump[j].mark[0] = box2;
     }
   }
 }
 
 for(i = 1;i < kosuu;i++){
   printf("%c%d ", trump[i].mark[0], trump[i].num);
 }
 printf("%c%d\n", trump[i].mark[0], trump[i].num);
 printf("Stable\n");
 return 0;
}

int select(int kosuu, card trump[])
{
 int i, j,  min, minnum, box1,flag=0;
 char box2;
   
 for(i = 1;i <= kosuu;i++){
   min = trump[i].num;
   for(j = i + 1;j <= kosuu;j++){
     if(trump[j].num < min){
       min = trump[j].num;
       minnum = j;
     }
   }
   if(min < trump[i].num){
      box1  = trump[i].num;
      box2  = trump[i].mark[0];
      trump[i].num     = min;
      trump[i].mark[0] = trump[minnum].mark[0];
      trump[minnum].num     = box1;
      trump[minnum].mark[0] = box2;
      if( (trump[minnum].num == trump[minnum-1].num) || (trump[i].num == trump[i+1].num) ){
        flag++;
      }
   }
 }
 
 for(i = 1;i < kosuu;i++){
   printf("%c%d ", trump[i].mark[0], trump[i].num);
 }
 printf("%c%d\n", trump[i].mark[0], trump[i].num);

 if(flag == 0) 
   printf("Stable\n");
 else
   printf("Not stable\n");
 return 0;
}

int main()
{
 int i, kosuu;
 card trump[40],copy1[40];
   
 scanf("%d", &kosuu);
   
 for(i = 1;i <= kosuu;i++){ 
   scanf("%1s%d",&trump[i].mark,&trump[i].num);
 }
 
 for(i = 1;i <=kosuu; i++){
   copy1[i].mark[0] = trump[i].mark[0];
   copy1[i].num     = trump[i].num;
 }
 bubble(kosuu,trump);
 select(kosuu,copy1);
 
 return 0;
}