#include<stdio.h>
#include<string.h>
#define MAX 36
typedef struct{
  char mark;
  int num;
}Card;

 // if(strlen(x,y)==0)return 0;//同じだったら０
int swap_s(Card *X,Card *Y){
  Card Z;
  Z=*X;
  *X=*Y;
  *Y=Z;
  return 1;//違ったら１
}
/*
//安定なら1　 ちがったら0
int isStable(Card *In,Card *Out,int n)
{
  int i,j,a,b;

  for (i = 0;i< n;i++){
    for (j = i+1 ;j<n;j++){
      for (a = 0;a <n;a++){
	for (b = a+1;b<n;b++){
	  if (In[i].num ==In[j].num&& In[i].num == Out[b].num && In[i].mark == Out[b].mark && In[j].num == Out[a].num && In[j].mark == Out[a].mark)
	    return 0;
	}
      }
    }
  }
  return 1;
}
*/
//n番目まで安定か？　bubleで確かめる安定なら1　 ちがったら0 
int isStable2(Card *buble,Card *select,int n){
  int i;
  
  for(i=0;i<n;i++){
    if(buble[i].mark!=select[i].mark)return 0;
  }
  return 1;
}



  
//Aの配列を/ n番目まで出力
void sarray_output(Card *A,int N){
  int i;
  for(i=0;i<N;i++){
    if(i)printf(" ");
    printf("%c%d",A[i].mark,A[i].num);
  }
  printf("\n");
}

int bubbleSort(Card *A, int n){
  int flag=1;
  int i,j;
  
  for (i=0;flag;i++){
    flag = 0;//一回も交換しない、 つまり既に並んんでいたら０

    for (j = n-1;j>=1;j--){
      if (A[j].num < A[j-1].num)
	{
	  swap_s(&A[j],&A[j-1]);
	  flag=1;
	}
    }
  }
  return 0;
}

int selectionSort(Card *A,int n){ // N個の要素を含む0-オリジンの配列A
  int i;
  int j;
  int minj;
    
  for (i=0;i<=n-1;i++){
    minj = i;
    for (j=i;j<=n-1;j++){
      if (A[j].num < A[minj].num) minj=j;
    }
    swap_s(&A[i],&A[minj]);
  }
  return 0;
}

int main(){
  Card A[MAX],B[MAX],In[MAX];//A bubule /B selection 
  
  int i;
  int n;

  scanf("%d",&n);
  for(i=0;i<n;i++){//Input
    scanf(" %c%d",&A[i].mark,&A[i].num);
    In[i]= B[i]=A[i];
  }
  
  bubbleSort(A,n);
  selectionSort(B,n);


  //print
  sarray_output(A,n);
  printf("Stable\n");
	    
  sarray_output(B,n);
  if(isStable2(A,B,n))printf("Stable\n");
  else  printf("Not stable\n");
  
  return 0;
}



//(In,B,n)
/*
  2
  H4 D1を昇順に

  出力
  D1 H4 
  Stable
  H4 D1
  Not Stable
 
  バブルソートは絶対安定
*/

