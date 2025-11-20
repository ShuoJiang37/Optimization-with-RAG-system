#include<stdio.h>
#define N 36

struct A{
  int num;
  char cha;
};

int main(){
  int i, j, s, minj, tempi, flag = 0;
  char tempc;
  struct A a[N], b[N];

  scanf("%d",&s);
  for(i = 0; i < s; i++){
    scanf(" %c%d",&a[i].cha,&a[i].num);
    b[i].cha = a[i].cha;
    b[i].num = a[i].num;
  }

  for(i = 0; i < s; i++){
    for(j = s - 1; j > i; j--){
      if(a[j].num < a[j-1].num){
	tempi = a[j].num;
	tempc = a[j].cha;
	a[j].num = a[j-1].num;
	a[j].cha = a[j-1].cha;
	a[j-1].num = tempi;
	a[j-1].cha = tempc;
      }
    }
  }
  for(i = 0; i < s; i++){
    printf("%c%d",a[i].cha,a[i].num);
    if(i != s - 1) printf(" ");
  }
  printf("\nStable\n");
  
  for(i = 0; i < s; i++){
    minj = i;
    for(j = i; j < s; j++){
      if(b[j].num < b[minj].num) minj = j;
    }
    tempi = b[i].num;
    tempc = b[i].cha;
    b[i].num = b[minj].num;
    b[i].cha = b[minj].cha;
    b[minj].num = tempi;
    b[minj].cha = tempc;
  }
  for(i = 0; i < s; i++){
    printf("%c%d",b[i].cha,b[i].num);
    if(i != s - 1) printf(" ");
  }
  printf("\n");
  for(i = 0; i < s; i++){
    if(b[i].cha != a[i].cha) flag = 1;
    else if(b[i].num != a[i].num) flag = 1;
  }
  if(flag == 0) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}