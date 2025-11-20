#include<stdio.h>
int main(void){
  int N,i,j,figure1[36],mini=0,temp=0,s[36],n,te=0,stable=0,figure2[36],c_s[36];
  char ma[36],T,c_ma[36];
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf(" %c%d",&ma[i],&figure1[i]);
  }
  for(n = 0 ; n < N ; n++){
    s[n] = n;
  }
  for(i = 0 ; i < N ; i++){
    figure2[i] = figure1[i];
    c_s[i] = s[i];
    c_ma[i] = ma[i];
  }
  /*BubbleSort*/
  for(i = 0 ; i < N ; i++){
    for(j = N-1 ; j > i ; j--){
      if(figure1[j] < figure1[j-1]){
	temp = figure1[j];
	T = ma[j];
	te = s[j];

	figure1[j] = figure1[j-1];
	ma[j] = ma[j-1];
	s[j] = s[j-1];

	figure1[j-1] = temp;
	ma[j-1] = T;
	s[j-1] = te;
      }
    }
  }
  for(i = 0 ; i < N ; i++){
    printf("%c%d",ma[i],figure1[i]);
    if(i < N-1){
      printf(" ");
      if(figure1[i] == figure1[i+1]){
	if(s[i] > s[i+1]){
	  stable = 1;
	}
      } 
    }
    else printf("\n");
  }
  if(stable == 1){
    printf("Not stable\n");
  } else {
    printf("Stable\n");
  }
  stable = 0;
  
  /*SelectionSort*/
  for(i = 0 ; i < N ; i++){
    mini = i;
    for(j = i+1 ; j < N ; j++){
      if(figure2[j] < figure2[mini]){
	mini = j;
      }
    }
    temp = figure2[i];
    T = c_ma[i];
    te = c_s[i];

    figure2[i] = figure2[mini];
    c_ma[i] = c_ma[mini];
    c_s[i] = c_s[mini];

    figure2[mini] = temp;
    c_ma[mini] = T;
    c_s[mini] = te;
  }
  for(i = 0 ; i < N ; i++){
    printf("%c%d",c_ma[i],figure2[i]);
    if(i < N-1){
      printf(" ");
      if(figure2[i] == figure2[i+1]){
	if(c_s[i] > c_s[i+1]){
	  stable = 1;
	}
      } 
    }
    else printf("\n");
  }
  if(stable == 1){
    printf("Not stable\n");
  } else {
    printf("Stable\n");
  }
  return 0;
}