#include <stdio.h>
#define N 36

struct trump{
  char c;
  int num;
  int order;
};

void bubble(struct trump *, int);
void select(struct trump *, int);
int judge(int, int);

struct trump card[N],card2[N] ,sub;

int main(){

  int n, i, j, fc=0, rs=1;
  char ct[N][2];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",ct[i]);
    card[i].c=ct[i][0];
    card[i].num=((int)ct[i][1])-48;
    card[i].order=i;
  }

  for(i=0;i<N;i++){
    card2[i]=card[i];
  }

  bubble(card, n);
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(card[i].num==card[j].num){
         rs=judge(card[i].order, card[j].order);
         if(rs==0) fc++;
      }
    }
  }
  
  for(i=0;i<n;i++){
    printf("%c%d",card[i].c, card[i].num);
    if(i<n-1) printf(" ");
  }
  if(fc==0) printf("\nStable\n");
  else printf("\nNot stable\n");
  
  fc=0;

  select(card2, n);
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(card[i].num==card[j].num){
         rs=judge(card2[i].order, card2[j].order);
         if(rs==0) fc++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%c%d",card2[i].c, card2[i].num);
    if(i<n-1) printf(" ");
  }
  if(fc==0) printf("\nStable\n");
  else printf("\nNot stable\n");

  return 0;
}
void bubble(struct trump *C,int n){

  int i, j;

  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(C[j].num<C[j-1].num){
        sub=C[j];
        C[j]=C[j-1];
        C[j-1]=sub;
      }
    }
  }
}

void select(struct trump *C,int n){

 int i, j, minj;

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(C[j].num<C[minj].num)
         minj=j;
    }
    sub=C[i];
    C[i]=C[minj];
    C[minj]=sub;
  }
}

int judge(int a, int b){
  if(a<b) return 1;
   else return 0;
}
  
 

  
