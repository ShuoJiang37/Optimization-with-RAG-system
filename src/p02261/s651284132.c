#include <stdio.h>
#include <string.h>

#define N 36

typedef struct{

  char c;
  int n;

} Card;

void bubble_sort(Card*, int);
void selec_sort(Card*, int);

int main(int argc, char const *argv[]) {

  int i;
  int num;

  Card card[N],bubble[N],selec[N];

  scanf("%d",&num);

  for( i = 0 ; i < num ; i++ ){
    scanf(" %c%d",&card[i].c,&card[i].n);

    bubble[i] = selec[i] = card[i];
  }

  bubble_sort(bubble,num);
  selec_sort(selec,num);

  for( i = 0 ; i < num ; i++ ){

    if( i == num-1 ){
      printf("%c%d\n",bubble[i].c,bubble[i].n);
    }else{
      printf("%c%d ",bubble[i].c,bubble[i].n);
    }

  }

  printf("Stable\n");

  for( i = 0 ; i < num ; i++ ){

    if( i == num-1 ){
      printf("%c%d\n",selec[i].c,selec[i].n);
    }else{
      printf("%c%d ",selec[i].c,selec[i].n);
    }

  }

  for( i = 0 ; i < num ; i++ ){

    if( selec[i].c != bubble[i].c && selec[i].n == bubble[i].n ){
      printf("Not stable\n");
      return 0;
    }

  }

  printf("Stable\n");

  return 0;
}

void bubble_sort(Card *a, int n){

  int i,j;
  int tempn;
  char tempc;

  for( i = 0 ; i < n ; i++ ){
    for( j = n-1 ; j > i ; j-- ){

      if( a[j].n < a[j-1].n ){
        tempn = a[j].n;
        a[j].n = a[j-1].n;
        a[j-1].n = tempn;

        tempc = a[j].c;
        a[j].c = a[j-1].c;
        a[j-1].c = tempc;
      }

    }

  }

}

void selec_sort(Card *a, int n){

  int i,j,mini;
  int tempn;
  char tempc;

  for( i = 0 ; i < n ; i++ ){
    mini = i;
    for( j = i ; j < n ; j++ ){
      if( a[j].n < a[mini].n ){
        mini = j;
      }
    }

    if( i != mini ){
      tempn = a[i].n;
      a[i].n = a[mini].n;
      a[mini].n = tempn;

      tempc = a[i].c;
      a[i].c = a[mini].c;
      a[mini].c = tempc;
    }

  }


}