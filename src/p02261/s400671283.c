#include <stdio.h>

struct Card
{
  char suit;
  int value;
};

void bubble(struct Card b[], int n)
{
  int i, j;
  struct Card swap;
  
  for(i = 1; i < n; i ++ ){
    for(j = n-1; j >= i; j--){
      if(b[j].value < b[j-1].value){
       swap = b[j];
       b[j] = b[j-1];
       b[j-1] = swap;
      }
    }
  }
}

void selection(struct Card s[], int n)
{
  int min, i, j;
  struct Card swap;
  
  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(s[j].value < s[min].value)
        min = j;
    }
    if( i != min){
      swap = s[i];
      s[i] = s[min];
      s[min] = swap;
    }
  }
}

int stable(struct Card b[], struct Card s[], int n)
{
  int i;
  
  for(i = 0; i < n; i++){
    if(b[i].suit != s[i].suit)
      return 0;
  }
  
  return 1;
}

int main()
{
  struct Card b[36], s[36];
  char space;
  int i, n;
  
  scanf("%d\n", &n);
  
  for(i = 0; i < n; i++){
    scanf("%c%d", &b[i].suit, &b[i].value);
    scanf("%c", &space);
  }
  
  for(i = 0; i < n; i++)
    s[i] = b[i];
    
  bubble(b, n);
  
  selection(s, n);
  
  for(i = 0; i < n-1; i++)
    printf("%c%d ", b[i].suit, b[i].value);
    
  printf("%c%d\n", b[n-1].suit, b[n-1].value);
  
  puts("Stable");
  
  for(i = 0; i < n-1; i++)
    printf("%c%d ", s[i].suit, s[i].value);
    
  printf("%c%d\n", s[n-1].suit, s[n-1].value);
  
  if(stable(b, s, n))
    puts("Stable");
  else
    puts("Not stable");
    
  return 0;
}