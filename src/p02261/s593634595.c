#include <stdio.h>
#include <string.h>

typedef struct{
  char a;
  int  num;
}data;

//バブルソートと比較し安定か安定じゃないか確かめる

int main(){
  data data[36],data1[36],data2[36],tmp_data;
  char temp[2];
  int i,j,n,minj,s=0,flag=0,flag2=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    //scanf(" %c %d",&data[i].a,&data[i].num);
    scanf("%s", temp);
    data[i].a = temp[0];
    data[i].num = temp[1] - 48;
    
    data1[i]=data[i];
    data2[i]=data[i];
  }

  //バブルソート
  for(i = 0 ; i < n; i++){
    for(j = n-1; j >= i + 1; j--){
      if(data1[j].num < data1[j-1].num){
	tmp_data = data1[j-1];
	data1[j-1] = data1[j];
	data1[j] = tmp_data;
	flag = 1;
      }
    }
  }
   
  for(i=0;i<n;i++){
    printf("%c%d",data1[i].a,data1[i].num);
    if(i!=n-1)printf(" ");
      }
  printf("\nStable\n");
  

  
  //セレクションソート
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(data2[j].num < data2[minj].num){
	minj = j;
      }
    }

    tmp_data = data2[i];
    data2[i] = data2[minj];
    data2[minj] = tmp_data;
  }

  for(i=0;i<n;i++){
    printf("%c%d",data2[i].a,data2[i].num);
    if(i!=n-1)printf(" ");
    if(data1[i].a!=data2[i].a)flag2=1;
  }
  printf("\n");
  if(flag2==0)printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

