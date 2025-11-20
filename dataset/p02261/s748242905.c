#include<stdio.h>

#define MAX 36

struct Node{
  int value;
  char mark;
};

void BubbleSort(struct Node *C, int n){
  int i, j;
  struct Node buf;
  
  for(i = 0; i < n; i++){
    for(j = n - 1; j > i; j--){
      if(C[j].value < C[j - 1].value){
	buf = C[j];
	C[j] = C[j - 1];
	C[j - 1] = buf;
      }
    }
  }
}

void SelectionSort(struct Node *C, int n){
  int i,j,minj;
  struct Node buf;
  
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(C[j].value < C[minj].value){
	minj = j;
      }
    }
    buf = C[i];
    C[i] = C[minj];
    C[minj] = buf;
  }

}

int main(){
  int i,j,n,f;
  struct Node c[MAX],d[MAX];
  int count[MAX] = {};
  char ex[MAX][4] = {};

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%c",&c[i].mark);
    if(c[i].mark == '\n' || c[i].mark == ' '){
      --i;
      continue;
    }  
    scanf("%d",&c[i].value);

    // ex[7][] = {'S','C'} 
    // count[] でその数が複数あったか確認させる
    ex[c[i].value][count[c[i].value]++] = c[i].mark;

    d[i].mark = c[i].mark;
    d[i].value = c[i].value;
  }

  BubbleSort(c,n);
  SelectionSort(d,n);

  for(i = 0; i < (n - 1); i++){
    printf("%c%d ",c[i].mark,c[i].value);
  }
  printf("%c%d\n",c[i].mark,c[i].value);
  
  f = 0;

  if(f == 0)
    printf("Stable\n");
  else
    printf("Not stable\n");
  
  for(i = 0; i < (n - 1); i++)
    printf("%c%d ",d[i].mark,d[i].value);
  printf("%c%d\n",d[i].mark,d[i].value);
  
  f = 0;
  for(i = 0; i < n; i++){
    if(count[d[i].value] > 1){
      // input: H2 H1 S2
      // H1 ここから->H2 S2
      for(j = 0; j < count[d[i].value]; j++){
	if(d[j + i].mark != ex[d[i].value][j]){
	  f = 1;
	  break;
	}
      }
      i += count[d[i].value];
    }
  }
  if(f == 0)
    printf("Stable\n");
  else
    printf("Not stable\n");
  

  return 0;
}

