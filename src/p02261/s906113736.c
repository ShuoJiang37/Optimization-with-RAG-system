#include<stdio.h>

void BubbleSort(int );
void SelectionSort(int);

struct card{

  char character;   

  int  number;

};


struct card inputdata[100];
struct card inputdata2[100];
struct card temp;

int main(){

  int sumcard,i,j,flag;

  flag = 0;

  scanf("%d",&sumcard);

  for(i = 0; i < sumcard; i++){

    scanf("%c%c%d",&inputdata[i].character,&inputdata[i].character,&inputdata[i].number);
    // scanf("%c",&inputdata[i].number[0]);

    inputdata2[i].character = inputdata[i].character;
    inputdata2[i].number = inputdata[i].number;

  }

  /* printf("\n");

  for(i = 0; i < sumcard; i++){

    printf("%c %d\n",inputdata[i].character,inputdata[i].number);

    }*/

  //  printf("test\n");
  BubbleSort(sumcard);

  for(i = 0; i < sumcard-1; i++){

    printf("%c%d ",inputdata[i].character,inputdata[i].number);

  }

  printf("%c%d\n",inputdata[i].character,inputdata[i].number);


  printf("Stable\n");

  
  SelectionSort(sumcard);

  for(i = 0; i < sumcard -1; i++){

    printf("%c%d ",inputdata2[i].character,inputdata2[i].number);

  }

  printf("%c%d\n",inputdata2[i].character,inputdata2[i].number);

  for(i = 0; i < sumcard; i++){

    if(inputdata[i].character != inputdata2[i].character){

      flag = 1;

      break;

    }

  }

  if(flag == 0){

    printf("Stable\n");

  }

  else{

    printf("Not stable\n");

  }


  return 0;

}

void BubbleSort(int sumcard){

  int i,x,j;


  for(i = 0; i < sumcard ; i++){

    for(j = sumcard-1; j >= i+1; j--){

      if(inputdata[j].number < inputdata[j-1].number){

	temp = inputdata[j];

	inputdata[j] = inputdata[j-1];
	inputdata[j-1] = temp;



      }
    }

  }
}

void SelectionSort(int sumcard){

  int i,j,minj,x;
  char y;

  for(i = 0; i < sumcard; i++){

    minj = i;

    for(j = i; j < sumcard; j++){

      if(inputdata2[j].number < inputdata2[minj].number){

	minj = j;

      }

    }
      temp = inputdata2[i];
    
      inputdata2[i] =inputdata2[minj];

      inputdata2[minj] = temp;
     
  }
  
}



 