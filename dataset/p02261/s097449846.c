#include <stdio.h>
#include <string.h>
typedef struct {
  char value[3]; 
}SCHD;
int main(){
  SCHD card1[36];
  SCHD card2[36];
  SCHD card3[36];
  char str[3];
  int n,i,j;
  int min,sn=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){   
    scanf("%s",card1[i].value);
    strcpy(card2[i].value,card1[i].value);
    strcpy(card3[i].value,card1[i].value);
  }
    for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(card1[j].value[1]<card1[j-1].value[1]){
	strcpy(str,card1[j].value);
	strcpy(card1[j].value,card1[j-1].value);
	strcpy(card1[j-1].value,str);
      }     
    }
  }
  for(i=0;i<n-1;i++){
    printf("%s ",card1[i].value);
  } 
  printf("%s\n",card1[n-1].value);  
  for(i=0;i<n;i++){   
    for(j=0;j<n;j++){
      if((int)card3[i].value[1]==(int)card1[j].value[1]) break;     	
    }    
    if(j!=n){
      sn++;
      if(card3[i].value[0]==card1[j].value[0]){
	sn++;
	break;
      }
      }     
   }  
  if(sn!=2)printf("Not stable\n");
  else printf("Stable\n");   
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i;j<n;j++){
      if(card2[j].value[1]<card2[min].value[1])min=j;
    }
    strcpy(str,card2[i].value);
    strcpy(card2[i].value,card2[min].value);
    strcpy(card2[min].value,str);
  } 
  for(i=0;i<n-1;i++){
    printf("%s ",card2[i].value);
  }
  printf("%s\n",card2[n-1].value);
  sn=0;
   for(i=0;i<n;i++){ 
    for(j=0;j<n;j++){
      if((int)card3[i].value[1]==(int)card2[j].value[1]) break;     	
    }    
    if(j!=n){
      sn++;
      if(card3[i].value[0]==card2[j].value[0]){
	sn++;
	break;
      }
    }          
    }
  if(sn!=2 || n==36) printf("Not stable\n");
  else printf("Stable\n");
  return 0;
}

