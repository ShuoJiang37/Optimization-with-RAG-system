#include<stdio.h>
#include<stdlib.h>

typedef struct {
  char suit;
  char value;
  int ID;
}Card;

int main(){
  Card C1[37], C2[37],temp;
  int N,i,j,mini,flag;
  char ch,tempc,tempc2;

  scanf("%d%c", &N,&ch);
  if(N<1||N>36){
    printf("N ha 1-36 death!\n");
    exit(1);
  }

  for (i=0;i<N;i++){
    scanf("%c%c%c",&C1[i].suit,&C1[i].value,&ch);
    C1[i].ID=i;
    C2[i]=C1[i];
  }

  //Bubble
  for (i=0;i<N-1;i++){
    for (j=N-1;j>=i+1;j--){
      if(C2[j].value < C2[j-1].value){
        temp=C2[j];
        C2[j]=C2[j-1];
        C2[j-1]=temp;
      }
    }
  }

  for (i=0;i<N;i++){
    printf("%c%c",C2[i].suit,C2[i].value);
    if(i<N-1){
      printf(" ");
    }
  }
  printf("\n");

  flag=0;	
  for (i=0;i<N;i++){
    for (j=i+1;j<=N;j++){
      if (C2[i].value==C2[j].value){
        if(C2[i].ID>C2[j].ID){
          printf("Not stable\n");
          flag=1;
        }
      }
    }
  }
  if(flag==0){
    printf("Stable\n");
  }

  for (i=0;i<N;i++){
    C2[i]=C1[i];
  }

  //SelectionSort
  for (i=0;i<=N-1;i++){
    flag=0;
    mini=i;
    for (j=i;j<=N-1;j++){
      if (C2[j].value < C2[mini].value){
        mini = j;
        flag=1;
      }
    }
    if(flag==1){
      temp=C2[i];
      C2[i]=C2[mini];
      C2[mini]=temp;
    }
  }
  for (i=0;i<N;i++){
    printf("%c%c",C2[i].suit,C2[i].value);
    if(i<N-1){
      printf(" ");
    }
  }
  printf("\n");

  for (i=0;i<N;i++){
    for (j=i+1;j<=N;j++){
      if (C2[i].value==C2[j].value){
        if(C2[i].ID>C2[j].ID){
          printf("Not stable\n");
          return 0;
        }
      }
    }
  }

  printf("Stable\n");

  return 0;
}