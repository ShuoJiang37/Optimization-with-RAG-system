#include <stdio.h>

struct Card{
	char suit;
	int value;
};


void bubbleSort(struct Card x[], int N)
{
	int i, j;
	struct Card tmp;
	for(i=0; i<N-1; i++){
		for(j=N-1; j>i; j--){
			if(x[j].value < x[j-1].value)
			{
				tmp = x[j];
				x[j] = x[j-1];
				x[j-1] = tmp;
			}
		}
	}
}


void selectionSort(struct Card x[], int N)
{
	int i, j, minj;
	struct Card tmp;
	for(i=0; i<N; i++){
		minj = i;
		for(j=i; j<N; j++){
			if(x[j].value < x[minj].value)
			{
				minj = j;
			}
		}
		tmp = x[i];
		x[i] = x[minj];
		x[minj] = tmp;
	}
}


int main(void)
{
	int N;
	struct Card c1[36], c2[36];
	
	scanf("%d", &N);
	
	int i;
	for(i=0; i<N; i++){
		scanf(" %c%d", &c1[i].suit, &c1[i].value);
	}
	
	for(i=0; i<N; i++){
		c2[i] = c1[i];
	}
	
	for(i=0; i<N-1; i++){
		bubbleSort(c1, N);
		printf("%c%d ", c1[i].suit, c1[i].value);
	}
	printf("%c%d\n", c1[N-1].suit, c1[N-1].value);
	printf("Stable\n");
	
	for(i=0; i<N-1; i++){
		selectionSort(c2, N);
		printf("%c%d ", c2[i].suit, c2[i].value);
	}
	printf("%c%d\n", c2[N-1].suit, c2[N-1].value);
	int count=0;
	for(i=0; i<N; i++){
		if(c1[i].suit != c2[i].suit) count++;
	}
	if(count == 0) printf("Stable\n");
	else printf("Not stable\n");
	
	return 0;
}

