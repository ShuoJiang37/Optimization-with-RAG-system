#include<stdio.h>
#include<string.h>
#define N 36
void BubbleSort(int, char [][3]);
void SelectionSort(int, char [][3]);
int isStable(char [][3], char [][3],int);

int main(){
  int i,j,n;
  char array[N][3],arrayB[N][3],arrayS[N][3];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",arrayB[i]);
    strcpy(arrayS[i],arrayB[i]);
    strcpy(array[i],arrayB[i]);
  }
  BubbleSort(n, arrayB);
  if( isStable(array,arrayB,n) ){
    printf("Stable\n");
  }
  else {
    printf("Not Stable\n");
  }
  SelectionSort(n, arrayS);
  if( isStable(array,arrayS,n) ){
    printf("Stable\n");
  }
  else {
    printf("Not stable\n");
  }

  return 0;
}

void BubbleSort(int n,char array[n][3]){
  int i,j,flag;
  char buf[3];
  flag = 1;
  while(flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if( (int)array[j-1][1] > (int)array[j][1]){
	strcpy(buf,array[j-1]);
	strcpy(array[j-1],array[j]);
	strcpy(array[j],buf);
	flag = 1;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%s ",array[i]);
  }
  printf("%s\n",array[i]);
  return;
}
void SelectionSort(int n,char array[n][3]){
  int i,j,mini;
  char buf[3];

  for(i=0;i<n;i++){
    mini = i;
    for(j=i;j<n;j++){
      if( (int)array[mini][1] > (int)array[j][1] ){
	mini = j;
      }
    }
    strcpy(buf,array[i]);
    strcpy(array[i],array[mini]);
    strcpy(array[mini],buf);
  }
  for(i=0;i<n-1;i++){
    printf("%s ",array[i]);
  }
  printf("%s\n",array[i]);
     
  return;
}
int isStable(char in[][3],char out[][3],int n){
  int i,j,a,b;

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if( ((int)in[i][1] == (int)in[j][1] )&&
	      (!strcmp(in[i],out[b]))&&
	      (!strcmp(in[j],out[a]))){
	    return 0;
	  }
	}
      }
    }
  }
  return 1;
}