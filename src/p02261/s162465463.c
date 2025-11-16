#include <stdio.h>

int BubbleSort(int);



int main(){
  int A[100],B[100],n,i,j,a,c,count,min,cnt=0;
  char C[100],D[100];

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf(" %c%d",&C[i],&A[i]);

  for(i=0;i<n;i++){
    B[i] = A[i];
    D[i] = C[i];
  }


//バブルソート
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        a = A[j];
        c = C[j];
        A[j] = A[j-1];
        C[j] = C[j-1];
        A[j-1] = a;
        C[j-1] = c;
      }
    }
  }

  //セレクションソート

  for(i=0;i<n-1;i++){
    min = i;
    for(j=i+1;j<n;j++){
      if(B[j]<B[min]) min = j;
    }
    if(B[i]!=B[min]){
      a = B[i];
      c = D[i];
      B[i] = B[min];
      D[i] = D[min];
      B[min] = a;
      D[min] = c;
    }
  }

  for(i=0;i<n;i++) {
    if(C[i]!=D[i]) {
      cnt = 0;
      break;
    } else {
      cnt++;
    }
  }

  for(i=0;i<n;i++){
    if(i==0) printf("%c%d",C[i],A[i]);
    else printf(" %c%d",C[i],A[i]);
  }
  printf("\n");
  printf("Stable\n");

  for(i=0;i<n;i++){
    if(i==0) printf("%c%d",D[i],B[i]);
    else printf(" %c%d",D[i],B[i]);
  }
  printf("\n");
  if(cnt==0) printf("Not stable\n");
  else printf("Stable\n");






  return 0;
}

