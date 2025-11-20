#include <stdio.h>
#include <stdlib.h>

void InsSort(int num[ ], int n) ;
void ShowData(int num[ ], int n);
int main(void);

void InsSort(int num[ ], int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++) {
        temp = num[i];
        for (j = i; j > 0 && num[j-1] > temp; j--)
            num[j] = num[j -1];

        num[j] = temp;
        ShowData(num, n);
    }
}

/* n 個のデータを表示 */
void ShowData(int num[ ], int n)
{
  while (n--){
    if(n == 0)
      printf("%d", *num++);
    else
      printf("%d ", *num++);
  }
  printf("\n");
}

int main(void)
{
  int NUM_DATA,i;
  int *num;

  while(1){
 scanf("%d",&NUM_DATA);
  if(NUM_DATA >= 0 || NUM_DATA <= 100)break;
  }

  num = (int *)malloc(sizeof(int) * NUM_DATA);

  for(i = 0; i < NUM_DATA; i++){
    while(1){
    scanf("%d",&num[i]);
    if(num[i] >= 0 || num[i] <= 1000) break;
    }
  }



  for(i = 0;i<NUM_DATA;i++){
    if(i < NUM_DATA-1)
      printf("%d ",num[i]);
    else
      printf("%d",num[i]);
  }
  printf("\n");

    InsSort(num, NUM_DATA);

    for(i = 0; i++; i < NUM_DATA){
      free(num);
    }

    return 0;
}


