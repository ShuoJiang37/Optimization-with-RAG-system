#include<stdio.h>
#define N 36
typedef struct {
  char mark;
  int value;
}DATA;

void stable(DATA *,DATA *,int);
void display(DATA *,int);

int main()
{
  DATA A[N],B[N],C[N],V;
  int n,i,j,minj,flag,count;
  char sp;
  scanf("%d%c",&n,&sp);
  for(i=0;i<n;i++){
    scanf("%c%d%c",&A[i].mark,&A[i].value,&sp);
    B[i] = A[i];
    C[i] = A[i];
  }

  flag = 1;
  j = 1;

  while(flag){
    flag = 0;
    for(i = n-1;i >= j;i--){
      if(B[i].value < B[i-1].value){
        flag = 1;
        V = B[i];
        B[i] = B[i-1];
        B[i-1] = V;
        count++;
      }
    }
    j++;
  }

  display(B,n);
  printf("Stable\n");

  for(i = 0;i < n;i++){
    minj = i;
    for(j = i;j < n;j++){
      if(C[j].value < C[minj].value) minj = j;
    }
    if(C[i].value != C[minj].value) count++;
    V = C[i];
    C[i]  = C[minj];
    C[minj] = V;
  }

  display(C,n);
  stable(C,A,n);

  return 0;
}

void display(DATA *A,int n){
  int i;
  for(i = 0;i < n;i++){
    printf("%c%d",A[i].mark,A[i].value);
    if(i == n-1) break;
    printf(" ");
  }printf("\n");
}

void stable(DATA *A,DATA *B,int n){
  int i,j,k,l,same = 0,flag = 0;
  for(i = 0;i < n;i++){
    for(l = i+1;l < n;l++){
      if(A[i].value == A[l].value){
        same = 1;
        for(j = 0;j < n;j++){
          if(A[i].value == B[j].value){
            for(k = j+1;k < n;k++){
              if(B[j].value == B[k].value){
                if(A[i].mark != B[j].mark || A[l].mark != B[k].mark){
                  flag = 1;
                }
              }
            }
          }
        }
      }
    }
  }
  if(same == 0 || flag == 0) printf("Stable\n");
  else printf("Not stable\n");
}

