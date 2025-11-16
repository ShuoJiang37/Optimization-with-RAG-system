#include<stdio.h>
#include<string.h>

int main(){
  char arrayA[36][3];
  char arrayB[36][3];
  char str[3];

  int i,num,j,tmp,min,ans = 1;
  int arrayC[36];
  int arrayD[36];

  scanf("%d",&num);
  for(i = 0;i < num;i++){
    scanf("%s",arrayA[i]);
    strcpy(arrayB[i],arrayA[i]);
    arrayC[i] = arrayD[i] = arrayA[i][1] - '0';
  }

  for(i = 0;i < num;i++){
    for(j = num - 1;j > i;j--){
      if(arrayC[j] < arrayC[j - 1]){
        tmp = arrayC[j];
        arrayC[j] = arrayC[j - 1];
        arrayC[j - 1] = tmp;

        strcpy(str,arrayA[j]);
        strcpy(arrayA[j],arrayA[j - 1]);
        strcpy(arrayA[j - 1],str);
      }
    }
  }

  for(i = 0;i < num;i++){
    if(i != num - 1){
      printf("%s ",arrayA[i]);
    }
    else{
      printf("%s\n",arrayA[i]);
      puts("Stable");
    }
  }

  for(i = 0;i < num - 1;i++){
    min = i;
    for(j = i + 1;j < num;j++){
      if(arrayD[j] < arrayD[min]){
        min = j;
      }
    }
    if(min != i){
      tmp = arrayD[i];
      arrayD[i] = arrayD[min];
      arrayD[min] = tmp;

      strcpy(str,arrayB[i]);
      strcpy(arrayB[i],arrayB[min]);
      strcpy(arrayB[min],str);
     }
  }

  for(i = 0;i < num;i++){
    if(strcmp(arrayA[i],arrayB[i])){
      ans = 0;
    }
    if(i != num - 1){
      printf("%s ",arrayB[i]);
    }
    else{
      printf("%s\n",arrayB[i]);
    }
  }

  if(ans){
    puts("Stable");
  }
  else{
    puts("Not stable");
  }
  return 0;
}

