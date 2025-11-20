#include<stdio.h>
#include<string.h>

#define N 36

typedef struct pp{
  char name;
  int value;
}CARD;


int n;
CARD data[N],data1[N];


void BubbleSort(CARD* ,int);
void SelectionSort(CARD* ,int);
int isStable(CARD*,CARD*,int);


int main(){
  int i,j,m;
  char t;

  scanf("%d",&n);

  scanf(" %c",&data[0].name);
  scanf("%d",&data[0].value);
  data1[0]=data[0];
  for(j=1;j<n;j++){
    scanf(" %c",&data[j].name);
    scanf("%d",&data[j].value);
    data1[j]=data[j];
  }

  
  BubbleSort(data,n);

  SelectionSort(data1,n);

  m=isStable(data,data1,n);

  printf("%c%d",data[0].name,data[0].value);
  for(j=1;j<n;j++) printf(" %c%d",data[j].name,data[j].value);
  printf("\nStable\n");

  printf("%c%d",data1[0].name,data1[0].value);
  for(j=1;j<n;j++) printf(" %c%d",data1[j].name,data1[j].value);
  if(m==0) printf("\nNot stable\n");
  else printf("\nStable\n");

  return 0;
  
  
}

void BubbleSort(CARD *B,int n){
  int i,j;
  CARD temp;
  
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(B[j].value<B[j-1].value){
	temp=B[j];
	B[j]=B[j-1];
	B[j-1]=temp;
      }
    }
  }

  return;
}

void SelectionSort(CARD *S,int n){
  int i,j,min;
  CARD temp;

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(S[j].value<S[min].value) min=j;
    }
    temp=S[i];
    S[i]=S[min];
    S[min]=temp;
  }

  return;
}

int isStable(CARD *in,CARD *out,int n){
  int i,j,a=0,b=0;

  for(i=0;i<n;i++){
    if(strcmp(&in[i].name,&out[i].name)==0) a++;
  }
  for(i=0;i<n;i++){
    if(in[i].value==out[i].value) b++;
  }
  

  if(a==b) return 1;

  else return 0;
}

