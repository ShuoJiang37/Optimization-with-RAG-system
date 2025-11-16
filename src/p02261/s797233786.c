#include<stdio.h>
#include<string.h>

#define MAX 36

int main(){

  int i, j, a, b, num, min, ans1, ans2;
  int temp[MAX];

  char oridata[MAX][3];
  char data1[MAX][3];
  char data2[MAX][3];

  ans1 = 0;
  ans2 = 0;

  scanf("%d", &num);

  for(i = 0; i < num; i++){

    scanf("%s", &oridata[i]);

    data1[i][0] = oridata[i][0];
    data1[i][1] = oridata[i][1];
    data1[i][2]='\0';
    data2[i][0] = oridata[i][0];
    data2[i][1] = oridata[i][1];
    data2[i][2]='\0';
  }

  for(i = 0; i < num - 1; i++){

    for(j = num - 1; j > i; j--){

      if(data1[j][1] < data1[j - 1][1]){
	
	temp[0] = data1[j - 1][0];
	temp[1] = data1[j - 1][1];

	data1[j - 1][0] =  data1[j][0];
	data1[j - 1][1] =  data1[j][1];

	data1[j][0] = temp[0];
	data1[j][1] = temp[1];
	
      }
	
    }

  }

  for(i = 0; i < num - 1; i++){

    min = i;

    for(j = i + 1; j < num; j++){

      if(data2[min][1] > data2[j][1]){
	
	min = j;
	
      }
	
    }


    if(data2[i][1] != data2[min][1]){

      temp[0] = data2[min][0];
      temp[1] = data2[min][1];

      data2[min][0] =  data2[i][0];
      data2[min][1] =  data2[i][1];

      data2[i][0] = temp[0];
      data2[i][1] = temp[1];

    }
     
  }



  for(i = 0; i < num; i++){

    for(j = i + 1; j < num; j++){

      for(a = 0; a < num; a++){

	for(b = a + 1; b < num; b++){

	  if(oridata[i][1] == oridata[j][1] && (strcmp(oridata[i],data1[b])==0) && (strcmp(oridata[j],data1[a])==0))
	    ans1 = 1;

	}	

      }

    }

  }

  for(i = 0; i < num; i++){

    for(j = i + 1; j < num; j++){

      for(a = 0; a < num; a++){

	for(b = a + 1; b < num; b++){

	  if(oridata[i][1] == oridata[j][1] && (strcmp(oridata[i],data2[b])==0) &&( strcmp(oridata[j],data2[a])==0)) 
	    ans2 = 1;

	}	

      }

    }

  }

  for(i = 0; i < num - 1; i++){

    printf("%c%c ", data1[i][0],data1[i][1]);

  }
   
  if(ans1 == 0)
    printf("%c%c\nStable\n", data1[i][0], data1[i][1]);
  else
    printf("%c%c\nNot stable\n", data1[i][0], data1[i][1]);


  for(i = 0; i < num - 1; i++){

    printf("%c%c ", data2[i][0],data2[i][1]);

  }

  if(ans2 == 0)
    printf("%c%c\nStable\n", data2[i][0], data2[i][1]);
  else
    printf("%c%c\nNot stable\n", data2[i][0], data2[i][1]);

  return 0;

}