#include <stdio.h>
#include <string.h>
#define N 36
int judge(char x[N][2],char y[N][2],int n);
int main(){
  int i, j, n, min,k;
  char a[N][2],b[N][2],c[N][2],change[3];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%s",a[i]);

  

  for(i=0;i<n;i++){ 
    for(j=i+1;j<n;j++){
   
    }
  }
  for(i=0;i<n;i++){
    strncpy(b[i],a[i],2);
    strncpy(c[i],a[i],2);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(b[j][1]<b[j-1][1]){
	  strncpy(change,b[j],2);
	  strncpy(b[j],b[j-1],2);
	  strncpy(b[j-1],change,2);
      }
    }
  }
  for(i=0;i<n;i++){
    if(i<n-1)printf("%c%c ",b[i][0],b[i][1]);
    else printf("%c%c\n",b[i][0],b[i][1]);
  }
		
 
  if(judge(&a[0],&b[0],n)==0)printf("Stable\n");
  else printf("Not stable\n");
  
  
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(c[j][1]<c[min][1])
	min=j;
	
      
    }
     if(min==i)continue; 
  strncpy(change,c[i],2);
  
  strncpy(c[i],c[min],2);

  strncpy(c[min],change,2);

  
  
  }
  
  for(k=0;k<n;k++){
    if(k<n-1)printf("%c%c ",c[k][0],c[k][1]);
    else printf("%c%c\n",c[k][0],c[k][1]);
  }
 if(judge(&a[0],&c[0],n)==0)printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;
}
int judge(char x[N][2],char y[N][2],int n){
  int i, j, a, b;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if(x[i][1]==x[j][1] && x[i][1]==y[b][1] && x[j][1]==y[a][1] && x[i][0]==y[b][0] && x[j][0]==y[a][0])
	    return 1;
	}
      }
    }
  }
  return 0;
}