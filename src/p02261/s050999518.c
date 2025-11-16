#include<stdio.h>
#include<string.h>
#define N 36
int main(){

  int i,j,n,min,flag=0;
  int swap,N1[N],N2[N];
  char tmp,data1[N][2],data2[N][2];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    N1[i]=i;
    scanf("%s",&data1[i]);
  }
  for(i=0;i<n;i++){
    N2[i]=i;
    strcpy(data2[i],data1[i]);
  }
  
  /*Bubble sort*/
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(data1[j][1]-'0'<data1[j-1][1]-'0'){
	tmp=data1[j][1];
	data1[j][1]=data1[j-1][1];
	data1[j-1][1]=tmp;
	tmp=data1[j][0];
	data1[j][0]=data1[j-1][0];
	data1[j-1][0]=tmp;
	swap=N1[j];
	N1[j]=N1[j-1];
	N1[j-1]=swap;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%c%c\n",data1[i][0],data1[i][1]);
    }
    else{
      printf("%c%c ",data1[i][0],data1[i][1]);
    }
  }
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(data1[i][1]==data1[j][1] && N1[i]>N1[j]){
	flag=1;
	break;
      }
    }
    if(flag==1) break;
  }
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");
  flag=0;
  
  /*Selection sort*/
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(data2[j][1]-'0'<data2[min][1]-'0'){
	min=j;
      }
    }
    tmp=data2[i][1];
    data2[i][1]=data2[min][1];
    data2[min][1]=tmp;
    tmp=data2[i][0];
    data2[i][0]=data2[min][0];
    data2[min][0]=tmp;
    swap=N2[i];
    N2[i]=N2[min];
    N2[min]=swap;
  }
  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%c%c\n",data2[i][0],data2[i][1]);
    }
    else{
      printf("%c%c ",data2[i][0],data2[i][1]);
    }
  }
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(data2[i][1]==data2[j][1] && N2[i]>N2[j]){
	flag=1;
	break;
      }
    }
    if(flag==1) break;
  }
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}

