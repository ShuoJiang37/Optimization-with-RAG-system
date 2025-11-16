#include<string.h>
#define N 36
typedef struct number{
  char card[2];
  int num;
  int judge;
}S;
void bubblesort(S*,int);
void sellectionsort(S*,int);
void judgesort(S*,int);
int myatoi(char x){
  int y;
  y=x-48;
  return y;
}
int main(){
  int a,i;
  S tra[N],np[N];
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%s",tra[i].card);
    strcpy(np[i].card,tra[i].card);
    tra[i].num=myatoi(tra[i].card[1]);
    np[i].num=tra[i].num;
    tra[i].judge=i;
    np[i].judge=i;
  }
  bubblesort(tra,a);
  printf("%s",tra[0].card);
  for(i=1;i<a;i++)printf(" %s",tra[i].card);
  printf("\n");
  judgesort(tra,a);
  sellectionsort(np,a);
  printf("%s",np[0].card);
  for(i=1;i<a;i++)printf(" %s",np[i].card);
  printf("\n");
  judgesort(np,a);
  return 0;
}
void judgesort(S *tra,int y){
  int flag=1;
  int i;
  for(i=0;i<y;i++){
    if(tra[i].num==tra[i+1].num){
      if(tra[i].judge>tra[i+1].judge){
        printf("Not stable\n");
        flag=0;
        break;
      }
    }
  }
    if(flag)printf("Stable\n");
}
void bubblesort(S *tra,int x){
  int flag=1,j;
  S r;
  while(flag){
    flag=0;
    for(j=x-1;1<=j;j--){
      if(tra[j].num<tra[j-1].num){
        r=tra[j];
        tra[j]=tra[j-1];
        tra[j-1]=r;
        flag=1;
      }
    }
  }
}
void sellectionsort(S *tra,int x){
  int j,minj,i;
  S r;
  for(i=0;i<x;i++){
    minj=i;
    for(j=i;j<x;j++){
      if(tra[j].num<tra[minj].num)minj=j;
    }
    if(i!=minj){
      r=tra[i];
      tra[i]=tra[minj];
      tra[minj]=r;
    }
  }
}

