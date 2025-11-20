#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);
  char cards1[n][3];
  char cards2[n][3];

  for (int i=0; i<n; i++) {
    char tmp[3];
    scanf("%s", tmp);
    strcpy(cards1[i], tmp);    
    strcpy(cards2[i], tmp);    
  }

  // バブルソート
  for (int i=0; i<n; i++) {
    for (int j=n-1; j>0; j--) {
      if (cards1[j][1]<cards1[j-1][1]) {
        char tmp[3];
        strcpy(tmp, cards1[j]);
        strcpy(cards1[j], cards1[j-1]);
        strcpy(cards1[j-1], tmp);
      }
    }
  }

  for (int i=0; i<n; i++) {
    if (i<n-1) printf("%s ", cards1[i]);
    else printf("%s\n", cards1[i]);
  }
  printf("Stable\n");

  // 選択ソート
  int flg=0;
  for (int i=0; i<n; i++) {
    int minj=i;
    for (int j=i+1; j<n; j++) {
      if (cards2[minj][1]>cards2[j][1]) {
        minj=j;
      } else if (cards2[minj][1]==cards2[j][1] && minj!=i) {
        flg=1;
      }
    }
    
    if (minj!=i) {
      char tmp[3];
      strcpy(tmp, cards2[i]);
      strcpy(cards2[i], cards2[minj]);
      strcpy(cards2[minj], tmp);
    }
  }

  for (int i=0; i<n; i++) {
    if (i<n-1) printf("%s ", cards2[i]);
    else printf("%s\n", cards2[i]);
  }
  if (flg) {
    printf("Not stable\n");
  } else {
    printf("Stable\n");
  }
  
  return 0;
}
