#include<stdio.h>
typedef struct{
  int value;
  char symbol;
}trump;


int main(){
  int N,i,j,min,judge=0;
  trump before[36],sorted[36],temp;
  char s[2];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%s",s);
    before[i].symbol=s[0];
    before[i].value=s[1]-'0';
  }
  for(i=0;i<N;i++){
    sorted[i]=before[i];
  }  

  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(before[j].value<before[j-1].value){
	temp=before[j];
	before[j]=before[j-1];
	before[j-1]=temp;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%c%d ",before[i].symbol,before[i].value);
  }
  printf("%c%d\n",before[i].symbol,before[i].value);
  printf("Stable\n");
  
  for(i=0;i<N;i++){
    min=i;
    for(j=i;j<N;j++){
      if(sorted[j].value<sorted[min].value){
	min=j;
     }
    }
    temp=sorted[i];
    sorted[i]=sorted[min];
    sorted[min]=temp;
  }
  
  for(i=0;i<N-1;i++){
    printf("%c%d ",sorted[i].symbol,sorted[i].value);
  }
  printf("%c%d\n",sorted[i].symbol,sorted[i].value);
  for(i=0;i<N;i++){
    if(before[i].symbol!=sorted[i].symbol){
      judge=1;
      break;
    }
    if(before[i].value!=sorted[i].value){
      judge=1;
      break;
    }
  }
  if(judge==0)printf("Stable\n");
    else printf("Not stable\n");

  return 0;
}
    
  
  

