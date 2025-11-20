#include<stdio.h>
#define N 36
struct card{
  char mark;
  int number;
};

void trace(struct card A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%c%d", A[i].mark,A[i].number);
  }
  printf("\n");
}

void bubble(struct card[],int);
void selection(struct card[],int);

int main(){

  struct card trump[N],tmp[N];
  int length,i,flag=0;
  char ch;


  scanf("%d%c", &length,&ch);
  for ( i = 0; i < length; i++ ){
    scanf("%c%d%c", &trump[i].mark, &trump[i].number,&ch);
    tmp[i] = trump[i];
  }

  bubble(trump,length);
  printf("Stable\n");
  selection(tmp,length);

  for(i = 0;i < length;i++){

    if(trump[i].mark != tmp[i].mark){
      
      printf("Not stable\n");
      flag = 1;
      break;
      
    }
  }
  if(flag ==0) printf("Stable\n");
  return 0;
}


void bubble(struct card trump[],int length){
  int n[N],i,j;
  struct card tmp;
  
  
  for(i = 0;i < length;i++){
    for(j = length - 1;j > i;j--){
      
      if(trump[j].number < trump[j - 1].number){
	tmp = trump[j];
	trump[j] = trump[j-1];
	trump[j-1] = tmp;
      }

    } 
  } 

  trace(trump,length);


}


void selection(struct card trump[],int length){

  int i,j,mini,flag;
  struct card tmp;

  
  for(i = 0;i <  length;i++){
    flag = 0;
    mini = i;
    for(j = i;j < length;j++){
      
      if(trump[j].number < trump[mini].number){
	mini = j;
	flag = 1;	
      }
    }
    if(flag == 1){
  	tmp = trump[i];
	trump[i] = trump[mini];
	trump[mini] = tmp;
    }
  }
  
  trace(trump,length);


  
}