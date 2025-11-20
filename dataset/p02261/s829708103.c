#include <stdio.h>
#include <string.h> 
typedef struct{
  char type;
  int value;
}card;

void bubble(card *,card *,int );
void select(card *,card *,int );
void hantei(card *,card *,int);
void output(card *,int);

int main(){
  int i,j,n;
  scanf("%d",&n);
  card hai[n];
  card hai1[n];
  for(i=0;i<n;i++){
    scanf(" %c%d",&hai[i].type,&hai[i].value);
    hai1[i]=hai[i];
  }
  
  bubble(hai,hai,n);
  select(hai,hai1,n);

  return 0;
}




void bubble(card *haiin,card *hai,int n){
  int i,j,hozon;
  char hoz;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(hai[j].value<hai[j-1].value){
	hozon=hai[j-1].value;
	hoz=hai[j-1].type;
	hai[j-1].value=hai[j].value;
	hai[j-1].type=hai[j].type;
	hai[j].value=hozon;
	hai[j].type=hoz;
      }
    }
  }
  output(hai,n);
  printf("Stable\n");
}

void select(card *haiin,card *hai,int n){
  int i,j,hozon,min;
  char hoz;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(hai[j].value<hai[min].value){
	min=j;
      }
    }
    hozon=hai[i].value;
    hoz=hai[i].type;
    hai[i].value=hai[min].value;
    hai[i].type=hai[min].type;
    hai[min].value=hozon;
    hai[min].type=hoz;
  }
  output(hai,n);
  hantei(haiin,hai,n);
}

void hantei(card *haiin,card *haiout,int n){
  int i,j,a,b,flag=0;
  for(i=0;i<n;i++){
    if(haiin[i].type==haiout[i].type && haiin[i].type==haiout[i].type){
      flag=1;
    }else{
      flag=0;
      break;
    }
  }
  if (flag==0) printf("Not stable\n");
  else printf("Stable\n");
}

void output(card *hai,int n){
  int i,j;
  for(i=0;i<n;i++){
    printf("%c%d",hai[i].type,hai[i].value);
    if(i==n-1) printf("\n");
    else printf(" ");
  }
}
  