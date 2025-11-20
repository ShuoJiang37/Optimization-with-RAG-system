#include <stdio.h>
#include <string.h>

typedef struct {
  char card[36][3];
}Record;



Record Bubble(Record, int);
Record Select(Record, int);
int Stable(Record, Record, int);

int main () {
  int i, j, n = 0, h =0;
  Record data, bub, sel;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) {
      scanf("%s",&data.card[i]);
  }


  
  bub = Bubble(data, n);
   for(i = 0 ; i < n ; i++) {
    if(i == n - 1) printf("%s\n",bub.card[i]);
    else printf("%s ",bub.card[i]);
  }
  printf("Stable\n");

  
  sel = Select(data, n);
  for(i = 0 ; i < n ; i++) {
    if(i == n - 1) printf("%s\n",sel.card[i]);
    else printf("%s ",sel.card[i]);
  }

  if(Stable(bub, sel, n) == 1) printf("Stable\n");
    else printf("Not stable\n"); 
  
  return 0;
}


Record Bubble(Record data, int n) {
  int i, j;
  char c[3];

  for(i = 0 ; i < n ; i++) {
    for(j = n - 1 ; j >= i + 1 ; j--) {
      if(atoi(&data.card[j][1]) < atoi(&data.card[j-1][1])) {
	strcpy(c, data.card[j]);
	strcpy(data.card[j], data.card[j-1]);
	strcpy(data.card[j-1], c);
      }
    }
  }
  return data;
}



Record Select(Record data, int n) {
  int i, j, min = 0;
  char c[3];
  
  for(i = 0 ; i < n ; i++) {
    min = i;

    for(j = i ; j < n ; j++) {
      if(atoi(&data.card[j][1]) < atoi(&data.card[min][1])) min = j;
    }
    strcpy(c, data.card[i]);
    strcpy(data.card[i], data.card[min]);
    strcpy(data.card[min], c);
  }
  
  return data;
}


int Stable(Record data, Record str, int n) {
  int i;

  for(i = 0 ; i < n ; i++) {
    if(strcmp(data.card[i], str.card[i]) != 0) return 0;
  }

  return 1;

}

