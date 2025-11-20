#include <stdio.h>

typedef struct{
  char M;
  int value;
}tc;

void BubbleSort(tc*, int);
void SelectionSort(tc*, int);
void isStable(tc*, tc*, int);

int main(){

  int i,j,n;
  tc g[36],s[36];

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf(" %c%d",&g[i].M, &g[i].value); 
    s[i] = g[i]; 
  }

  BubbleSort(g,n);
  SelectionSort(s,n);

  return 0;
}

void BubbleSort(tc* g,int n){
  int i,j;
  tc temp;
  tc in[n];

  for(i=0; i<n; i++){
    in[i] = g[i]; 
  }
  
  for(i = 0; i <= n-1; i++){
    for(j = n-1; j >= i+1; j--){
      if(g[j].value < g[j-1].value){
	temp = g[j];
	g[j] = g[j-1];
	g[j-1] = temp;
      }
    }
  }

  for(i=0; i<n; i++){
    printf("%c%d",g[i].M,g[i].value);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  isStable(in,g,n);
}

void SelectionSort(tc* s,int n){

  int i,j,minj;
  tc temp;
  tc in[n];

  for(i=0; i<n; i++){
    in[i] = s[i]; 
  }

  for(i = 0; i<= n-1; i++){
    minj = i;
    for(j = i;j <= n-1; j++){
      if(s[j].value < s[minj].value){
	minj = j;
      }
    }
    temp = s[i];
    s[i] =  s[minj];
    s[minj] = temp;
  }

  for(i=0; i<n; i++){
    printf("%c%d",s[i].M,s[i].value);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  isStable(in,s,n);
}

void isStable(tc* in,tc* out,int n){

  int i,j,a,b,flag=1;

  for(i=0; i<n-1; i++){
    for(j= i+1; j<n-1;j++){
      for(a=0; a<n-1; a++){
	for(b=a+1; b<n-1; b++){
	  if(in[i].value==in[j].value&&in[i].value==out[b].value&&in[j].value==out[a].value&&in[i].M==out[b].M&&in[j].M==out[a].M){
	    flag = 0;
	  }
	}
      }   
    }
  }
  if(flag==1){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
}