#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define rep(i, n) for(int i = 0; i < (n); i++)
#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9 + 7
#define endl printf("\n")
typedef long long ll;

typedef struct { int id; char x[3]; } card;

int
main(int argc, char *argv[])
{
  int n; card a[40], b[40];
  scanf("%d\n", &n);
  rep(i, n){
    scanf("%s", a[i].x);
    a[i].id = i;
    b[i] = a[i];
  }

  card temp;
  
  //bubble sort
  for(int i = 0; i < n; i++){
    for(int j = n - 1; j > i; j--){
      if(a[j - 1].x[1] > a[j].x[1]){
	temp = a[j - 1];
	a[j - 1] = a[j];
	a[j] = temp;
      }
    }
  }

  rep(i, n - 1) printf("%s ", a[i].x);
  printf("%s\n", a[n - 1].x);
  int flag = 0;
  for(int i = 0; i + 1 < n; i++){
    if(a[i].x[1] == a[i + 1].x[1]){
      if(a[i].id > a[i + 1].id){
	printf("Not stable\n");
	flag++;
        break;
      }
    }
  }
  if(flag == 0) printf("Stable\n");

  int min;
  for(int i = 0; i < n; i++){
    min = i;
    for(int j = i + 1; j < n; j++){
      if(b[min].x[1] > b[j].x[1]){
	min = j;
      }
    }
    temp = b[i];
    b[i] = b[min];
    b[min] = temp;
  }

  rep(i, n - 1) printf("%s ", b[i].x);
  printf("%s\n", b[n - 1].x);
  flag = 0;
  for(int i = 0; i + 1 < n; i++){
    if(b[i].x[1] == b[i + 1].x[1]){
      if(b[i].id > b[i + 1].id){
	printf("Not stable\n");
	flag++;
        break;
      }
    }
  }
  if(flag == 0) printf("Stable\n");
  return 0;
}

