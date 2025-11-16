#include <stdio.h>

int mark2num(char c) {
  if(c == 'S') return 0;
  if(c == 'H') return 1;
  if(c == 'C') return 2;
  if(c == 'D') return 3;
  return -1;
}

int num2mark(int num) {
  if(num == 0) return 'S';
  if(num == 1) return 'H';
  if(num == 2) return 'C';
  if(num == 3) return 'D';
  return 'Z';
}

void Out(int C[], int N) {
  int i;
  for(i = 0; i < N; i++) {
    if(i) printf(" ");
    printf("%c%d", num2mark(C[i]/9), C[i]%9+1);
  }
  puts("");
}

int B[55];

void BubbleSort(int A[], int N) {
  int C[55], tmp;
  int i, j;
  for(i = 0; i < N; i++) C[i] = A[i];
  for(i = 0; i < N-1; i++){
    for(j = N-1; j > i; j--) {
      if(C[j]%9 < C[j-1]%9) {
	tmp = C[j];
	C[j] = C[j-1];
	C[j-1] = tmp;
      }
    }
  }  
  Out(C, N);
  puts("Stable");
  for(i = 0; i < N; i++) B[i] = C[i];
}

void SelectionSort(int A[], int N) {
  int C[55], tmp, mni;
  int i, j;
  for(i = 0; i < N; i++) C[i] = A[i];
  for(i = 0; i < N; i++) {
    mni = i;
    for(j = i; j < N; j++) {
      if(C[j]%9 < C[mni]%9) mni = j;
    }
    if(mni != i) {
      tmp = C[i];
      C[i] = C[mni];
      C[mni] = tmp;
    }
  }
  Out(C, N);
  for(i = 0; i < N; i++) {
    if(C[i] != B[i]) {
      puts("Not stable");
      return;
    }
  }
  puts("Stable");
}

int main() {
  int N, A[55];
  int i;
  char c[3];
  scanf("%d", &N);
  for(i = 0; i < N; i++) {
    scanf("%s", c);    
    A[i] = mark2num(c[0]) * 9 + (c[1]-'0')-1;
  }
  BubbleSort(A, N);
  SelectionSort(A, N);
  return 0;
}