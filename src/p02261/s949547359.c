#include<stdio.h>
#define N 36
 
struct Card{
  char value;
  char suit;
};
 
int main(){
  int i,j,n,min,flag=0;
  char a;
  struct Card C1[N],C2[N],tmp;
   
  scanf("%d%c",&n,&a);
  for(i=0 ; i<n ; i++){
    scanf("%c%c%c",&C1[i].suit,&C1[i].value,&a);
  }
 
  for(i=0 ; i<n ; i++){
    C2[i]=C1[i];
  }
   
  //BubbleSort
   for(i=0 ; i<n ; i++){
    for(j=n-1 ; j>i ; j--){
      if(C2[j].value < C2[j-1].value){
    tmp=C2[j];
    C2[j]=C2[j-1];
    C2[j-1]=tmp;
      }
    }
   }
   for(i=0 ; i<n ; i++){
     if(i>0)printf(" ");
     printf("%c%c",C2[i].suit,C2[i].value);
   }
   printf("\n");
   printf("Stable\n");
    
   //SelectionSort
   for(i=0 ; i<n ; i++){
     min=i;
     for(j=i ; j<n ; j++){
       if(C1[j].value<C1[min].value) min=j;
    }
    tmp=C1[i];
    C1[i]=C1[min];
    C1[min]=tmp;
   }
   for(i=0 ; i<n ; i++){
     if(i>0)printf(" ");
     printf("%c%c",C1[i].suit,C1[i].value);
     if(C1[i].suit!=C2[i].suit || C1[i].value!=C2[i].value) flag=1;
   }
   printf("\n");
 
   if(flag==1)printf("Not stable\n");
   else printf("Stable\n");
 
 
return 0; 
}