#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 36

typedef struct{
  char str[3];
  int value;
} Tramp;

void bubbleSort(Tramp *,int);
void selectionSort(Tramp *,int);
  
int main(void){
  int num,cnt;
  int i;
  Tramp A[N],C1[N],C2[N];

  scanf(" %d",&num);
  
  for(i = 0; i < num; i++){
    scanf(" %s",A[i].str);
  }

  for(i = 0; i < num; i++){
    strcpy(C1[i].str,A[i].str);
    C1[i].value = atoi((A[i].str)+1);
  }

  for(i = 0; i < num; i++){
    strcpy(C2[i].str,A[i].str);
    C2[i].value = atoi((A[i].str)+1);
  }

  bubbleSort(C1,num);
  selectionSort(C2,num);

  for(i = 0; i < num-1; i++){
    printf("%s ",C1[i].str);
  }
  printf("%s\n",C1[num-1].str);
  printf("Stable\n");

  for(i = 0; i < num-1; i++){
    printf("%s ",C2[i].str);
  }
  printf("%s\n",C2[num-1].str);
  
  for(i = 0; i < num; i++){
    if(strcmp(C1[i].str,C2[i].str) != 0){
      printf("Not stable\n");
      break;
    }
  }
  if(i == num){
    printf("Stable\n");
  }
  
  
  return 0;
}

void bubbleSort(Tramp *A, int num){
  int i,j;
  int tmp;
  char str_tmp[3];

  for(i = 0; i < num; i++){
    for(j = num -1; j > i; j--){
      if(A[j].value < A[j-1].value){
	tmp = A[j-1].value;
	A[j-1].value = A[j].value;
	A[j].value = tmp;
	strcpy(str_tmp,A[j-1].str);
	strcpy(A[j-1].str,A[j].str);
	strcpy(A[j].str,str_tmp);
      }
    }
  }

}
  
void selectionSort(Tramp *A, int num){
  int i,j;
  int min,tmp;
  char str_tmp1[3],str_tmp2[3];

  for(i = 0; i < num; i++){
    min = i;
    for(j = i; j < num; j++){
      if(A[j].value < A[min].value){
	min = j;
      }
    }
    tmp = A[i].value;
    A[i].value = A[min].value;
    A[min].value = tmp;
    strcpy(str_tmp1,A[i].str);
    strcpy(str_tmp2,A[min].str);
    strcpy(A[i].str,str_tmp2);
    strcpy(A[min].str,str_tmp1);
  }

}

