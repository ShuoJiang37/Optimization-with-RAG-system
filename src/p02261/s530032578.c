#include<stdio.h>

int main(){
  char card[36][3];
  int N,i,j,minj,Order[36],tmp,check=0,stable=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    Order[i]=i;
    scanf("%s",card[i]);
    
  }
  
  while(1){
    for(i=N-1;i>0;i--){
      if(card[Order[i-1]][1] > card[Order[i]][1]){
	tmp = Order[i];
	Order[i] = Order[i-1];
	Order[i-1] = tmp;
	check++;
      }
    }
    if(check == 0)break;
    check = 0;  
  }
  for(i=0;i<N;i++){
    if(i==N-1)printf("%s\n",card[Order[i]]);
    else printf("%s ",card[Order[i]]);
    if(i < N-1 && card[Order[i]][1] == card[Order[i+1]][1] && Order[i] > Order[i+1])stable=-1;
  }
  if(stable == -1)printf("Not stable\n");
  else printf("Stable\n");

  for(i=0;i<N;i++)Order[i]=i;
  for(i=0;i<N-1;i++){
    for(minj = j = i+1;j<N;j++){
      if (card[Order[minj]][1] > card[Order[j]][1] ) minj = j;
    }
    if(card[Order[i]][1] >card[Order[minj]][1] ){
      tmp = Order[i];
      Order[i] = Order[minj];
      Order[minj] = tmp;
    } 
  }
  for(i=0;i<N;i++){
    if(i==N-1)printf("%s\n",card[Order[i]]);
    else printf("%s ",card[Order[i]]);
    if(i < N-1 && card[Order[i]][1] == card[Order[i+1]][1] && Order[i] > Order[i+1])stable=-1;
  }
  if(stable == -1)printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}
