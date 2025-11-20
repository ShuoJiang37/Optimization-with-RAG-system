#include<stdio.h>

#define N 100


struct Card{
  char word;
  char num;
};

int judge(struct Card *,struct Card *,int );



int main(){

  struct Card C1[N], C2[N];
  struct Card tmp;
  int i, j;
  int minj;
  int n;
  



  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) {
    scanf(" %c %c", &C1[i].word,&C1[i].num);
  }  


  for(i=0;i<n;i++){
    C2[i]=C1[i];
  }


  
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(C1[j].num < C1[j-1].num){
	tmp=C1[j];
	C1[j]=C1[j-1];
	C1[j-1]=tmp;
      }
    }
  }//bubble sort

   for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(C2[j].num < C2[minj].num){
	minj=j;
      }
    }
      tmp=C2[i];
      C2[i]=C2[minj];
      C2[minj]=tmp;
   }//selection sort


   for ( i = 0; i < n; i++ ){
     if ( i >= 1 ) printf(" ");
     printf("%c%c", C1[i].word,C1[i].num);
   }
   printf("\n");
   
   printf("Stable\n");



   
   for ( i = 0; i < n; i++ ){
     if ( i >= 1 ) printf(" ");
     printf("%c%c", C2[i].word,C2[i].num);
   }
   printf("\n");

   if ( judge(C1, C2, n) == 1 ){
     printf("Stable\n");
   }
   else {
     printf("Not stable\n");
   }
   return 0;   

}
int judge(struct Card C1[] ,struct Card C2[],int n){

  int i;
  
  for(i=0;i<n;i++){
    if(C1[i].word != C2[i].word){
      return 0;
    }
  }
    return 1;
}