#include <stdio.h>
#include <string.h>

#define MAX 36

int main(){
  char a[MAX][3],b[MAX][3],str[3];
  int n,i,j,c[MAX],d[MAX],tmp,mini,ok = 1;

  scanf("%d" ,&n);
  for(i = 0 ; i < n ; i++){
    scanf("%s" ,a[i]);
    strcpy(b[i],a[i]);
    c[i] = d[i] = a[i][1]-'0';
  }

  for(i = 0 ; i < n ; i++){
    for(j = n-1 ; j > i ; j--){
      if(c[j] < c[j-1]){
	tmp = c[j];
	c[j] = c[j-1];
	c[j-1] = tmp;

	strcpy(str,a[j]);
	strcpy(a[j],a[j-1]);
	strcpy(a[j-1],str);
      }
    }
  }  

  for(i = 0 ; i < n ; i++){
    if(i != n-1){
      printf("%s " ,a[i]);
    }else{
      printf("%s\n" ,a[i]);
      puts("Stable");
    }
  }

  for(i = 0 ; i < n-1 ; i++){
    mini = i;
    for(j = i+1 ; j < n ; j++){
      if(d[j] < d[mini]){
	mini = j;
      }
    }
    
    if(mini != i){
      tmp = d[i];
      d[i] = d[mini];
      d[mini] = tmp;

      strcpy(str,b[i]);
      strcpy(b[i],b[mini]);
      strcpy(b[mini],str);
    }
  }

  for(i = 0 ; i < n ; i++){
    if(strcmp(a[i],b[i])){
      ok = 0;
    }
    if(i != n-1){
      printf("%s " ,b[i]);
    }else{
      printf("%s\n" ,b[i]);
    }
  }

  if(ok){
    puts("Stable");
  }else{
    puts("Not stable");
  }

  return 0;
}