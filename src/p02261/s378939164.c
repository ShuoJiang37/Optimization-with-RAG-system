#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int num;
    char alp;
}data;

void output(data *,int);
void bubble(data *,int);
void selection(data *,int);
void swap(data *,data *);
int check_stable(data *,data *,int);

int main(void){ 
  int N;
  int i;
  data *bubble_data,*sort_data;

  /* input */
  scanf("%d",&N);

  bubble_data=(data *)malloc(sizeof(data)*N);
  sort_data=(data *)malloc(sizeof(data)*N);

  for(i=0;i<N;i++){
    getchar();
    bubble_data[i].alp=getchar();
    scanf("%d",&bubble_data[i].num);
    sort_data[i]=bubble_data[i];
  }


  /* bubble sort */
  bubble(bubble_data,N);
  output(bubble_data,N);
  printf("\nStable\n");

  /* selection sort */
  selection(sort_data,N);
  output(sort_data,N);
  for(i=0;i<N;i++){
    if(bubble_data[i].alp!=sort_data[i].alp) break;
  }
  if(i==N)printf("\nStable\n");
  else printf("\nNot stable\n");

  free(sort_data);
  free(bubble_data);

  return 0;
}


void output(data *data,int N){
  int i;

  printf("%c%d",data[0].alp,data[0].num);
  for(i=1;i<N;i++){
    printf(" %c%d",data[i].alp,data[i].num);
  }
}


void bubble(data *data,int N){
  int i,j;

  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(data[j-1].num>data[j].num) swap(&data[j-1],&data[j]);
    }
  }
}


void selection(data *data,int N){
  int i,j;
  int min;

  for(i=0;i<N-1;i++){
    min=i;
    for(j=i+1;j<N;j++){
      if(data[min].num>data[j].num) min=j;
    }
    if(min!=i) swap(&data[i],&data[min]);
  }
}


void swap(data *a,data *b){
  data work;
  
  work=*a;
  *a=*b;
  *b=work;
}