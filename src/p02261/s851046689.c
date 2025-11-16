#include<stdio.h>
#define N 101

struct Card{
  char s;
  char v;
};

void bubble(struct Card data[],int n)
{
  int i,j;
  struct Card tmp;

  for(i=0; i<n; i++){
    for(j=n-1; j>=i+1; j--){
      if(data[j].v < data[j-1].v){
        tmp = data[j];
        data[j] = data[j-1];
        data[j-1] = tmp;
      }
    }
  }
}

void selection(struct Card data[], int n)
{
  int i,j,mini;
  struct Card tmp;

  for(i=0; i<n; i++){
    mini = i;
    for(j=i; j<n; j++){
      if(data[j].v < data[mini].v)
        mini = j;
    }
    tmp = data[i];
    data[i] = data[mini];
    data[mini] = tmp;
  }
}

void print(struct Card data[], int n)
{
  int i;

  for (i=0; i<n-1; i++){
    printf("%c%c ",data[i].s,data[i].v);
  }
  printf("%c%c\n",data[n-1].s,data[n-1].v);
}

int isStable(struct Card C1[], struct Card C2[], int n)
{
  int i;

  for(i=0; i<n; i++){
    if(C1[i].s != C2[i].s)
      return 0;
  }

  return 1;
}

int main()
{
  int n,i;
  char ch;
  struct Card C1[N], C2[N];

  scanf("%d\n",&n);

  for (i=0; i<n; i++)
    scanf("%c%c ",&C1[i].s,&C1[i].v);

  for (i= 0; i<n; i++)
    C2[i] = C1[i];

  bubble(C1,n);
  selection(C2,n);
  print(C1,n);

  printf("Stable\n");

  print(C2,n);

  if(isStable(C1,C2,n))
    printf("Stable\n");
  else
    printf("Not stable\n");

  return 0;
}
