#include<stdio.h>
#include<string.h>

typedef struct{
  char mark;
  int num;
}card;
void Bubblesort(card*);
void Selectionsort(card*);
void isStable(card*);

int n;
card C[36];

int main(){
  card B[36],S[36];
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&C[i].mark,&C[i].num);
  }
  for(i=0;i<n;i++){
    strncpy(&B[i].mark,&C[i].mark,1);
    strncpy(&S[i].mark,&C[i].mark,1);
    B[i].num=C[i].num;
    S[i].num=C[i].num;
  }

  Bubblesort(B);
  Selectionsort(S);

  return 0;
}

void Bubblesort(card *C){
  int i,j,num;
  char mark;
  card chg;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(C[j].num<C[j-1].num){
        chg = C[j];
      C[j] = C[j-1];
      C[j-1] = chg;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%c%d",C[i].mark,C[i].num);
  }
  printf("\n");
  isStable(C);
}

void Selectionsort(card *C){
  int i,j,minj;
  card chg;
  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(C[j].num<C[minj].num){
        minj=j;
      }}
      chg = C[i];
    C[i] = C[minj];
    C[minj] = chg;
    }
    for(i=0;i<n;i++){
      if(i!=0)printf(" ");
      printf("%c%d",C[i].mark,C[i].num);
    }
    printf("\n");
    isStable(C);
  }


  void isStable(card out[]){
    int i,j,a,b,flag=0;
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
        for(a=0;a<n;a++){
          for(b=a+1;b<n;b++){
            if(C[i].num==C[j].num&&C[i].mark==out[b].mark&&C[i].num==out[b].num&&C[j].num==out[a].num&&C[j].mark==out[a].mark){
              flag=1;
            }
          }
        }
      }
    }
    if(flag==0){
      printf("Stable\n");
    }else{
        printf("Not stable\n");
    }
  }

