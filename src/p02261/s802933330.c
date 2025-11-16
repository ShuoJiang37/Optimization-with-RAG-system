#include<stdio.h>

typedef struct{
  char mark;
  int value;
}card;

void BobbleSort(card  *,int);
void SelectionSort(card*,int);
int check(card *,card *,int);

int main (){
  int N,i;

  scanf("%d",&N);

  card a1[N],a2[N],a[N];

  for(i=0;i<N;++i){
    scanf(" %c%d",&a1[i].mark,&a1[i].value);
    a2[i]=a1[i];
    a[i]=a1[i];
  }
  
  BobbleSort(a1,N);
  for(i=0;i<N-1;++i)printf("%c%d ",a1[i].mark,a1[i].value);
  printf("%c%d\n",a1[N-1].mark,a1[N-1].value);
  
  if(check(a1,a,N)==1)printf("Stable\n");
  else printf("Not stable\n");

  

  SelectionSort(a2,N);
  for(i=0;i<N-1;++i)printf("%c%d ",a2[i].mark,a2[i].value);
  printf("%c%d\n",a2[N-1].mark,a2[N-1].value);
  
  if(check(a2,a,N)==1)printf("Stable\n");
  else printf("Not stable\n");

  
  return 0;
}

void BobbleSort(card *a,int N){
  int i,j;
  card tmp;
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(a[j].value < a[j-1].value){
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
      }
    }
  }
}

void SelectionSort(card *a,int N){
  int i,minj,j;
  card tmp;

  for(i=0;i<N;++i){
    minj=i;
    for(j=i;j<N;j++){
      if(a[j].value < a[minj].value){
	minj = j;
      }
    }
    tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;
  }
}

int check(card *in,card *out,int N){
  int i,j,a,b;

  for(i=0;i<N;++i){
    for(j=i+1;j<N;j++){
      for(a=0;a<N;a++){
	for(b=a+1;b<N;b++){
	  if((in[i].value==in[j].value)&&
	     (in[i].value==out[b].value&&in[i].mark==out[b].mark)&&
	     (in[j].value==out[a].value&&in[j].mark==out[a].mark)){
	    return 0;
	  }
       }
      }
    }
  }

  return 1; 
}

