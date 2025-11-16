#include <stdio.h>
#include <string.h>

int main(){
  int i,j,n,flag=1,min;
  char a[36][3],b[36][3],r1[3],r2[3];

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%s",a[i]);
    for(j=0; j<3; j++)
      b[i][j]=a[i][j];
  }

  /* Babble  */
  while(flag){
    flag=0;
    for(i=n-1; i>0; i--){
      if(a[i][1]<a[i-1][1]){
	strcpy(r1,a[i]);
	strcpy(a[i],a[i-1]);
	strcpy(a[i-1],r1);
 
	flag=1;
      }
    }
  }

    
  for(i=0; i<n-1; i++)
    printf("%s ",a[i]);
  
  printf("%s\n",a[i]);
  printf("Stable\n");

  
  /* Selection */
  for(i=0; i<n; i++){
    min = i;
    for(j=i; j<n; j++)
      if(b[j][1]<b[min][1])
	min = j;
    if(i!=min){
    strcpy(r2,b[i]);
    strcpy(b[i],b[min]);
    strcpy(b[min],r2);
    }
    
  }

  
  for(i=0; i<n-1; i++)
    printf("%s ",b[i]);
  
  printf("%s\n",b[i]);

  flag=0;
  for(i=0; i<n; i++)
    if(a[i][0]!=b[i][0])
      flag=1;
  
  if(flag==0)
     printf("Stable\n");
  else
     printf("Not stable\n");
    
  
  return 0;

}

