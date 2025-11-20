#include<stdio.h>
#include<string.h>

int main() {
  int x,i,j,min,flag;
  char c[36][3],t[3],d[36][3];

  scanf("%d",&x);
  for(i = 0; i < x; i++) {
    scanf("%s",c[i]);
    strcpy(d[i],c[i]);
  }
  
  for(i = 0; i < x; i++) {
    for(j = x - 1; j >= i + 1; j--) {
      if((c[j][1] - '0') < (c[j - 1][1] - '0')) {
	strcpy(t,c[j]);
	strcpy(c[j],c[j - 1]);
	strcpy(c[j - 1],t);
      }
    }
  }

  for(i = 0; i < x - 1; i++) {
    printf("%s ",c[i]);
  }
  printf("%s\n",c[i]);
  printf("Stable\n");

  for(i = 0; i < x; i++) {
    min = i;
    for(j = i; j < x; j++) {
      if((d[j][1] - '0') < (d[min][1] - '0')) {
	min = j;
      }
    }
    strcpy(t,d[i]);
    strcpy(d[i],d[min]);
    strcpy(d[min],t);
  }

  for(i = 0; i < x - 1; i++) {
    printf("%s ",d[i]);
  }
  printf("%s\n",d[i]);
  flag = 1;

   for(i = 0; i < x; i++) {
     if(strcmp(c[i],d[i]) != 0) {
       flag = 0;
     }
   }

   if(flag) {
     printf("Stable\n");
   }else{
     printf("Not stable\n");
   }

   return 0;
}
   
  
  

