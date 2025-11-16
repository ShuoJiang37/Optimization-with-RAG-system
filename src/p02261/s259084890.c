#include<stdio.h>
#include<stdlib.h>

void BubbleSort(void);
void SelectionSort(void);

int n;

typedef struct{
  char kind;
  int value;
}array;

array C[36],B[36],S[36],temp;

int main(){
  int i;

  scanf("%d",&n);

  if(n>=1 && n<=36){
    for (i=0; i<n; i++){
      scanf(" %c",&C[i].kind);
      scanf("%d",&C[i].value);
      B[i] = S[i] = C[i];
    }
    BubbleSort();
    SelectionSort();
  }

  return 0;
}

void BubbleSort(void)
{
  int i,j,a,b;
  int jud=1;

  for (i=0; i<n; i++){
    for (j=n-1; j>0; j--){
      if (B[j].value < B[j-1].value){
        temp = B[j-1];
        B[j-1] = B[j];
        B[j] = temp;
      }
    }
  }

  for (i=0; i<n-1; i++) printf("%c%d ",B[i].kind,B[i].value);
  printf("%c%d\n",B[i].kind,B[i].value);

  for(i=0; i<n; i++){
    for(j=i+1; j<n; j++){
      for(a=0; a<n; a++){
        for(b=a+1; b<n; b++){
          if (C[i].value == C[j].value){
            if ((C[i].value == B[b].value) && (C[i].kind == B[b].kind)){
              if ((C[j].value == B[a].value) && (C[j].kind == B[a].kind))
                jud = 0;
            }
          }
        }
      }
    }
  }

  if (jud == 0) printf("Not stable\n");
  if (jud == 1) printf("Stable\n");
}

void SelectionSort(void)
{
  int i,j,minj,a,b,jud=1;

  for (i=0; i<n; i++){
    minj = i;
    for (j=i; j<n; j++){
      if (S[j].value < S[minj].value){
        minj = j;
      }
    }
    if (minj != i){
      temp = S[i];
      S[i] = S[minj];
      S[minj] = temp;
    }
  }
  for (i=0; i<n-1; i++) printf("%c%d ",S[i].kind,S[i].value);
  printf("%c%d\n",S[i].kind,S[i].value);

  for(i=0; i<n; i++){
    for(j=i+1; j<n; j++){
      for(a=0; a<n; a++){
        for(b=a+1; b<n; b++){
          if (C[i].value == C[j].value){
            if ((C[i].value == S[b].value) && (C[i].kind == S[b].kind)){
              if ((C[j].value == S[a].value) && (C[j].kind == S[a].kind))
                jud = 0;
            }
          }
        }
      }
    }
  }

  if (jud == 0) printf("Not stable\n");
  if (jud == 1) printf("Stable\n");
}
