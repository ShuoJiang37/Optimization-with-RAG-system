#include<stdio.h>
#define N 36

typedef struct{
  char mark;
  int num;
}Trump;
  

int isStable(Trump*,Trump*,int);

int main(){
  Trump C[N],C2[N];
  char y;
  int n,i,j,minj,x,f=0;
 
  scanf("%d",&n);
  if(n<1 || n>36) return 0;
  
  for(i=0 ; i<n ; i++){
    scanf(" %c%d",&C[i].mark,&C[i].num);
    C2[i] = C[i];
   
  }

  
  /*BubbleSort*/
  for(i=0 ; i<=n-1 ; i++){
    for(j=n-1 ; j>=i+1 ; j--){
      if(C[j].num < C[j-1].num){
	x = C[j].num;
	C[j].num = C[j-1].num;
	C[j-1].num = x;
	y = C[j].mark;
	C[j].mark = C[j-1].mark;
	C[j-1].mark = y;		
      }
    }
  }
  
  for(i=0 ; i<n ; i++){
    if(i == n-1)  printf("%c%d\n",C[i].mark,C[i].num);
    else printf("%c%d ",C[i].mark,C[i].num);
  }
  printf("Stable\n");
  
  /*SelectionSort*/
  for(i=0 ; i<=n-1 ; i++){
    minj = i;
    for(j=i+1 ; j<=n-1 ; j++){
      if(C2[j].num < C2[minj].num){
	minj = j;
	f = 1;
      }
    }
    if(f == 1){
      x = C2[i].num;
	C2[i].num = C2[minj].num;
	C2[minj].num = x;
	y = C2[i].mark;
	C2[i].mark = C2[minj].mark;
	C2[minj].mark = y;
      
  }
    f = 0;
  }
    
  for(i=0 ; i<=n-1 ; i++){
    printf("%c%d",C2[i].mark,C2[i].num);
    if(i < n-1) printf(" ");
  }
  printf("\n");

  

for(i = 0; i < n; i++){
      if(C[i].mark == C2[i].mark) continue;
      else{
      f = 1;
      break;
    }
    }
  if(f == 0) printf("Stable\n");
  else printf("Not stable\n");

  
 
  
  return 0;
}




