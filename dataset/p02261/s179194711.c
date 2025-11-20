#include<stdio.h>
#include<stdlib.h>
 
#define NMIN 1
#define NMAX 36
 
struct Number{
char mark;
char value;  
};
 
 
void bubble(struct Number A[],int N){
  int i,j;
 struct Number t;
  for(i=0;i<N;i++){
for(j=N-1;j>=i;j--){
  if(A[j].value<A[j-1].value){
    t=A[j];
    A[j]=A[j-1];
    A[j-1]=t;
  }
}    
  }
}
 
void selections(struct Number A[],int N){
  int i,j,minj;
 struct Number t;
  for(i=0;i<N;i++){
minj=i; 
for(j=i;j<N;j++){
  if(A[j].value<A[minj].value) minj=j;
}
t=A[i];
A[i]=A[minj];
A[minj]=t;
  }
}
 
void print(struct Number A[],int N){
int i;
for(i=0;i<N;i++){
  if(i>0) printf(" ");
  printf("%c%c",A[i].mark,A[i].value);
}
 printf("\n");
}
 
int isStable(struct Number N1[],struct Number N2[],int N){
int i;
  for(i=0;i<N;i++){
    if(N1[i].mark != N2[i].mark) return 0;
  }
  return 1;
}
 
 
 
int main(){
int N,i,j;
struct Number N1[NMAX],N2[NMAX];
char ch;
scanf("%d",&N);
if(N<NMIN||N>NMAX) exit(1);
for(i=0;i<N;i++){
  scanf(" %c%c",&N1[i].mark,&N1[i].value);
}
for(i=0;i<N;i++){
N2[i]=N1[i];
}
bubble(N1,N);
selections(N2,N);
 
print(N1,N);
printf("Stable\n");
print(N2,N);
if(isStable(N1,N2,N)==1){
  printf("Stable\n");
}
else{
  printf("Not stable\n");
}
  return 0;
}

