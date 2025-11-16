#include <stdio.h>
#include <string.h>
#define N 36

struct Toramp{
  char c;
  char num;
};

int c1n[N], c2n[N];
struct Toramp C1[N], C2[N];

void Bubble(int n){
  int i, j, k;
  char x, y;
  for(i = 0; i <= n-1; i++){
    for(j = n-1; j >= i+1; j--){
      if(c1n[j] < c1n[j-1]){
        x = C1[j].c;
	y = C1[j].num;
	k = c1n[j];
	C1[j].c = C1[j-1].c;
	C1[j].num = C1[j-1].num;
	c1n[j] = c1n[j-1];
	C1[j-1].c = x;
	C1[j-1].num = y;
	c1n[j-1] = k;
      }
    }
  }
}

void SelectionSort(int n){
  int i, j, minj, k;
  char x, y;
  for(i = 0; i <= n-1; i++){
    minj = i;
    for(j = i; j <= n-1; j++){
      if(c2n[j] < c2n[minj]){
	minj = j;
      }
    }
    x = C2[i].c;
    y = C2[i].num;
    k = c2n[i];
    C2[i].c = C2[minj].c;
    C2[i].num = C2[minj].num;
    c2n[i] = c2n[minj];
    C2[minj].c = x;
    C2[minj].num = y;
    c2n[minj] = k;
  }
}

int isStable(int n){
  int i;
  for(i = 0; i < n; i++){
    if(C1[i].c != C2[i].c){
      return 0;
    }
  }
  return 1;
}

int numHenkan(char ccc){
  if(ccc == '0'){
    return 0;
  }else if(ccc == '1'){
    return 1;
  }else if(ccc == '2'){
    return 2;
  }else if(ccc == '3'){
    return 3;
  }else if(ccc == '4'){
    return 4;
  }else if(ccc == '5'){
    return 5;
  }else if(ccc == '6'){
    return 6;
  }else if(ccc == '7'){
    return 7;
  }else if(ccc == '8'){
    return 8;
  }else if(ccc == '9'){
    return 9;
  }
}

int main(){
  int i, n, k;
  char cc[3];
  
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%s", cc);
    C1[i].c = cc[0];
    C1[i].num = cc[1];
  }
  
  for(i = 0; i < n; i++){
    C2[i].c = C1[i].c;
    C2[i].num = C1[i].num;
    c1n[i] = numHenkan(C1[i].num);
    c2n[i] = c1n[i];
  }
  
  Bubble(n);
  SelectionSort(n);
  
  printf("%c%c", C1[0].c, C1[0].num);
  for(k = 1; k < n; k++){
    printf(" %c%c", C1[k].c, C1[k].num);
  }
  printf("\n");
  printf("Stable\n");
  
  printf("%c%c", C2[0].c, C2[0].num);
  for(k = 1; k < n; k++){
    printf(" %c%c", C2[k].c, C2[k].num);
  }
  printf("\n");
  if(isStable(n) == 1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
  
  return 0;
}

