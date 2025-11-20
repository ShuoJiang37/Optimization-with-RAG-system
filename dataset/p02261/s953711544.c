#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int v;
  char m;
}C;

C in[36],b[36],s[36];

void bubblesort(int);
void selectionsort(int);
int isstable(C*,int);

int main(){
  int n,i;
  char temp[4];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%s",temp);
    in[i].m = b[i].m = s[i].m = temp[0];
    in[i].v = b[i].v = s[i].v = atoi(temp+1);
  }

  bubblesort(n);
  selectionsort(n);

  for(i = 0; i < n; i++){
    printf("%c%d",b[i].m,b[i].v);
    if(i != n-1) printf(" ");
  }
  printf("\n");
  if(isstable(b,n) == 1) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0; i < n; i++){
    printf("%c%d",s[i].m,s[i].v);
    if(i != n-1) printf(" ");
  }
  printf("\n");
  if(isstable(s,n) == 1) printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;

}

void  bubblesort(int n){
  int i,j;
  C temp;

  for(i = 0; i < n; i++){
    for(j = n-1; j > i; j--){
      if(b[j].v < b[j-1].v){
	temp = b[j];
	b[j] = b[j-1];
	b[j-1] = temp;
      }
    }
  }
}

void selectionsort(int n){
  int i,j,minj;
  C temp;
  
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(s[j].v < s[minj].v)
	minj = j;
    }
    temp = s[i];
    s[i] = s[minj];
    s[minj] = temp;
  }
}

int isstable(C *out,int n){
  int i,j,a,b;

  for(i = 0; i < n; i++){
    for(j = i+1; j < n; j++){
      for(a = 0; a < n; a++){
	for(b = a+1; b < n-1; b++)
	  if(in[i].v == in[j].v){
	    if(in[i].v == out[b].v && in[i].m == out[b].m &&
	       in[j].v == out[a].v && in[j].m == out[a].m)
	      return 0;
	  }
      }
    }
  }
  return 1;
}

