#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  char num[2];
  int  value;
}Roll;

void BubbleSort(Roll *);
void isStable(Roll * ,Roll *);

int N;

int main(){
  Roll *Cin;
  Roll *C;
  Roll *C1;
  int i,j;
  Roll c;
  int mini;

  scanf("%d",&N);
  C=(Roll *)malloc(N*sizeof(Roll));
  Cin=(Roll *)malloc(N*sizeof(Roll));
  C1=(Roll *)malloc(N*sizeof(Roll));
  for(i=0;i<N;i++){
    scanf("%s",C[i].num);
    C1[i].num[0]=C[i].num[0];
    C1[i].num[1]=C[i].num[1];
    Cin[i].num[0]=C[i].num[0];
    Cin[i].num[1]=C[i].num[1];

    C[i].value=C[i].num[1]-'0';
    C1[i].value=C[i].num[1]-'0';
    Cin[i].value=C[i].num[1]-'0';
  }
  BubbleSort(C1);

  for(i=0;i<N;i++){
    mini=i;
    for(j=i;j<N;j++){
      if(C[j].value<C[mini].value)
	mini=j;
    }
    c=C[i];
    C[i]=C[mini];
    C[mini]=c;
  }
  for(i=0;i<N-1;i++) printf("%s ",C[i].num);
  printf("%s\n",C[i].num);
  isStable(C,Cin);
}

void isStable(Roll *in,Roll *out){
  int i,j;
  int a,b;  
  for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      for(a=0;a<N;a++){
	for(b=a+1;b<N;b++){
	  if(in[i].value==in[j].value&&in[i].num[0]==out[b].num[0]&&in[j].num[0]==out[a].num[0]){
	    printf("Not stable\n");
	    return;
          }
        }
      }
    }
  }
printf("Stable\n");	
return;
}
	
void BubbleSort(Roll *C){
int i,j;
Roll c;
for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(C[j].value<C[j-1].value){
        c=C[j];
        C[j].num[0]=C[j-1].num[0];
        C[j].num[1]=C[j-1].num[1];
        C[j].value=C[j-1].value;
        C[j-1].num[0]=c.num[0];
        C[j-1].num[1]=c.num[1];
        C[j-1].value=c.value;
      }
    }
  }

  for(i=0;i<N-1;i++) printf("%s ",C[i].num);
  printf("%s\n",C[i].num);
  printf("Stable\n");
}

