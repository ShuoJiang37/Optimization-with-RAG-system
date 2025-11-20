#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char a[36][2];
}roll;

int isStable(roll ,roll);
int N;

int main(){
  roll A, B, C;
  int i, j, hantei, minj;
  char a[36][2], tmp[1][2],g;

  scanf("%d",&N);
  if(N<0 || N>36) exit(1);

  for(i=0; i<N; i++) scanf(" %c%c",&A.a[i][0],&A.a[i][1]);
  for(i=0; i<N; i++){
    B.a[i][0] = A.a[i][0];
    B.a[i][1] = A.a[i][1];
  }
  for(i=0; i<N; i++){
    C.a[i][0] = A.a[i][0];
    C.a[i][1] = A.a[i][1];
  }

  //bubble sort
  for(i=0; i<N-1; i++){
    for(j=N-1; j>=i+1; j--){
      if(B.a[j][1] < B.a[j-1][1]){
	tmp[0][0] = B.a[j][0];
	tmp[0][1] = B.a[j][1];
	B.a[j][0] = B.a[j-1][0];
	B.a[j][1] = B.a[j-1][1];
	B.a[j-1][0] = tmp[0][0];
	B.a[j-1][1] = tmp[0][1];
      }
    }
  }
  hantei = isStable(A,B);
  for(i=0; i<N-1; i++) printf("%c%c ",B.a[i][0],B.a[i][1]);
  printf("%c%c",B.a[N-1][0],B.a[N-1][1]);
  if(hantei == 1) printf("\nStable\n");
  else printf("\nNot stable\n");

  //selection sort
  for(i=0; i<N-1; i++){
    minj = i;
    for(j=i; j<=N-1; j++){
      if(C.a[j][1] < C.a[minj][1]) minj = j;
    }
    tmp[0][0] = C.a[minj][0];
    tmp[0][1] = C.a[minj][1];
    C.a[minj][0] = C.a[i][0];
    C.a[minj][1] = C.a[i][1];
    C.a[i][0] = tmp[0][0];
    C.a[i][1] = tmp[0][1];
  }
  hantei = isStable(A,C);
  for(i=0; i<N-1; i++) printf("%c%c ",C.a[i][0],C.a[i][1]);
  printf("%c%c",C.a[N-1][0],C.a[N-1][1]);
  if(hantei == 1) printf("\nStable\n");
  else printf("\nNot stable\n");

  return 0;
}

int isStable(roll A, roll B) {
  int i, j, c, d;

  for(i=0; i<N-1; i++){
    for(j=i+1; j<N; j++){
      if(A.a[i][1] == A.a[j][1]){
	for(c=0; c<N; c++) if(A.a[i][0] == B.a[c][0] && A.a[i][1] == B.a[c][1]) break;
	for(d=0; d<N; d++) if(A.a[j][0] == B.a[d][0] && A.a[j][1] == B.a[d][1]) break;
	if(c<d) continue;
	else return 0;
      }
    }
  }
  return 1;
}

