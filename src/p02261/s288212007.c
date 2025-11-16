#include<stdio.h>

typedef struct{
	char mark;                     //?§??????????
	int num;
}card;

void swap(card *a,card *b);                    //????????????????????£?¨?	
void bubble(int N,card *B);
void select(int N,card *S);
void printer(int N,card *P,card *P2);

int main(void)
{
	int i,j,n;
	card c[36],c2[36];

	scanf("%d",&n);                              
	for(i = 0;i < n;i++){
		scanf(" %c%d",&c[i].mark,&c[i].num);
	}

	for(i = 0;i < n;i++){   //copy
		c2[i] = c[i];
	}

	bubble(n,c);
	select(n,c2);
	printer(n,c,c2);
	return 0;
}

void swap(card *a,card *b)        //??????????????¢??°
{
	card temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void bubble(int N,card *B)          //????????????????????????????????????
{
	int j = 0;
	int flag = 1;
	int i = 0;

	while(flag){
		flag = 0;
		for(j = N - 1;j > i;j--){
			if(B[j].num < B[j - 1].num)swap(&B[j],&B[j - 1]);
			flag = 1;
		}
		i++;
	}
	return;
}

void select(int N,card *S)
{
	int i,j,minj;

	for(i = 0;i < N;i++){
		minj = i;
		for(j = i;j < N;j++){
			if(S[j].num < S[minj].num){
				minj = j;
			}
		}
		swap(&S[i],&S[minj]);
	}
	return;
}

void printer(int N,card *P,card *P2)                        //????????¢??°
{
	int i;

	for(i = 0;i < N;i++){
		if(i != 0)printf(" ");
		printf("%c%d",P[i].mark,P[i].num);
	}
	printf("\n");
	printf("Stable\n");

	for(i = 0; i < N;i++){
		if(i != 0)printf(" ");
		printf("%c%d",P2[i].mark,P2[i].num);
	}
	printf("\n");
	
	int count = 0;
	for(i = 0;i < N;i++){
		if(P[i].mark == P2[i].mark){
			count++;
		}
	}
	if(count == N){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
}          