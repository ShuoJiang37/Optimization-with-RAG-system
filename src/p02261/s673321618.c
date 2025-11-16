#include<stdio.h>
#include<stdlib.h>
#define NMIN 1
#define NMAX 36

struct card{
  char mark;
  char value;
};

void bubble(struct card A[],int n){
  int i,j;
  struct card t;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j].value<A[j-1].value){
	t=A[j];
	A[j]=A[j-1];
	A[j-1]=t;
      }
    }
  }
}
void selection(struct card A[],int n){
  int i,j,miji;
  struct card t;
  for(i=0;i<n;i++){
    miji=i;
    for(j=i;j<n;j++){
      if(A[j].value<A[miji].value)miji=j;
    }
    t=A[i];
    A[i]=A[miji];
    A[miji]=t;
      }
    }
void print(struct card A[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%c%c",A[i].mark,A[i].value);
  }
  printf("\n");
}
int isStable(struct card c1[],struct card c2[],int n){
  int i;
  for(i=0;i<n;i++){
    if(c1[i].mark!=c2[i].mark) return 0;
  }
  return 1;
}

int main(){
  int n,i,j;
  struct card c1[NMAX],c2[NMAX];
  char ch;

  scanf("%d",&n);
  if(n<NMIN || n>NMAX)exit(1);
  for(i=0;i<n;i++){
    scanf(" %c%c",&c1[i].mark,&c1[i].value);
  }
  for(i=0;i<n;i++){
    c2[i]=c1[i];
  }
  bubble(c1,n);
  selection(c2,n);

  print(c1,n);
  printf("Stable\n");
  print(c2,n);
  if(isStable(c1,c2,n)==1){
    printf("Stable\n");
  }
  else {printf("Not stable\n");
  }
  return 0;
}
    

