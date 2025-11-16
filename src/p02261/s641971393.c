#include <stdio.h>

#define N 36 

typedef struct{
    char shape; 
    int  value;
}Data;

int main(){

  int i;
  int j;
  int n;
  int min;
  int judge=0;
  Data b_data[N];
  Data s_data[N];
  Data buf[N];
  Data tmp;


  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c%d",&buf[i].shape,&buf[i].value);
  }

  for(i=0;i<n;i++){
    s_data[i] = buf[i];
    b_data[i] = buf[i];
  }
  
  for(i=0;i<n-1;i++){
    for(j=n-1;j>=1;j--){
      if(b_data[j].value<b_data[j-1].value){
	tmp = b_data[j];
	b_data[j] = b_data[j-1];
	b_data[j-1] = tmp;
    }
   }
  }

  for(i=0;i<n-1;i++){
    min = i;
    for(j=i+1;j<n;j++){
      if(s_data[j].value<s_data[min].value){
	min = j;
      }
    }
      if(min!=i){
	tmp = s_data[i];
	s_data[i] = s_data[min];
	s_data[min] = tmp;
   }
  }

  for(i=0;i<n-1;i++){
    printf("%c%d ",b_data[i].shape,b_data[i].value);
  }
  printf("%c%d\n",b_data[i].shape,b_data[i].value);

  printf("Stable\n");
    
  for(i=0;i<n-1;i++){
    printf("%c%d ",s_data[i].shape,s_data[i].value);
  }
  printf("%c%d\n",s_data[i].shape,s_data[i].value);

  judge=0;
  
  for(i=0;i<n-1;i++){
    if(b_data[i].value == s_data[i].value && b_data[i].shape != s_data[i].shape){
    judge=1;
    break;
   }
  }
  
  if(judge==0) printf("Stable\n");
  else printf("Not stable\n");
    
  return 0;
}