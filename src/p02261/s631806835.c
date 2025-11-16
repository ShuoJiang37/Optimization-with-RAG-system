#include <stdio.h>


struct card {
  char pattern;
  int number;
};

int main(){
  int N,i,j,min,flg=0;
  struct card card1[36],card2[36],tmp;
  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf(" %c%d",&card1[i].pattern,&card1[i].number);
    //printf("%c %d\n",card[i].pattern,card[i].number);
  }
  for(i=0;i<N;i++){
    card2[i]=card1[i];
  }
  
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(card1[j].number < card1[j-1].number){
	tmp=card1[j];
	card1[j]=card1[j-1];
	card1[j-1]=tmp;
      }
    }
  }
    for(i=0;i<N;i++){
      if(i>0)printf(" ");
      printf("%c%d",card1[i].pattern,card1[i].number);
    }
    printf("\n");

    printf("Stable\n");
    
    for(i=0;i<N;i++){
      min = i;
      for(j=i;j<N;j++){
	if(card2[j].number < card2[min].number) min=j;
      }
      tmp=card2[i];
      card2[i]=card2[min];
      card2[min]=tmp;
    }
    for(i=0;i<N;i++){
      if(i>0)printf(" ");
      printf("%c%d",card2[i].pattern,card2[i].number);
    }
    printf("\n");

    for(i=0;i<N;i++){
      if(card1[i].number != card2[i].number || card1[i].pattern != card2[i].pattern){
	flg=1;
      }
    }
    if(flg==0){
      printf("Stable\n");
    }else{
      printf("Not stable\n");
    }
    return 0;
  }