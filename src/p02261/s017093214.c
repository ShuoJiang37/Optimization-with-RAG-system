#include<stdio.h>

typedef struct{
  char c;
  int value;
}Card;

int main(){
  Card C[36],C1[36],C2[36];
  int n,i,j,minj,flag=0,s=35,t=35;
  Card a;
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf(" %c%d",&C[i].c,&C[i].value);
    C1[i] = C[i];
    C2[i] = C[i];
     }

  /*BubbleSort*/

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(C1[j].value < C1[j-1].value){
	a = C1[j];
	C1[j] = C1[j-1];
	C1[j-1] = a;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%c%d",C1[i].c,C1[i].value);
  }
  printf("\n");

  for(i=0;i<n-1;i++){
    if(C1[i].value == C1[i+1].value){
      for(j=0;j<n;j++){
	if((C[j].c==C1[i].c)&&(C[j].value==C1[i].value)) s = j;
	if((C[j].c==C1[i+1].c)&&(C[j].value==C1[i+1].value)) t = j;
       }
      if(s>t){
	flag = 1;
	break;
      }
    }
  }
  



  
  if(flag == 0) printf("Stable\n");
  else printf("Not stable\n");
 

 for(i=0;i<n;i++){
   minj = i;
   for(j=i;j<n;j++){
     if(C2[j].value<C2[minj].value) minj =j;
   }
   a = C2[i];
   C2[i] = C2[minj];
   C2[minj] = a;
 }
 
 for(i=0;i<n;i++){
   if(i!=0)printf(" ");
   printf("%c%d",C2[i].c,C2[i].value);
 }
 printf("\n");

 flag = 0;
  for(i=0;i<n-1;i++){
    if(C2[i].value == C2[i+1].value){
      for(j=0;j<n;j++){
	if((C[j].c==C2[i].c)&&(C[j].value==C2[i].value)) s = j;
	if((C[j].c==C2[i+1].c)&&(C[j].value==C2[i+1].value)) t = j;
      }
      if(s>t){
	flag = 1;
	break;
      }
    }
  }

  if(flag == 0) printf("Stable\n");
  else printf("Not stable\n");
 

  

  
  return 0;
}
  

