#include<stdio.h>
#include<stdlib.h>
 
#define NMIN 1
#define NMAX 36
 
struct Card{
char suit;
char value;  
};
 
 
void bubble(struct Card A[],int N){
  int i,j;
 struct Card t;
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
 
void selection(struct Card A[],int N){
  int i,j,minj;
 struct Card t;
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
 
void print(struct Card A[],int N){
int i;
for(i=0;i<N;i++){
  if(i>0) printf(" ");
  printf("%c%c",A[i].suit,A[i].value);
}
 printf("\n");
}
 
int isStable(struct Card C1[],struct Card C2[],int N){
int i;
  for(i=0;i<N;i++){
    if(C1[i].suit != C2[i].suit) return 0;
  }
  return 1;
}
 
 
 
int main(){
int N,i,j;
struct Card C1[NMAX],C2[NMAX];
char ch;
scanf("%d",&N);
if(N<NMIN||N>NMAX) exit(1);
for(i=0;i<N;i++){
  scanf(" %c%c",&C1[i].suit,&C1[i].value);
}
for(i=0;i<N;i++){
C2[i]=C1[i];
}
bubble(C1,N);
selection(C2,N);
 
print(C1,N);
printf("Stable\n");
print(C2,N);
if(isStable(C1,C2,N)==1){
  printf("Stable\n");
}
else{
  printf("Not stable\n");
}
  return 0;
}

