#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 36

struct Data{
  int num;
  char moji[3];
};
  
int main(){
  int n,i,j,min,k;
  struct Data date[N],change,date2[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",date[i].moji);
    date[i].num = atoi(&date[i].moji[1]);
    date2[i] = date[i];
  }

  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {
      if ( date[j - 1].num > date[j].num ) {  
	change = date[j];
	date[j] = date[j-1];
	date[j-1] = change;
      }
    }
  }

   for (i = 0; i < n - 1; i++) {
        min = date2[i].num;                 
        k = i;                       
        for (j = i + 1; j < n; j++) {
            if (date2[j].num < min) {       
                min = date2[j].num;        
                k = j;               
            }
        }                            
	change = date2[i];
	date2[i] = date2[k];
	date2[k] = change;
   }


  for(i=0;i<n-1;i++){
    printf("%s ",date[i].moji);
  }
  printf("%s\nStable\n",date[i].moji);

  k = 0;
  for(i=0;i<n-1;i++){
    if( strcmp( date[i].moji,date2[i].moji ) != 0 ) k = 1;
    printf("%s ",date2[i].moji);
  }
  if( strcmp( date[n-1].moji,date2[n-1].moji ) != 0 ) k = 1;
  if( k == 0 ) printf("%s\nStable\n",date2[i].moji);
  else printf("%s\nNot stable\n",date2[i].moji);
  return 0;
}