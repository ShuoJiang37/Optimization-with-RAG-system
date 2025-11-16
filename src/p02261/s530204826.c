#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct{
  char c;
  int num;
}pair;

void bubblesort(pair* , int );
void selectionsort(pair* , int);



int main(){

  int e,n,i,j,temp,flag = 0;
  pair box[64];
  pair in1[64];
  pair in2[64];
  char emp;

  scanf("%d\n",&n);
  // printf("n = %d\n",n);

  for(i = 0;i < n;i++){
    // printf("%d\n",i);
    scanf("%c",&box[i].c);
    scanf("%d",&box[i].num);
    if(i != n - 1) scanf("%c",&emp);
    // scanf("%c\n",&emp);

    // printf("c = %c,num = %d\n",box[i].c,box[i].num);
    in1[i].c = box[i].c;
    in2[i].c = box[i].c;
    in1[i].num = box[i].num;
    in2[i].num = box[i].num;
  }

  bubblesort(in1,n);
  
  for(i = 0;i < n;i++){
    printf("%c",in1[i].c);
    if(i != n - 1) printf("%d ",in1[i].num);
    else printf("%d\n",in1[i].num);
  }

  printf("Stable\n");

  selectionsort(in2,n);


  for(i = 0;i < n;i++){
    printf("%c",in2[i].c);
    if(i != n - 1) printf("%d ",in2[i].num);
    else printf("%d\n",in2[i].num);
  }

  for(i = 0;i < n;i++){
    if(in1[i].num != in2[i].num || in1[i].c != in2[i].c){
      flag = 1;
      break;
    }
  }
  if(flag == 0) printf("Stable\n");
  else printf("Not stable\n");


  return 0; 
}

void bubblesort(pair *c, int n){

  int temp,i,j;
  char tem;
  for(i = 0;i <= n - 1;i++){
    for(j = n - 1;j >= i + 1;j--){
      if(c[j].num < c[j - 1].num){
	temp = c[j].num;
	tem = c[j].c;
	c[j].num = c[j - 1].num;
	c[j].c = c[j - 1].c;
	c[j - 1].num = temp;
	c[j - 1].c = tem;
      }
    }
  }

}


void selectionsort(pair *c, int n){

  int i,j,temp,minj;
  char tem;
  for(i = 0;i <= n - 1;i++){
    minj = i;
    for(j = i;j <= n - 1 ;j++){
      if(c[j].num < c[minj].num){
	minj = j;
      }
    }
    temp = c[i].num;
    tem = c[i].c;
    c[i].num = c[minj].num;
    c[i].c = c[minj].c;
    c[minj].num = temp;
    c[minj].c = tem;
  }
}