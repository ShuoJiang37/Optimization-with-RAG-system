#include<stdio.h>
 
typedef struct
{
  int num;
  char mark;
} card;
 
int length;
int i, j;
card orig_n[36];
card sort_n[36];
card tmp;

void ScanCards();
void BubbleSort();
void PrintSortedCards();
void JudgeStable();
void SelectionSort();
void PrintSortedCards();
void JudgeStable();
 
void ScanCards(){
  char c;
 
  scanf("%d", &length);
  for(i=0;i<length;i++){
      while(1){
      c = getchar();
      if(c != ' ' && c != '\n') break;
      }
      orig_n[i].mark=c;
      scanf("%d",&orig_n[i].num);
      orig_n[i]=orig_n[i];
    }
}

void BubbleSort(){
  int flag;
 
  for(i=0;i<length;i++) sort_n[i]=orig_n[i];
 
  for(i=0;i<length;i++){
      flag=0;
      for(j=length-1;j>i;j--){
      if(sort_n[j-1].num>sort_n[j].num){
          tmp=sort_n[j];
          sort_n[j]=sort_n[j-1];
          sort_n[j-1]=tmp;
          flag=1;
        }
    }
      if(flag==0) break;
    }
}

void SelectionSort(){
  int min_i;
 
  for(i=0;i<length;i++) sort_n[i]=orig_n[i];
 
  for(i=0;i<length;i++){
      min_i=i;
      for(j=i;j<length;j++){
      if(sort_n[j].num<sort_n[min_i].num) min_i=j;
    }
      tmp=sort_n[i];
      sort_n[i]=sort_n[min_i];
      sort_n[min_i]=tmp;
    }

}

void PrintSortedCards(){
  for(i=0;i<length-1;i++){
      printf("%c%d ", sort_n[i].mark, sort_n[i].num);
    }
  printf("%c%d\n", sort_n[length-1].mark, sort_n[length-1].num);
}

void JudgeStable(){
  int s1,s2;
  int flag=0;
 
  for(i=0;i<length;i++){
      if(sort_n[i].num == sort_n[i+1].num){
      for(j=0;j<length;j++){
	if((sort_n[i].num==orig_n[j].num) && (sort_n[i].mark==orig_n[j].mark)) s1=j;
	if((sort_n[i + 1].num == orig_n[j].num) && (sort_n[i + 1].mark==orig_n[j].mark)) s2=j;
        }
      if(s1>s2) flag=1;
    }
      if(flag==1) break;
    }
  if(flag==0) printf("Stable\n");
  else printf("Not stable\n");
 
}

int main()
{
  ScanCards();
 
  BubbleSort();
 
  PrintSortedCards();
 
  JudgeStable();
 
  SelectionSort();
 
  PrintSortedCards();
 
  JudgeStable();
 
  return 0;
}