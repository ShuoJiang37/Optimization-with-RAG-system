#include <stdio.h>
#include <stdlib.h>

main(){

  int i,j;
  int C[37][2];
  int Bub[37][2];
  int Sel[37][2];
  int N;
  int tmpi;
  char tmpc;
  char str[3];
  int mini,isStable;

  scanf("%d",&N);

  for(i=1; i<=N;i++){
    scanf("%s",str);
    C[i][0] = Bub[i][0] = Sel[i][0] = atoi(&str[1]);
    C[i][1] = Bub[i][1] = Sel[i][1] = str[0];
  }

  // bubble
  for (i=1; i<=N; i++){

    for (j=N; j>=i+1; j--){

      if(Bub[j][0] < Bub[j-1][0]){
	
	tmpi = Bub[j][0];
	tmpc = Bub[j][1];
	Bub[j][0] = Bub[j-1][0];
	Bub[j][1] = Bub[j-1][1];
	Bub[j-1][0] = tmpi;
	Bub[j-1][1] = tmpc;

      }

    }

  }

  // selection
  for (i=1; i<=N; i++){
    mini = i;
    for (j=i; j<=N; j++){
      if(Sel[j][0] < Sel[mini][0]){
	mini = j;
      }
    }
    if(i != mini){
      
      tmpi = Sel[i][0];
      tmpc = Sel[i][1];
      Sel[i][0] = Sel[mini][0];
      Sel[i][1] = Sel[mini][1];
      Sel[mini][0] = tmpi;
      Sel[mini][1] = tmpc;
      
    }

  }

  isStable = 1;

  // DISPLAY
  for (i=1; i<=N; i++){
    printf("%c%d",Bub[i][1],Bub[i][0]);

    // SAME NUMBER
    if(isStable==1 && i>1 && Bub[i][0] == Bub[i-1][0]){
      for(j=1; j<=N; j++){
	if(C[j][0]==Bub[i][0] && C[j][1]==Bub[i][1]){
	  isStable = 0;
	  break;
	}
	if(C[j][0]==Bub[i-1][0] && C[j][1]==Bub[i-1][1]){
	  break;
	}
      }
    }

    if(i!=N){
      printf(" ");
    }
  }

  printf("\n");
  if(isStable==1){
    printf("Stable");
  }else{
    printf("Not stable");
  }
  printf("\n");

  isStable = 1;

  for (i=1; i<=N; i++){
    printf("%c%d",Sel[i][1],Sel[i][0]);

    // SAME NUMBER
    if(isStable==1 && i>1 && Sel[i][0] == Sel[i-1][0]){
      for(j=1; j<=N; j++){
	if(C[j][0]==Sel[i][0] && C[j][1]==Sel[i][1]){
	  isStable = 0;
	  break;
	}
	if(C[j][0]==Sel[i-1][0] && C[j][1]==Sel[i-1][1]){
	  break;
	}
      }
    }

    if(i!=N){
      printf(" ");
    }
  }

  printf("\n");
  if(isStable==1){
    printf("Stable");
  }else{
    printf("Not stable");
  }
  printf("\n");

return 0;

}