#include <stdio.h>
#include <stdlib.h>

 typedef struct{
    char c;
    int value;
  }Card;

void BubbleSort(Card *,int);
void SelectionSort(Card *,int);
void swap(int *,int *);
void swapc(char *,char *);
int isStable(Card[], Card[],int);

int main(){

  int i,j,n,flag=1;
  
scanf("%d",&n);

 Card *card,*card2,*card3;
 
 card = malloc(sizeof(Card)*n);
 card2 = malloc(sizeof(Card)*n);
 card3 = malloc(sizeof(Card)*n);
 
 for(i=0;i<n;i++){

   scanf(" %c",&card[i].c);
   scanf("%d",&card[i].value);
   card2[i].value=card[i].value;
   card2[i].c=card[i].c;
   card3[i].value=card[i].value;
   card3[i].c=card[i].c;

   //printf("%c%d\n",card[i].c,card[i].value);
 }

 
 
 BubbleSort(card,n);
  
 // for(i=0;i<n-1;i++)printf("%c%d ",card2[i].c,card2[i].value);
 // printf("%c%d\n",card2[i].c,card2[i].value);

 if(isStable(card3,card,n)==1)printf("Stable\n");
 else printf("Not stable\n");
 
 SelectionSort(card2,n);
 
 // for(i=0;i<n-1;i++)printf("%c%d ",card[i].c,card[i].value);
 //printf("%c%d\n",card[i].c,card[i].value);
if(isStable(card3,card2,n)==1)printf("Stable\n");
 else printf("Not stable\n");
 
 free(card);
 free(card2);
 free(card3);
 return 0;
}

void swap(int *a,int *b){

  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;

}


void BubbleSort(Card c[],int n){

  int i,k,flag=1;
  
while(flag==1){
    flag=0;

    for(i=n-1;i>0;i--){

      if(c[i].value < c[i-1].value){
	swap(&c[i].value,&c[i-1].value);
	swapc(&c[i].c,&c[i-1].c);
	flag = 1;
      }
      
     
    }

 }
   for(k=0;k<n-1;k++)printf("%c%d ",c[k].c,c[k].value);
      printf("%c%d\n",c[k].c,c[k].value);

      
}


void SelectionSort(Card c[],int n){

  int i,j,k,min;
  
for(i=0;i<n;i++){
    min = i;
    for(j=i;j<n;j++)if(c[j].value < c[min].value)min = j;

    if(c[i].value!=c[min].value){
      swap(&c[i].value,&c[min].value);
      swapc(&c[i].c,&c[min].c);
    }
    
  }
for(k=0;k<n-1;k++)printf("%c%d ",c[k].c,c[k].value);
    printf("%c%d\n",c[k].c,c[k].value);
      
}

void swapc(char *a,char *b){

  char tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;

}

int isStable(Card in[], Card out[],int n){

  int i,j,a,b;

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if(in[i].value==in[j].value && in[i].c==out[b].c && in[i].value==out[b].value && in[j].value==out[a].value && in[j].c==out[a].c)return -1;
	}

      }

    }

  }
  return 1;
}

