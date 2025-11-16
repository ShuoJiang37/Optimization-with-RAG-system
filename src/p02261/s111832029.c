
#include <stdio.h>
struct Card{
  char mark;
  char num;
};

void Bubble(struct Card B[], int N){
  int i, j;
 struct Card swap;
  for(i = 0; i < N; i++){
    for(j = (N - 1); j > i; j--){
      if(B[j].num < B[j - 1].num){
	swap = B[j - 1];
	B[j - 1] = B[j];
	B[j] = swap;
      } 
    }
  }
  for(i = 0; i < N; i++){
    printf("%c%c", B[i].mark, B[i].num);
    if(i < (N - 1))printf(" ");
  }
  printf("\n");
}
void Selection(struct Card S[], int N){
  struct Card swap;
  int i, j, mini, han;
  for(i = 0; i < N - 1; i++){
    han = 0;
    mini = i;
    for(j = i; j < N; j++){
      if(S[j].num < S[mini].num){
	mini = j;
	han = 1;
      }
    }
    if(han == 1){ 
      swap = S[i];
      S[i] = S[mini];
      S[mini] = swap;
    }
  }
  for(i = 0; i < N; i++){
    printf("%c%c", S[i].mark, S[i].num);
    if(i < (N - 1))printf(" ");
  }
  printf("\n");
}

int main(){
  struct Card trump[36], trump2[36];
  int N, i, han = 0;
  char ch;
  scanf("%d%c", &N, &ch); 
  for(i = 0; i < N; i++){
    scanf("%c%c%c", &trump[i].mark, &trump[i].num, &ch);
    trump2[i] = trump[i];
  }
  Bubble(trump, N);
  printf("Stable\n");
  Selection(trump2, N);
  for(i = 0; i < N; i++){
    if(trump2[i].mark != trump[i].mark){
      printf("Not stable\n");
      han = 1;
      break;
    }
  }
  if(han == 0)printf("Stable\n");
  return 0;
}