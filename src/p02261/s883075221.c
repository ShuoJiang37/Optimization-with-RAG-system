#include<stdio.h>
#define MAX 40
#define true 1
#define false 0

typedef struct{
  char alp,num;
}cinfo;

void bubblesort( cinfo c[],int N){
  int i,j;
  for(i=0;i<N;i+=1){
    for(j=N-1;j>=i+1;j--){
      if(c[j].num < c[j-1].num){
	cinfo tmp = c[j];
	c[j] = c[j-1];
	c[j-1] = tmp;
      }
    }
  }
}

 void selectionsort(cinfo c[],int N){
    int i,j,minj;
    cinfo tmp;
    for(i=0;i<N;i++){
      minj = i;
      for(j=i;j<N;j++){
	if(c[j].num < c[minj].num) minj = j;
      }
      tmp = c[i];
      c[i] = c[minj];
      c[minj] = tmp;
    }
 }

void print( cinfo *c, int N){
  int i;
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%c %c",(c+i)->alp,(c+i)->num);
	   }
  printf("\n");
}


int isstable( cinfo data1[], cinfo data2[],int N){
  int i;
  for(i=0;i<N;i++){
    if(data1[i].alp != data2[i].alp) return false;
  }
  return true;
}

int main(){
  cinfo data1[MAX],data2[MAX];
  int N,i;
  char ch;

  scanf("%d",&N);
  for(i=0;i<N;i+=1){
    scanf(" %c %c",&data1[i].alp,&data1[i].num);
  }

  for(i=0;i<N;i++) data2[i] = data1[i];

   bubblesort(data1,N);
  selectionsort(data2,N);

  
  for(i=0;i<N;i++){
 if(i>0) printf(" ");
    printf("%c%c",data1[i].alp,data1[i].num);
    // if(i>0) printf(" ");
  }
  printf("\n");
  printf("Stable\n");//バブルソートはつねに安定なソート

  
  for(i=0;i<N;i++){
     if(i>0) printf(" ");
    printf("%c%c",data2[i].alp,data2[i].num);
    // if(i>0) printf(" ");
  }
  printf("\n");
  if(isstable(data1,data2,N)) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  
  return 0;
}

