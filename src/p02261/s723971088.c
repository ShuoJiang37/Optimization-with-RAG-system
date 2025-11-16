#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef struct{
  char kind;
  int num;
} data;
int N;
int isStable(data *,data *);
void BubbleSort(data *,int);
void SelectionSort(data *,int);

int main()
{
  int i; 
  data *in, *B, *S;
  
  scanf("%d",&N);
  in = (data *)malloc(N * sizeof(data));
  B = (data *)malloc(N * sizeof(data));
  S = (data *)malloc(N * sizeof(data));

  for(i = 0 ; i < N ; i++){
    scanf(" %c%d",&in[i].kind,&in[i].num);
    B[i] = in[i];
    S[i] = in[i]; }

  BubbleSort(B ,N); 
  SelectionSort(S, N);

  for(i = 0 ; i < N-1 ; i++) printf("%c%d ",B[i].kind,B[i].num);
  printf("%c%d\n",B[N-1].kind,B[N-1].num);
  if(isStable(in,B) == true) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0 ; i < N-1 ; i++) printf("%c%d ",S[i].kind,S[i].num);
  printf("%c%d\n",S[N-1].kind,S[N-1].num);
  if(isStable(in,S) == true) printf("Stable\n");
  else printf("Not stable\n");

  free(in);
  free(B);
  free(S);
  
  return 0;
}

int isStable(data *in,data *out){
  int i, j, a, b;

  for(i = 0 ; i < N-1 ; i++){
    for(j = i+1 ; j < N-1 ; j++){ 
      for(a = 0 ; a < N-1 ; a++){
	for(b = a+1 ; b < N-1 ; b++){
	  if(in[i].num == in[j].num && in[i].num == out[b].num && in[j].num == out[a].num){
	    if(in[i].kind == out[b].kind && in[j].kind == out[a].kind) return false; }
	}
      }
    }
  }
  
  return true;
}

void BubbleSort(data *C,int N){
  int i, j, num;
  char kind;
  
  for(i = 0 ; i < N-1 ; i++){
    for(j = N-1 ; j >= i+1 ; j--){
      if(C[j].num < C[j-1].num){
	num = C[j].num;
	C[j].num = C[j-1].num;
	C[j-1].num = num;
	kind = C[j].kind;
	C[j].kind = C[j-1].kind;
	C[j-1].kind = kind; }
    }
  }
      
}

void SelectionSort(data *C,int N){
  int i, j, minj, for_change_num;
  char for_change_kind;
  
  for(i = 0 ; i < N-1 ; i++){
    minj = i;
    for(j = i ; j <= N-1 ; j++){
      if(C[j].num < C[minj].num) minj = j; }
    for_change_num = C[i].num;
    C[i].num = C[minj].num;
    C[minj].num = for_change_num;
    for_change_kind = C[i].kind;
    C[i].kind = C[minj].kind;
    C[minj].kind = for_change_kind;
  }

}

