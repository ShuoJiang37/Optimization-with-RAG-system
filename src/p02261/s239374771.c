#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 36
typedef struct t{
  int val;
  char c;
}C;
int n;
void bubblesort(C sort[]){
  int i,j;
  C tmp;

  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(sort[j].val<sort[j-1].val){
        tmp=sort[j]; sort[j]=sort[j-1]; sort[j-1]=tmp;
      }
    }
  }
}
void selectionsort(C sort[]){
  int i,j,minj;
  C tmp;

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(sort[j].val<sort[minj].val) minj=j;
    }
    tmp=sort[i]; sort[i]=sort[minj]; sort[minj]=tmp;
  }
}
bool isStable(C c1[],C c2[]){
  int i;
  for(i=0;i<n;i++){
    if(c1[i].c!=c2[i].c) return false;
  }
  return true;
}

int main(){
  C c1[MAX],c2[MAX];
  int i,num;
  char m;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&c1[i].c,&c1[i].val);
  }
  for(i=0;i<n;i++) c2[i]=c1[i];
  bubblesort(c1);
  selectionsort(c2);

  for(i=0;i<n;i++) {
    if(i>0) printf(" ");
    printf("%c%d",c1[i].c,c1[i].val);
}
printf("\nStable\n");


  for(i=0;i<n;i++) {
    if(i>0) printf(" ");
    printf("%c%d",c2[i].c,c2[i].val);
}
printf("\n");
  if(isStable(c1,c2)) printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}

