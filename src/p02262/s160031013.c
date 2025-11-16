#include<stdio.h>
#include<stdlib.h>

int *InsertionSort(int *,int);
int kansuu(int);
int num, cnt=0;
  
int main(){
  int *data, *g, m=0, i;

  //input data
  scanf("%d",&num);
  data=(int *)malloc(sizeof(int)*num);
  for(i=0;i<num;i++) scanf("%d",&data[i]);


  //shell sort
  for(i=1;kansuu(i)<=num;i++) m++;
  g=(int *)malloc(sizeof(int)*m);
  for(i=1;i<=m;i++) g[m-i]=kansuu(i);
  
  //insertionsort
  for(i=0;i<m;i++) data=InsertionSort(data,g[i]);
  

  //output result
  printf("%d\n",m);
  for(i=0;i<m-1;i++) printf("%d ",g[i]);
  printf("%d\n%d\n",g[i],cnt);
  for(i=0;i<num;i++) printf("%d\n",data[i]);
  

  free(data);
  free(g);
  return 0;
}

int *InsertionSort(int *data,int g){
  int i, j, v;

  for(i=g;i<num;i++){
    v=data[i];
    j=i-g;
    while(j>=0 && data[j]>v){
      data[j+g]=data[j];
      j-=g;
      cnt++;
    }
    data[j+g]=v;
  }
  
  return data;
}

int kansuu(int i){
  int a, b=1;
  if(i==1) return 1;
  else{
    for(a=0;a<i-1;a++) b*=3;
    return kansuu(i-1)+b;
  } 
}


