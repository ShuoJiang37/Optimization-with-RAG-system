#include <stdio.h>
#include <string.h>

#define ARR_SIZE 36
#define STR_LEN 3

#define SWAP(a, b) {int tmp; tmp = a; a = b; b = tmp;}

void print_array(char arr[][STR_LEN], int size)
{
  int i;

  for(i = 0; i < size; i++){
    if(i > 0) printf(" ");
    printf("%s", arr[i]);
  }

  printf("\n");
  return;
}

void selection_sort(char arr[][STR_LEN], int size)
{
  int i;

  for(i = 0; i < size; i++){
    int minj, j;
    minj = i;
    for(j = minj; j < size; j++){
      if((arr[j][1] - '0') < (arr[minj][1] - '0')){
        minj = j;
      }
    }
    SWAP(arr[minj][0], arr[i][0]);
    SWAP(arr[minj][1], arr[i][1]);
  }

  return;
}

void bubble_sort(char arr[][STR_LEN], int size )
{
  int i = 0;
  int flag = 1;

  while(flag){
    flag = 0;
    for(i = 0; i < size - 1; i++){
      if((arr[i][1] -'0') > (arr[i+1][1] - '0')){
        SWAP(arr[i+1][0], arr[i][0]);
        SWAP(arr[i+1][1], arr[i][1]);
        flag = 1;
      }
    }
  }

  return;
}

int main(void)
{
  int size;
  int i;
  char arr_b[ARR_SIZE][STR_LEN];
  char arr_s[ARR_SIZE][STR_LEN];

  scanf("%2d", &size);

  for(i = 0; i < size; i++) scanf("%2s", arr_b[i]);

  memcpy((void *)arr_s, (void *)arr_b, ARR_SIZE * STR_LEN);

  bubble_sort(arr_b, size);
  print_array(arr_b, size);
  printf("Stable\n");

  selection_sort(arr_s, size);
  print_array(arr_s, size);

  if(memcmp((void *)arr_b, (void*)arr_s, size * STR_LEN) == 0){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  return 0;
}