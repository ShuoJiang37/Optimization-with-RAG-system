#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubble_sort(char **,int);
void select_sort(char **,char **,int);


int main(){

  int i=0,j,element;
  char **matrix_bubble,**matrix_select;

  scanf("%d",&element);

  matrix_bubble = malloc(sizeof(char*) * element);
  matrix_select = malloc(sizeof(char*) * element);

  for(i = 0 ; i < element ; i++){
  matrix_bubble[i] = malloc(sizeof(char) * 3);
  matrix_select[i] = malloc(sizeof(char) * 3);
  }//Dual_pointer

  i =0;

  while(i < element){
    scanf("%s",matrix_bubble[i]);
    strcpy(matrix_select[i],matrix_bubble[i]);
    i++;
  }
  
  bubble_sort(matrix_bubble,element);
  select_sort(matrix_select,matrix_bubble,element);
  
  free(matrix_bubble);
  free(matrix_select);
  return 0;


}




void bubble_sort(char **matrix_b,int element){

  int i=0,j,str=3;//str = string
  char temp[3];
  int nowline=0;

  while( nowline != element){
    for(i = element-1 ; i > 0 ; i--){

      if(matrix_b[i][1] < matrix_b[i-1][1]){   //string comper
	  strcpy(temp,matrix_b[i-1]);
	  strcpy(matrix_b[i-1],matrix_b[i]);
	  strcpy(matrix_b[i],temp);
      }
      /*    else if(matrix_b[i][1] == matrix_b[i-1][1] && i < matrix_b[i-1][0]){
	strcpy(temp,matrix_b[i-1]);
	strcpy(matrix_b[i-1],matrix_b[i]);
	strcpy(matrix_b[i],temp);
	
	}*/
    }
    nowline++;
  }

  i = 0;

  while(i < element){
    printf("%s",matrix_b[i]);
    if(i != element-1){
      printf(" ");

    }

    i++;

  }
    printf("\n");

  printf("Stable\n");
}



void select_sort(char **matrix_c,char **matrix_b,int element){
  int i=0;//temp = temporary
  int nowline=0,exchangeline=0,flag=0;
  char min[3],temp[3];

while(nowline != element){ //element = endline

    for( i = nowline ; i < element-1 ; i++){
      
      if( i == nowline ) strcpy(min, matrix_c[i]);//startline

      if( min[1] > matrix_c[i+1][1]){
	strcpy(min,matrix_c[i+1]);
	exchangeline = i+1;
      }
      /*      else if( min[1] == matrix_c[i+1][1]&& min[0] > matrix_c[i+1][0]){
	strcpy(min,matrix_c[i+1]);
	exchangeline = i+1;
	}*/
    }
      if(exchangeline != nowline){
      strcpy(temp,matrix_c[nowline]);
      strcpy(matrix_c[nowline],matrix_c[exchangeline]);
      strcpy(matrix_c[exchangeline],temp);
    }
    nowline++;
    exchangeline = nowline; //ここでどちらにしろexchangelineは頭に戻る
 }
 i = 0;

  while( i < element){
    printf("%s",matrix_c[i]);
    if(strcmp(matrix_b[i],matrix_c[i]) != 0) flag = 1;
    if(i != element-1) printf(" ");
    i++;
}
  printf("\n");

  if(flag == 0) printf("Stable\n");
  else printf("Not stable\n");


}