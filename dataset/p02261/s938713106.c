#include<stdio.h>
#include<string.h>

typedef struct{
  char pic;
  int num;
  int id;
}trnp;

void bubble_sort(int , trnp []);
void selection_sort(int , trnp []);

int main(void){
  int n;
  trnp a[36], b[36];
  int i;

  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    scanf(" %c%d", &a[i].pic, &a[i].num);
    a[i].id = i;
    b[i] = a[i];
  }

  bubble_sort(n, a);
  selection_sort(n, b);

	return 0;
}

void bubble_sort(int n, trnp x[]){
  int i, j, stable;
  trnp y;
  for(j = 0; j < n -1; j++){
    for(i = n-1; i > j; i--){
      if(x[i].num < x[i - 1].num){
        y = x[i];
        x[i] = x[i - 1];
        x[i - 1] = y;
      }
    }
  }
  stable = 1;
  for(i = 0; i < n; ++i) {
    printf("%c%d%c", x[i].pic, x[i].num, " \n"[i==n-1]);
    if(i > 0 && x[i].num == x[i-1].num && x[i].id < x[i-1].id) stable = 0;
  }
  puts((stable ? "Stable" : "Not stable"));
}

void selection_sort(int n, trnp x[]){
  int i, j, min, stable;
  trnp y;

  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(x[j].num < x[min].num){
        min = j;
      }
    }
    if(i != min){
      y = x[i];
      x[i] = x[min];
      x[min] = y;
    }
  }
  stable = 1;
  for(i = 0; i < n; ++i) {
    printf("%c%d%c", x[i].pic, x[i].num, " \n"[i==n-1]);
    if(i > 0 && x[i].num == x[i-1].num && x[i].id < x[i-1].id) stable = 0;
  }
  puts((stable ? "Stable" : "Not stable"));
}

