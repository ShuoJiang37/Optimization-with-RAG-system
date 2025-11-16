#include <stdio.h>

main(){

  int i,j;
  int Sel[101];
  int N;
  int tmp;
  int mini;
  int count = 0;

  scanf("%d",&N);

  for(i=1; i<=N;i++){
    scanf("%d",&Sel[i]);
  }

  // selection
  for (i=1; i<=N; i++){
    mini = i;
    for (j=i; j<=N; j++){
      if(Sel[j] < Sel[mini]){
	mini = j;
      }
    }
    if(i != mini){
      
      tmp = Sel[i];
      Sel[i] = Sel[mini];
      Sel[mini] = tmp;
      count++;
      
    }

  }

  for (i=1; i<=N; i++){
    printf("%d",Sel[i]);

    if(i!=N){
      printf(" ");
    }
  }

  printf("\n%d\n",count);

return 0;

}