#include<stdio.h>
#include<string.h>
#define N 36

typedef struct{
  char paint;
  int number;
}card;                                                                   ;
 
void Bubblesort(card *);
void Selectionsort(card *);
int isStable(card *,card *);

int a;

int main()
{
  int i;
  card trump[N],trump1[N],trump2[N];
  
  scanf("%d",&a);
  for(i = 0;i < a;i++){
    scanf(" %c%d",&trump[i].paint,&trump[i].number);
    trump1[i] = trump[i];
    trump2[i] = trump[i];
  }
  
  Bubblesort(trump);
  if(isStable(trump2,trump) == 1) printf("Stable\n");
  else printf("Not stable\n");
  
  Selectionsort(trump1);
  if(isStable(trump2,trump1) == 1) printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;
}

void Bubblesort(card *trump)
{
  int i,j;
  card tmp;
  
  for(i = 0;i < a;i++){
    for(j = a-1;j > i;j--){
      if(trump[j].number < trump[j-1].number){
	tmp = trump[j];
	trump[j] = trump[j-1];
	trump[j-1] = tmp;
      }
    }
  }
  for(i = 0;i < a-1;i++){
    printf("%c%d ",trump[i].paint,trump[i].number);
  }
  printf("%c%d\n",trump[a-1].paint,trump[a-1].number);
}

void Selectionsort(card *trump)
{
  int i,j,minj;
  card tmp;
  
  for(i = 0;i < a;i++){
    minj = i;
    for(j = i;j < a;j++){
      if(trump[j].number < trump[minj].number){
	minj = j;
      }
    }
    tmp = trump[i];
    trump[i] = trump[minj];
    trump[minj] = tmp;
  }
  
  for(i = 0;i < a-1;i++){
    printf("%c%d ",trump[i].paint,trump[i].number);
  }
  printf("%c%d\n",trump[a-1].paint,trump[a-1].number);
}

int isStable(card *trump,card *trump1)
{
  int i,j,x,y,num = 1;

  for(i = 0;i < a;i++){
    for(j = i+1;j < a;j++){
      for(x = 0;x < a;x++){
	for(y = x+1;y < a;y++){
	  if(trump[i].number == trump[j].number && trump[i].number == trump1[y].number && trump[j].number == trump1[x].number && trump[i].paint == trump1[y].paint && trump[j].paint == trump1[x].paint){
	    num = 0;
	    break;
	  } 
	}
      }
    }
  }

  return num;
}