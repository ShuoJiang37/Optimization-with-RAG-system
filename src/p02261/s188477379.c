#include<stdio.h>

typedef struct {
  char c;
  int n;
}Card;


int number;
Card card1[36],card2[36];

void bubble(Card card[]){
  int j=0;
  int i;

  
  int flag=1,kae,count=0;
  char kae2;
    while (flag==1){
    flag=0;
    for(j=number-1;j>0;j--){
      
      if(card[j].n<card[j-1].n){
	kae=card[j-1].n;
	kae2=card[j-1].c;
	card[j-1].n=card[j].n;
	card[j-1].c=card[j].c;
	card[j].n=kae;
	card[j].c=kae2;
	
	count++;
	flag=1;
      }
    }
    }
    

    for(i=0;i<number;i++){
      if(i!=number-1){
      printf("%c%d ",card[i].c,card[i].n);
      }

      else{printf("%c%d",card[i].c,card[i].n);}
    }
    printf("\nStable\n");
}



void selection(Card card[]){
int i,j,kae,minj;
 char kae2;

 
    for(i=0;i<number;i++){
      minj=i;
      
      for(j=i;j<number;j++){
	if(card[j].n<card[minj].n){minj=j;}}


      kae=card[i].n;
      kae2=card[i].c;
      
      card[i].n=card[minj].n;
      card[i].c=card[minj].c;

      card[minj].n=kae;
      card[minj].c=kae2;
      
       
	
      }
     
    

  
  
  for(j=0;j<number;j++){

    if(j==number-1) printf("%c%d",card[j].c,card[j].n);
    else if (j!=number){printf("%c%d ",card[j].c,card[j].n);}

  }
  printf("\n");
  
  



}


int stablekakunin(Card a[],Card b[]){

  int i;
  for(i=0;i<number;i++){
    if(a[i].c !=b[i].c)return 0;
  }
  return 1;}


int main(){
  
  int i;
  char str;
  int n;

  scanf("%d",&number);



  for(i=0;i<number;i++){
    scanf(" %c%d",&card1[i].c,&card1[i].n);
    card2[i].c=card1[i].c;
    card2[i].n=card1[i].n;
    //printf("%c%d\n",card[i].c,card[i].n);
    
  }
 
  
  
  bubble(card1);
  selection(card2);
  
  if(stablekakunin(card1,card2)==1){
    printf("Stable\n");
  }
  else {printf("Not stable\n");}
  
   return 0;
}

