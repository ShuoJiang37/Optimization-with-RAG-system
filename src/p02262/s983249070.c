#include <stdio.h>
#include <math.h>
 
#define ELEMENT_CNT_MIN 1
#define ELEMENT_CNT_MAX 1000000
#define ELEMENT_MIN 0
#define ELEMENT_MAX 1000000000
#define SHELL_SROT_CNT_MIN 1
#define SHELL_SROT_CNT_MAX 100

void shell_sort(int *p_arr, int size);
int insertion_srot(int *p_arr, int size, int interval);
void put_arr(int *p_arr, int size);
int get_int_sequence(int *p_num, int min, int max, int size);
int get_int(int *p_num, int min, int max);
int judge_constraint(int test_num, int min, int max);

 
int main(void){
     
    int element_num;
    int element[ELEMENT_CNT_MAX];
     
    if(get_int(&element_num, ELEMENT_CNT_MIN, ELEMENT_CNT_MAX) == -1)
    {
        return -1;
    }
     
    if(get_int_sequence(&element[0], ELEMENT_MIN, ELEMENT_MAX, element_num) == -1)
    {
        return -1;
    }
    
    shell_sort(&element[0], element_num);
    
    put_arr(&element[0], element_num);
    
    return 0;
}
 
int insertion_srot(int *p_arr, int size, int interval)
{
    int cnt = 0;    /* calculation amount */
    int i;
    int j;
    int locator;
    
    for(i = interval; i < size; i++)
    {
        locator = p_arr[i];
        j = i - interval;
        while(j >= 0 && p_arr[j] > locator)
        {
            p_arr[j + interval] = p_arr[j];
            j = j - interval;
            cnt++;
        }
        p_arr[j + interval] = locator;
    }
    
    return cnt;
}

void shell_sort(int *p_arr, int size)
{
   int cnt = 0;
   int interval = 1;    /* (pow(3, 0) - 1) / 2 == 0 */
   int i;
   int shell_sort_cnt = SHELL_SROT_CNT_MIN;
   int G[SHELL_SROT_CNT_MAX];
   
  for(i = shell_sort_cnt ;i <= SHELL_SROT_CNT_MAX; i++)
  {
      interval =  (int)((pow(3, i) - 1) / 2);
      if(interval > size)
      {
          shell_sort_cnt = i - 1;
          printf("%d\n",shell_sort_cnt);
          break;
      }
      G[i - 1] = interval;
  }
   
   
   for(i = shell_sort_cnt;;i--)
   {
       cnt += insertion_srot(p_arr, size, G[i - 1]);
       printf("%d ", G[i - 1]);
       if(G[i - 1] <= 1)
       {
           printf("\n");
           break;
       }
   }
   
   printf("%d\n", cnt);
   
   return;
}
 
void put_arr(int *p_arr, int size)
{
    int i;
     
    for(i = 0; i < size; i++)
    {
        printf("%d\n", p_arr[i]);
    }
    
    return;
}
 
int get_int_sequence(int *p_num, int min, int max, int size)
{
    int i;
     
    for(i = 0; i < size; i++)
    {
        if(get_int(&p_num[i], min, max) == -1)
        {
            return -1;
        }
    }
     
    return 0;
}
 
int get_int(int *p_num, int min, int max)
{
    scanf("%d%*c", p_num);
     
    if(judge_constraint(*p_num, min, max) == -1)
    {
        return -1;
    }
     
    return 0;
}
int judge_constraint(int test_num, int min, int max)
{
    if(test_num < min || test_num > max)
    {
        return -1;
    }
     
    return 0;
}