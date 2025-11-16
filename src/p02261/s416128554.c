#include <stdio.h>

typedef struct {
  char pic;
  int value;
} trump;

int main(){

  int i,j,a,b,n,minj,flag_buble=1,flag_select=1;
  trump c[36],buble[36],select[36],tmp;
  
  //in
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    while(1){
      scanf("%c",&c[i].pic);
      if(c[i].pic != 'D' && c[i].pic != 'C' && c[i].pic != 'S' && c[i].pic != 'H') 
	continue;
      scanf("%d",&c[i].value);
      break;
    }
  }
  
  //copy
  for(i=0;i<n;i++){
    buble[i] = c[i];
    select[i] = c[i];
  }
  //bublesort
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(buble[j].value < buble[j-1].value){
	tmp = buble[j-1];
	buble[j-1] = buble[j];
	buble[j] = tmp;
      }
    }
  }

  //SelectionSort
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(select[j].value<select[minj].value) minj=j;
    }
    //swap
    if(i!=minj){
      tmp = select[i];
      select[i] = select[minj];
      select[minj] = tmp;
    } 
  }

  //compare
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if(c[i].value==c[j].value && c[i].value==buble[b].value 
	     && c[i].pic==buble[b].pic && c[j].value==buble[a].value 
	     && c[j].pic==buble[a].pic) flag_buble=0;
	  
	  if(c[i].value==c[j].value && c[i].value==select[b].value 
	     &&c[i].pic==select[b].pic && c[j].value==select[a].value 
	     && c[j].pic==select[a].pic) flag_select=0;
	}
      }
    } 
  }
  
  //out
  for(i=0;i<n;i++){
    
    if(i!=0) printf(" ");
    printf("%c%d",buble[i].pic,buble[i].value);
  }
  if(flag_buble==1) printf("\nStable\n");
  else printf("\nNot stable\n");

  for(i=0;i<n;i++){
    
    if(i!=0) printf(" ");
    printf("%c%d",select[i].pic,select[i].value);
  }
  if(flag_select==1) printf("\nStable\n");
  else printf("\nNot stable\n");

  return 0;

}