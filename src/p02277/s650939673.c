#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 100001
#define INF INT_MAX

int Partition(int*, char*, int, int);
void Quicksort(int*, char*, int, int);
void merge(int*, char*, int, int, int);
void Mergesort(int*, char*, int, int);

int main(){
  int n, i, arr_q[MAX], arr_m[MAX];
  char mark_q[MAX], mark_m[MAX];

  scanf("%d" ,&n);
  for(i = 0 ; i < n ; i++){
    scanf("\n%c%d" , mark_q+i, arr_q+i);

    arr_m[i] = arr_q[i];
    mark_m[i] = mark_q[i];
  }

  Quicksort(arr_q, mark_q, 0, n-1);
  Mergesort(arr_m, mark_m, 0, n);

  if(memcmp(arr_q, arr_m, n) == 0 &&
     memcmp(mark_q, mark_m, n) == 0){
    puts("Stable");
  }else{
    puts("Not stable");
  }
 
  for(i = 0 ; i < n ; i++){
    printf("%c %d\n" ,mark_q[i], arr_q[i]);
  }

  return 0;
}

int Partition(int arr[], char mark[], int p, int r){
  int x = arr[r], i = p - 1, j, tmp;
  char tmp_mark;

  for(j = p ; j < r ; j++){
    if(arr[j] <= x){
      i++;
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;

      tmp_mark = mark[i];
      mark[i] = mark[j];
      mark[j] = tmp_mark;
    }
  }
  
  tmp = arr[i+1];
  arr[i+1] = arr[r];
  arr[r] = tmp;
  
  tmp_mark = mark[i+1];
  mark[i+1] = mark[r];
  mark[r] = tmp_mark;
  
  return ++i;
}

void Quicksort(int arr[], char mark[], int p, int r){
  int q;

  if(p < r){
    q = Partition(arr, mark, p, r);
    Quicksort(arr, mark, p, q-1);
    Quicksort(arr, mark, q+1, r);
  }
}

void merge(int arr[], char mark[], int left, int mid, int right){
  int n1 = mid - left, n2 = right - mid;
  int L[MAX], R[MAX], i, j, k;
  char Lm[MAX], Rm[MAX];

  for(i = 0 ; i < n1 ; i++){
    L[i] = arr[left + i];
    Lm[i] = mark[left + i];
  }

  for(i = 0 ; i < n2 ; i++){
    R[i] = arr[mid + i];
    Rm[i] = mark[mid + i];
  }

  L[n1] = R[n2] = INF;
  for(i = 0, j = 0, k = left ; k < right ; k++){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      mark[k] = Lm[i++];
    }else{
      arr[k] = R[j];
      mark[k] = Rm[j++];
    }
  }
}

void Mergesort(int arr[], char mark[], int left, int right){
  int mid;

  if(left + 1 < right){
    mid = (left + right) / 2;
    Mergesort(arr, mark, left, mid);
    Mergesort(arr, mark, mid, right);
    merge(arr, mark, left, mid, right);
  }
}