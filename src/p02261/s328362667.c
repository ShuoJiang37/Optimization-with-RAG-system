#include <stdio.h>
#include <string.h>
#define N 36
int isStable(char in[N][2],char out[N][2],int n){
  int i,j,a,b;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if(in[i][1]==in[j][1] && in[i][0]==out[b][0] && in[j][0] == out[a][0] && in[i][1]==out[b][1] && in[j][1] == out[a][1]){
	    return 0;
	  }
	}
      }
    }
  }
  return 1;
}
int main(){
  int i,n,j,min;
  char a[N][2],b[N][2],c[N][2],d[3]; 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",a[i]);
    strncpy(b[i],a[i],2);
    strncpy(c[i],a[i],2);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(b[j][1] <b[j-1][1]){    
    strncpy(d,b[j],2);
    strncpy(b[j],b[j-1],2);
    strncpy(b[j-1],d,2);
      }
    }
  }
  for(i=0;i<n;i++){
    if(i<n-1) printf("%c%c ",b[i][0],b[i][1]);
    else printf("%c%c\n",b[i][0],b[i][1]);
  }
  if(isStable(&a[0],&b[0],n)==0) printf("Not stable\n");
  else printf("Stable\n");
     for(i=0;i<n;i++){
      min=i; 
      for(j=i;j<n;j++){
    if(c[j][1]<c[min][1]) min=j;
      }
      if(i==min) continue;
       strncpy(d,c[i],2);
       strncpy(c[i],c[min],2);
       strncpy(c[min],d,2);
      }
    for(i=0;i<n;i++){
      if(i<n-1) printf("%c%c ",c[i][0],c[i][1]);
      else printf("%c%c\n",c[i][0],c[i][1]);
    }
    if(isStable(&a[0],&c[0],n)==0) printf("Not stable\n");
    else printf("Stable\n");
    return 0;
}