#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char **data, **data2;//data=bubble data2=selection
  char sub[3];
  int num, i, j, flag=1 ,judge=0;

  //input data
  scanf("%d",&num);
  data=(char **)malloc(sizeof(char *)*num);
  data2=(char **)malloc(sizeof(char *)*num);
  for(i=0;i<num;i++){
    data[i]=(char *)malloc(sizeof(char)*3);
    data2[i]=(char *)malloc(sizeof(char)*3);
    scanf("%s",data[i]);
  }

  //copy data to data2
  for(i=0;i<num;i++){
    for(j=0;j<3;j++) data2[i][j]=data[i][j];
  }
  


  

  //bubble sort
  while(flag==1){//flag==1 sort is not finish
    flag=0;

    for(i=num-1;i>0;i--){
      if(data[i][1]<data[i-1][1]){
	//data[i][1]<->data[i-1][1]
	strcpy(sub,data[i]);
	strcpy(data[i],data[i-1]);
	strcpy(data[i-1],sub);

	flag=1;

	//same number change judge
	if(data[i][1]==data[i-1][1]) judge=1;
      }
      
    }
    
  }

  //output bubble sort result
  for(i=0;i<num-1;i++) printf("%s ",data[i]);
  printf("%s\n",data[i]);

  //output judge result
  if(judge==0) printf("Stable\n");//bubble sort is always stable sort
  else printf("Not stable\n");



  

 
  //selection sort
  for(i=0;i<num;i++){
    flag=i;

    for(j=i;j<num;j++) //search minimum data(=data2[flag])
      if(data2[j][1]<data2[flag][1]) flag=j;
	

    if(flag!=i){
      //data2[i][1]<->data2[flag][1]
      strcpy(sub,data2[i]);
      strcpy(data2[i],data2[flag]);
      strcpy(data2[flag],sub);
      
    }
    
  }

  //output selection sort result
  for(i=0;i<num-1;i++) printf("%s ",data2[i]);
  printf("%s\n",data2[i]);


  judge=0;//reflesh judge
  
  //judge stable sort(compair bubble sort result)
  for(i=0;i<num;i++){
    if(strcmp(data[i],data2[i])!=0) judge=1;
  }

  //output judge result
  if(judge==0) printf("Stable\n");//slection sort is not always stable sort
  else printf("Not stable\n");

  for(i=0;i<num;i++){
    free(data[i]);
    free(data2[i]);
  }
  free(data);
  free(data2);
  
  return 0;
}

