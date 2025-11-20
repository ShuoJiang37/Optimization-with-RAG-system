#include <stdio.h>
#include <string.h>

int main(){
  
  char card[36][3], cardA[36][3], cardB[36][3];
  char temp[3];
  int  num, i, j, minj, flag;

  scanf("%d", &num);
  
  for(i = 0; i < num; i++){
    scanf("%s", card[i]);
    strcpy(cardA[i], card[i]);
    strcpy(cardB[i], card[i]);
  }
  
  for(i = 0; i < num; i++){
    for(j = num-1; j > i; j--){
      if( cardA[j][1] < cardA[j-1][1] ){
	strcpy(temp, cardA[j]);
	strcpy(cardA[j], cardA[j-1]);
	strcpy(cardA[j-1], temp);
      }
    }
  }
  for(i = 0; i < num-1; i++){
    printf("%s ", cardA[i]);
  }
  printf("%s", cardA[num-1]);
  printf("\n");

  minj = 0;
  
  for(i = 0; i < num-1; i++){
    if(flag == 1){
      break;
    }

    flag = 0;
    
    if(cardA[i][1] == cardA[i+1][1]){
      
      for(j = minj; j < num; j++){
	if(flag != 2){
	  if(card[j][1] == cardA[i][1]){
	    if(card[j][0] != cardA[i][0]){
	      flag = 1;
	      break;
	    }
	    else{
	      minj = j+1;
	      flag = 2;
	    }
	  }
	}
      }
    }
    else{
      minj = 0;
    }
  }
  
  if(flag == 1){
    printf("Not stable\n");
  }
  else{
    printf("Stable\n");
  }

  minj = 0;  
  for(i = 0; i < num - 1; i++){
    minj = i;
    
    for(j = i+1; j < num; j++){
      
      if(cardB[j][1] < cardB[minj][1]){
	minj = j;
      }
      
    }
    if(i != minj){
      strcpy(temp, cardB[i]);
      strcpy(cardB[i], cardB[minj]);
      strcpy(cardB[minj], temp);
    }
  }
  
  for(i = 0; i < num-1; i++){
    printf("%s ", cardB[i]);
  }
  printf("%s", cardB[num-1]);
  printf("\n");

  minj = 0;
  flag = 0;
  
  for(i = 0; i < num-1; i++){
    if(flag == 1){
      break;
    }

    flag = 0;

    if(cardB[i][1] == cardB[i+1][1]){
      for(j = minj; j < num; j++){
	if(flag != 2){
	  if(card[j][1] == cardB[i][1]){
	    if(card[j][0] != cardB[i][0]){
	      flag = 1;
	      break;
	    }
	    else{
	      minj = j+1;
	      flag = 2;
	    }
	  }
	}
      }
    }
    else{
      minj = 0;
    }
  }

  if(flag == 1){
    printf("Not stable\n");
  }
  else{
    printf("Stable\n");
  }
  
  return 0;
}

