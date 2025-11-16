#include <stdio.h>
#include <stdlib.h>
#define N 36

typedef struct trump{
  char mark;
  int value;
} TRUMP;

TRUMP *bubble(TRUMP *,int);
TRUMP *selection(TRUMP *,int);
void swap(TRUMP *,TRUMP *);
void listprint(TRUMP *,int num);
void JUDGE(TRUMP *,TRUMP *,int);

int main()
{
  int num;
  char tmp[3];
  TRUMP C_in[N],C1[N],C[N];
  TRUMP *bubble_C,*selection_C;

scanf("%d",&num);
for(int i = 0; i < num; i++){
  scanf("%s",tmp);
  C_in[i].mark = tmp[0];
  C_in[i].value = atoi(&tmp[1]);
  C[i] = C_in[i];
  C1[i] = C_in[i];
}

bubble_C = bubble(C,num);
selection_C = selection(C1,num);

listprint(bubble_C,num);
JUDGE(C_in,bubble_C,num);

listprint(selection_C,num);
JUDGE(C_in,selection_C,num);

  return 0;
}

TRUMP *bubble(TRUMP *C,int num){
  for(int i = 0; i < num; i++){
    for(int j = num - 1; j > i; j--){
      if(C[j].value < C[j-1].value) swap(&C[j],&C[j-1]);
    }
  }
  return C;
}

TRUMP *selection(TRUMP *C,int num){
  int minj,i,j;
  for(i = 0; i < num; i++){
    minj = i;
    for(j = i; j < num; j++){
      if(C[j].value < C[minj].value) minj = j;
    }
    swap(&C[i],&C[minj]);
  }
  return C;
}

void swap(TRUMP *x,TRUMP *y){
  TRUMP tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

void listprint(TRUMP *C,int num){
  for(int i = 0;i < num - 1; i++){
    printf("%c%d ",C[i].mark,C[i].value);
  }
  printf("%c%d\n",C[num - 1].mark,C[num-1].value);
}

void JUDGE(TRUMP *in,TRUMP *out,int num){
  int cnt = 0;
  for(int i = 0; i < num; i++){
    for(int j = i + 1; j < num;j++){
      for(int k = 0; k < num; k++){
        for(int l = k + 1; l < num; l++){
          if((in[i].value == in[j].value) && (in[i].value == out[l].value) && (in[j].value == out[k].value) && (in[i].mark == out[l].mark) && (in[j].mark == out[k].mark) && (cnt == 0)){
            printf("Not stable\n");
            cnt++;
          }
        }
      }
    }
  }
  if(cnt == 0) printf("Stable\n");
}

