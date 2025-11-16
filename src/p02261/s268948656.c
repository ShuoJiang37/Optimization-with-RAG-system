#include<stdio.h>
 
 struct card{
           char gara;
           char kazu;
           };

 struct card card1[37];
 struct card card2[37];

 void bublle(struct card card1[],int n){
               int i,j;
               struct card t;
               for(i=0;i<n;i++){
                          for(j=n-1;j>i;j--){
                                   if(card1[j-1].kazu>card1[j].kazu){
                                                   t=card1[j-1];
                                                   card1[j-1]=card1[j];
                                                   card1[j]=t;
                                                   }
                                   }
                          }
               
               }

 void select(struct card card2[],int n){
           int i,j,min;
           struct card t;
           for(i=0;i<n;i++){
                     min=i;
                     for(j=i;j<n;j++){
                              if(card2[j].kazu<card2[min].kazu){
                                                        min=j;
                                                        }
                              }
                     if(min!=i){
                              t=card2[min];
                              card2[min]=card2[i];
                              card2[i]=t;
                              }
                    }
            
            }
 
 int main(){
         int i,j,n,x,flag;
         char c,ch;
         scanf("%d%c",&n,&ch);
         for(i=0;i<n;i++){
                    scanf("%c%c%c",&card1[i].gara,&card1[i].kazu,&ch);
                    }
        for(i=0;i<n;i++){card2[i]=card1[i];}

         bublle(card1,n);
         for(i=0;i<n;i++){
                   printf("%c%c%c",card1[i].gara,card1[i].kazu,(i==n-1)?'\n':' ');
                   }
         printf("Stable\n");

         select(card2,n);
         for(i=0;i<n;i++){
                   printf("%c%c%c",card2[i].gara,card2[i].kazu,(i==n-1)?'\n':' ');
                   }
         flag=1;
         for(i=0;i<n;i++){
                  if(card2[i].gara!=card1[i].gara){flag=0;break;}
                  }

         if(flag==1)printf("Stable\n");
         else printf("Not stable\n");

         return 0;
         }






