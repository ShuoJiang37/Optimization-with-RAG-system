#include <stdio.h>

#define W_MAX 1000001
#define MAX 1001

int array[MAX];
int sorted[MAX];

void swap(int* a, int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int calc_cost(int n, int min_pos, int flag){
  int loop_pos = min_pos;
  int i, sum = 0;
  int min = array[min_pos];

  do{
    for(i = 0; i < n; i++){
      if(array[i] == sorted[loop_pos]){
	sum += array[i] + min;

	if(flag){ swap(&array[i], &array[loop_pos]); }

	loop_pos = i;
	
	break;
      }
    }
    
    
    if(0){
      for(i = 0; i < n; i++){
	printf("%s%d", i == 0 ? "" : " ", array[i]);
      }
      printf(" : %d\n", sum);
    }else{
      //printf("%d\n", sum);
    }
    
  }while(min != sorted[loop_pos]);

  return sum;
}

int greedy(int n){
  int i, j;
  int absolute_min = sorted[0], absolute_min_pos = -1;
  int min = W_MAX, min_pos = -1;
  int loop_pos = -1;
  int direct_sum = 0;
  int indirect_sum = 0;

  for(i = 0; i < n; i++){
    if(array[i] == absolute_min){
      absolute_min_pos = i;
      break;
    }
  }

  for(i = 0; i < n; i++){
    if(min > array[i] && sorted[i] != array[i]){
      min = array[i];
      min_pos = i;
    }
  }

  if(min_pos == -1){
    return 0;
  }

  //printf("absolute_min = %d(%d)\n", absolute_min, absolute_min_pos);

  direct_sum += calc_cost(n, min_pos, 0);
  
  swap(&array[min_pos], &array[absolute_min_pos]);
  indirect_sum += array[min_pos] + array[absolute_min_pos];
  indirect_sum += calc_cost(n, min_pos, 0);
  swap(&array[min_pos], &array[absolute_min_pos]);

  //printf("min = %d, direct_sum = %d, indirect_sum = %d\n", min, direct_sum, indirect_sum);

  if(direct_sum <= indirect_sum){
    calc_cost(n, min_pos, 1);
    
    return direct_sum + greedy(n);
  }else{
    swap(&array[min_pos], &array[absolute_min_pos]);
    //printf("%d\n", 
    calc_cost(n, min_pos, 1);

    return indirect_sum + greedy(n);
  }

  return 0;
}

int main(int argc, char* argv[]){
  int i, j, n;
  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
    sorted[i] = array[i];
  }
  
  for(i = 0; i < n; i++){
    int min = sorted[i];
    int min_pos = i;
    
    for(j = i + 1; j < n; j++){
      if(min > sorted[j]){
	min = sorted[j];
	min_pos = j;
      }
    }

    if(min_pos != i){
      swap(&sorted[i], &sorted[min_pos]);
    }
  }


  printf("%d\n", greedy(n));

  return 0;
}