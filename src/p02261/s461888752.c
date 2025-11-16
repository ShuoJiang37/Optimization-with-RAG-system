#include<stdio.h>

 int main(){
   typedef struct{
     int number;
     char type;
   }TRAMP;
   int datanum,i,j,minj,flag;
   TRAMP card[36];
   TRAMP b_card[36];
   TRAMP temp;
   scanf("%d",&datanum);

   for(i=0;i<datanum;i++){
     scanf(" %c",&card[i].type);
     scanf("%d",&card[i].number);
     b_card[i] =card[i];
   }
   for(i=0;i<datanum;i++)
     for(j=datanum-1;j>=i+1;j--){
       if(card[j].number < card[j-1].number){
	 temp = card[j];
	 card[j] = card[j-1];
	 card[j-1] = temp;
       }
     }
   for(i=0;i<datanum;i++){
     if(i == datanum-1){
       printf("%c%d\n",card[i].type,card[i].number);
       break;
     }
     printf("%c%d ",card[i].type,card[i].number);
   }
   printf("Stable\n");

   for(i=0;i<datanum;i++){
     minj = i;
     flag = 0;
     for(j = i;j<datanum;j++){
       if(b_card[j].number < b_card[minj].number){
	 minj = j;
	 flag = 1;
       }
     }
       if(flag == 1){
	 temp = b_card[i];
	 b_card[i] = b_card[minj];
	 b_card[minj] = temp;
       }
   }
     flag = 0;
     for(i=0;i<datanum;i++){
       if(i == datanum -1) {
	 printf("%c%d\n",b_card[i].type,b_card[i].number);
	 break;
       }
       printf("%c%d ",b_card[i].type,b_card[i].number);
       if(card[i].type != b_card[i].type || card[i].number != card[i].number)flag=1;
     }
     if(flag == 1)printf("Not stable\n");
     else printf("Stable\n");     

     return  0;


 }

