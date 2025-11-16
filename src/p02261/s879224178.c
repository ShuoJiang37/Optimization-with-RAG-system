#include <stdio.h>

void Bubble();
void Select();
int isStable();
void printresult();

char C[36][2], out[36][2];
int n;

int main(){
  int i;

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%s",&C[i][0]);

  Bubble();
  Select();

  return 0;
}

void Bubble(){
  int i, j;
  char temp;
  
  for(i = 0; i < n; i++){
    out[i][0] = C[i][0];
    out[i][1] = C[i][1];
  }
  
  for(i = 0; i < n; i++){
    for(j = n-1; j > i; j--){
      if(out[j][1] < out[j-1][1]){
	temp = out[j][0];
	out[j][0] = out[j-1][0];
	out[j-1][0] = temp;

	temp = out[j][1];
	out[j][1] = out[j-1][1];
	out[j-1][1] = temp;
      }
    }
  }

  printresult();
}

void Select(){
  int i, j, minj;
  char temp;

  for(i = 0; i < n; i++){
    out[i][0] = C[i][0];
    out[i][1] = C[i][1];
  }
  
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(out[j][1] < out[minj][1]){
        minj = j;
      }
    }

    temp = out[i][0];
    out[i][0] = out[minj][0];
    out[minj][0] = temp;

    temp = out[i][1];
    out[i][1] = out[minj][1];
    out[minj][1] = temp;
  }

  printresult();
}
      

int isStable(){
  int i, j, a, b;
  
  for(i = 0; i < n; i++){
    for(j = i+1; j < n; j++){
      for(a = 0; a < n; a++){
	for(b = a+1; b < n; b++){
	  if(C[i][1] == C[j][1] &&
	     C[i][1] == out[b][1] && C[i][0] == out[b][0] &&
	     C[j][1] == out[a][1] && C[j][0] == out[a][0]) return 0;
	}
      }
    }
  }

  return 1;
}

void printresult(){
  int i;
  
  for(i = 0; i < n-1; i++){
    printf("%c%c ",out[i][0],out[i][1]);
  }
  printf("%c%c\n",out[i][0],out[i][1]);
  
  if(isStable() == 1) printf("Stable\n");
  else printf("Not stable\n");
}
