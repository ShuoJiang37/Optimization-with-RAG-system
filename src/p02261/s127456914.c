#include <stdio.h>


typedef struct{
  char mj;
  int  num;
}trump;

void show(trump A[],int N){
  for (int  i = 0; i < N; i++) {
    printf("%c%d",A[i].mj,A[i].num );
    if(i!=N-1)printf(" ");
  }
  printf("\n");
}

void bubble(trump A[],int N){
  int sw;
  char swc;
  for (int i = 0; i < N-1; i++) {
    for (int j = N-1; i < j; j--) {
      if(A[j].num < A[j-1].num){
        sw = A[j].num;
        A[j].num=A[j-1].num;
        A[j-1].num=sw;
        swc = A[j].mj;
        A[j].mj=A[j-1].mj;
        A[j-1].mj=swc;
      }
    }
  }
}

int comp(trump A[],trump B[],int N){
    for (int i = 0; i < N; i++) {
      if(A[i].mj!=B[i].mj) return 0;
    }
    return 1;
}

void selection(trump A[],int N)
{
  int minj;
  trump sw;
  for (int i = 0; i < N-1; i++) {
    minj=i;
    for (int j = i; j < N; j++) {
      if(A[minj].num>A[j].num) minj=j;
    }
    sw=A[i];A[i]=A[minj];A[minj]=sw;
  }

}

int main()
{
 trump I[100];
 trump B[100];
 int N;
 scanf("%d\n",&N);
 /*for (int i = 0; i < N; i++) {
   scanf("%c%d",&I[i].mj,&I[i].num);
   B[i].num = I[i].num;
   B[i].mj = I[i].mj;
 }*/
 int i;
 for(i=0;i<N;i++){
scanf(" %c%d",&I[i].mj,&I[i].num);
B[i]=I[i];
}
 bubble(B,N);
 show(B,N);
 if(comp(B,B,N)) printf("Stable\n"); else printf("Not stable\n" );
 selection(I,N);
 show(I,N);
  if(comp(B,I,N)) printf("Stable\n"); else printf("Not stable\n" );
 return 0;
}

