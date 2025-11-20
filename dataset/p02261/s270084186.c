#include <stdio.h>

#define N 36
typedef struct {
  int value;
  char mark;
}card;

int main(){


  /*1 bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
    2   flag = 1 // 逆の隣接要素が存在する
    3   while flag
    4     flag = 0
    5     for j が N-1 から 1 まで
    6       if A[j] < A[j-1]
    7         A[j] と A[j-1] を交換
    8         flag = 1
  */
  /*
    1 BubbleSort(C, N)
    2   for i = 0 to N-1
    3     for j = N-1 downto i+1
    4       if C[j].value < C[j-1].value
    5         C[j] と C[j-1] を交換
    6
    7 SelectionSort(C, N)
    8   for i = 0 to N-1
    9     minj = i
    10    for j = i to N-1
    11      if C[j].value < C[minj].value
    12        minj = j
    13    C[i] と C[minj] を交換
  */ 

  int n ,i ,j,c=0 , t ,min;
  char tc , nu;
    card arr[N],input[N];
  scanf("%d\n" ,&n);
  // scanf("%c" ,&nu );// /n
  
  for ( i = 0; i < n; i++){
    if ( i == n-1 ) {    scanf("%c%d",&arr[i].mark,&arr[i].value);
    }else{
    scanf("%c%d ",&arr[i].mark,&arr[i].value);
    //    printf("test%c%d\n",arr[i].mark,arr[i].value);
    }
    input[i].mark = arr[i].mark;
    input[i].value = arr[i].value;
  }

  // printf("test%c%d\n",arr[0].mark,arr[0].value);
  
  int flag = 1 ;
  while ( flag){
    flag = 0;
    for ( i = n - 1 ;  i >= 1; i--){
      if ( arr[i].value < arr[ i-1 ].value){
	t = arr[i].value; arr[i].value = arr[ i-1 ].value; arr[i-1].value = t;
	tc = arr[i].mark; arr[i].mark = arr[ i-1 ].mark; arr[i-1].mark = tc;
	c++;
	flag = 1;
      }
    }
  }

  // printf("test%c%d\n",arr[0].mark,arr[0].value);
  
  for ( i = 0; i < n; i++){
    printf("%c%d",arr[i].mark,arr[i].value);
    if ( i == n-1){printf("\n");}
    else {printf(" ");}
  }
printf("Stable\n");

  
//selection sort part

  for ( i = 0; i < n ;i++){
    min = i;
    for ( j = i; j < n; j++){
      if ( input[j].value < input[min].value){ min = j;}
    }
    if ( input[i].value != input[min].value ){
      c++;
    j = input[i].value; input[i].value = input[min].value; input[min].value = j;
    	tc = input[i].mark; input[i].mark = input[min].mark; input[min].mark = tc;
    }
  }
  
   for ( i = 0; i < n; i++){
    printf("%c%d",input[i].mark,input[i].value);
    if ( i == n-1){printf("\n");}
    else {printf(" ");}
  }



 
  flag = 1;
  for ( i = 0; i < n; i++){
    if( input[i].mark != arr[i].mark){
      flag =0;break;
    }
  }
  if (flag == 1){printf("Stable\n");}
  else if ( flag == 0)  { printf("Not stable\n");}
  
  return 0;
}

