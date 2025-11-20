#include <stdio.h>
#include <string.h>

#define MAX_N 100

void init(int*,int[10][4]);
int getMark(char);
int selectionSort(char*,int*,int,int[10][4]);
int bubbleSort(char*,int*,int,int[10][4]);
void print(char*,int*,int,int);

int main(){
  int idx[10],data[10][4];
  int N,A[MAX_N],A2[MAX_N],i,isStable;
  char M[MAX_N],M2[MAX_N],ch;

  init(idx,data);

  scanf("%d%c",&N,&ch);
  for(i = 0 ; i < N ; i++){
    scanf("%c%d%c",&M[i],&A[i],&ch);
    M2[i] = M[i];
    A2[i] = A[i];
    data[A[i]][idx[A[i]]++] = getMark(M[i]);
  }
  isStable = bubbleSort(M,A,N,data);
  print(M,A,N,isStable);
  isStable = selectionSort(M2,A2,N,data);
  print(M2,A2,N,isStable);
  return 0;
}

void init(int *idx,int data[10][4]){
  int i,j;
  for(i = 0 ; i < 10 ; i++){
    idx[i] = 0;
    for(j = 0 ; j < 4 ; j++){
      data[i][j] = -1;
    }
  }
}

int getMark(char M){
  if(M == 'H'){ return 0; }
  if(M == 'C'){ return 1; }
  if(M == 'S'){ return 2; }
  if(M == 'D'){ return 3; }
  return -1;
}

int selectionSort(char *M,int *A,int N,int data[10][4]){
  int i,j,temp,min,idx,cur[10],isStable = 1;
  char temp2;
  memset(cur,0,sizeof(cur));
  for(i = 0 ; i < N ; i++){
    min = A[i]; idx = i;
    for(j = i+1 ; j < N ; j++){
      if(A[j] < min){
        min = A[j];
        idx = j;
      }
    }
    if(A[idx] < A[i]){
      temp = A[i];
      A[i] = A[idx];
      A[idx] = temp;
      temp2 = M[i];
      M[i] = M[idx];
      M[idx] = temp2;
    }
  }
  for(i = 0 ; i < N ; i++){
    if(data[A[i]][cur[A[i]]] != getMark(M[i])){
      isStable = 0;
      break;
    }
    ++cur[A[i]];
  }
  return isStable;
}

int bubbleSort(char *M,int *A,int N,int data[10][4]){
  int i,j,temp,cur[10],isStable = 1;
  char temp2;
  memset(cur,0,sizeof(cur));
  for(i = 0 ; i < N ; i++){
    for(j = N-1 ; j > i ; j--){
      if(A[j-1] > A[j]){
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        temp2 = M[j];
        M[j] = M[j-1];
        M[j-1] = temp2;
      }
    }
  }
  for(i = 0 ; i < N ; i++){
    if(data[A[i]][cur[A[i]]] != getMark(M[i])){
      isStable = 0;
      break;
    }
    ++cur[A[i]];
  }
  return isStable;
}

void print(char *M,int *A,int N,int isStable){
  int i;
  for(i = 0 ; i < N ; i++){
    printf("%c%d%c",M[i],A[i],(i < N-1 ? ' ' : '\n'));
  }
  if(isStable == 1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
}