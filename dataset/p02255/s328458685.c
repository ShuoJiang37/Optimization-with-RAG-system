#include <stdio.h>
#include <string.h>

#define BUF_SIZE 10000
#define ARRAY_SIZE 1000

void print_array(int array[], int size){
  int i;

  for(i = 0; i < size; i++){
    if(i > 0) printf(" ");
    printf("%d", array[i]);
  }

  printf("\n");
  return;
}

void insersion_sort(int array[], int size)
{
  int i, j, v;

  for(i = 1; i < size; i++){
    v = array[i];
    j = i - 1;
    while((j >= 0) && (array[j] > v)){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = v;
    print_array(array, size);
  }

  return ;
}

int main(void)
{
  char buf[BUF_SIZE];
  char *ptr;
  int input_size;
  int array[ARRAY_SIZE];
  int i;

  fgets(buf, BUF_SIZE, stdin);
  sscanf(buf, "%d", &input_size);

  fgets(buf, BUF_SIZE, stdin);
  ptr = strtok(buf, " ");

  for(i = 0; i < input_size; i++){
    sscanf(ptr, "%d", &array[i]);
    ptr = strtok(NULL, " ");
  }

  print_array(array, input_size);
  insersion_sort(array, input_size);

  return 0;
}