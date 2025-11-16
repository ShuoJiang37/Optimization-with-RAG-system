#include <stdio.h>
#include <string.h>
int main(){
  char a[36][3],b[36][3],x[3];
  int n,i,j,c[36],d[36],t,min,o=1;
  
  scanf("%d",&n);
  for(i =0;i<n;i++){
    scanf("%s",a[i]);
    strcpy(b[i],a[i]);
    c[i]=d[i]=a[i][1]-'0';
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(c[j]<c[j-1]){
    t=c[j];
    c[j]=c[j-1];
    c[j-1]=t;
    strcpy(x,a[j]);
    strcpy(a[j],a[j-1]);
    strcpy(a[j-1],x);
      }
    }
  }  
  for(i=0;i<n;i++){
    if(i!=n-1){
      printf("%s ",a[i]);
    }else{
      printf("%s\n",a[i]);
      puts("Stable");
    }
  }
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(d[j]<d[min]){
    min=j;
      }
    }   
    if(min!=i){
      t=d[i];
      d[i]=d[min];
      d[min]=t;
      strcpy(x,b[i]);
      strcpy(b[i],b[min]);
      strcpy(b[min],x);
    }
  }
  for(i=0;i<n;i++){
    if(strcmp(a[i],b[i])){
      o=0;
    }
    if(i!=n-1){
      printf("%s ",b[i]);
    }else{
      printf("%s\n",b[i]);
    }
  }
  if(o){
    puts("Stable");
  }else{
    puts("Not stable");
  }
  return 0;
}

