#include <stdio.h>
void bubble_sort(int C[], int value[], int length) {
  int i,j,tmp;
  for(i = 1; i <= length; ++i) {
    for(j = length; j >= i+1; --j) {
      if(value[C[j]] < value[C[j-1]]) {
        tmp = C[j];
        C[j] = C[j-1];
        C[j-1] = tmp;
      }
    }
  }
}

void select_sort(int C[], int value[], int length) {
  int i,j,mini,tmp;
  for(i = 1; i <= length; ++i) {
    mini = i;
    for(j = i; j <= length; ++j) {
      if(value[C[j]] < value[C[mini]] ){
        mini = j;
      }
    }
    tmp = C[i];
    C[i] = C[mini];
    C[mini] = tmp;
  }
}

void show(int C[], int value[], char mark[], int length, int isStable) {
  int i;
  for(i = 1; i <= length; ++i) {
    if(i != 1) printf(" ");
    printf("%c%d", mark[C[i]], value[C[i]]);
  }
  printf("\n");
  printf("%s\n",isStable?"Stable":"Not stable");
}

int isStable(int C[], int D[], int value[], char mark[], int length) {
  int i,j,s,t;
  for(i = 1; i+1 <= length; ++i) {
    if(value[D[i]] == value[D[i+1]]) {
      for(j = 1; j <= length; ++j) {
        if(value[C[j]] == value[D[i]] && mark[C[j]] == mark[D[i]])
          s = C[j];
        if(value[C[j]] == value[D[i+1]] && mark[C[j]] == mark[D[i+1]])
          t = C[j];
      }
      if(s > t) return 0;
    }
  }
  return 1;
}

int main() {
  int length;
  int value[37];
  char mark[37];
  int C[37],C1[37],C2[37];
  int isS1, isS2;

  int i,j,k;

  scanf("%d", &length);
  for(i = 1; i <= length; ++i)
    scanf(" %c%d", &mark[i], &value[i]);
  for(i = 1; i <= length; ++i)
    C[i] = C1[i] = C2[i] = i;

  bubble_sort(C1,value,length);
  select_sort(C2,value,length);

  isS1 = isStable(C,C1,value,mark,length);
  isS2 = isStable(C,C2,value,mark,length);

  show(C1,value,mark,length,isS1);
  show(C2,value,mark,length,isS2);
  return 0;
}