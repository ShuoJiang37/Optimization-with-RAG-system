#include<stdio.h>
#include<string.h>
#define C 36

int number(char []);

main(){
  char barray[C][4],sarray[C][4],array[C][4],temp[4];
  int N,mini,flag=0;
  int i,j;
  
  scanf("%d",&N); /*given set of cards*/
  
  for(i=0; i<N; i++){
    scanf("%s",temp);  
    strcpy(barray[i],temp); 
    strcpy(sarray[i],temp);  
  }
  
  /*Bubble Sort */
  for(i=0; i<N; i++){
    for(j=N-1; j>i; j--){
      if(number(barray[j]) < number(barray[j-1])){
	strcpy(temp,barray[j]);
	strcpy(barray[j],barray[j-1]);
	strcpy(barray[j-1],temp);
      }
    }
  }
  
  for(i=0; i<N; i++){
    printf("%s",barray[i]);
    if(i < N-1)
      printf(" ");
  }
  printf("\n");
  printf("Stable\n");
  
  
  /*Selection Sort */
  for(i=0; i<N; i++){
    mini = i;
    for(j=i; j<N; j++){
      if(number(sarray[j])<number(sarray[mini]))
	mini = j; 
    } 
    strcpy(temp,sarray[i]);
    strcpy(sarray[i],sarray[mini]);
    strcpy(sarray[mini],temp);
  }
  
  for(i=0; i<N; i++){
    printf("%s",sarray[i]);
    if(i < N-1)
      printf(" ");
  }
  printf("\n");
  
  for(i=0; i<N; i++){
    if(strcmp(barray[i],sarray[i])){
      flag=1;
      printf("Not stable\n");      
      break;
    }
  }
    if(flag == 0)
    printf("Stable\n");

    return 0;
  
}

int number(char x[]){
  return x[1] - '0';
}