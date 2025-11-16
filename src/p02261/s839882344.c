#include<stdio.h>
#include<string.h>

typedef struct{
	char suit;
	int value;
} Card;

Card* bubbleSort(Card*, int);
Card* selectionSort(Card*, int);

int main(void){
	Card c[36], c2[36], tmp, *b, *s;
	int n, i, last, j, min_ind, flag;
	
	scanf("%d\n", &n);
	last = n-1;
	for(i = 0; i < n; i++){
		if(n == last){
			scanf("%c%d\n", &c[i].suit, &c[i].value);
			break;
		}
		scanf("%c%d ", &c[i].suit, &c[i].value);
	}
	memcpy(c2, c, sizeof(Card)*36);
	b = bubbleSort(c, n);
	s = selectionSort(c2, n);
	for(i = 0; i < n; i++){
		if(i == last){
			printf("%c%d\n", b[i].suit, b[i].value);
			break;
		}
		printf("%c%d ", b[i].suit, b[i].value);
	}
	printf("Stable\n");
	for(i = 0; i < n; i++){
		if(i == last){
			printf("%c%d\n", s[i].suit, s[i].value);
			break;
		}
		printf("%c%d ", s[i].suit, s[i].value);
	}
	for(i = 0; i < n; i++){
		if(s[i].suit != b[i].suit || s[i].value != b[i].value){
			printf("Not stable\n");
			goto EXIT;
		}
	}
	printf("Stable\n");
	EXIT:
	return 0;
}

Card* bubbleSort(Card* c, int n){
	Card tmp;
	int last = n-1;
	for(int i = 0; i < n; i++){
		for(int j = last; j > 0; j--){
			if(c[j-1].value > c[j].value){
				tmp = c[j-1];
				c[j-1] = c[j];
				c[j] = tmp;
			}
		}
	}
	return c;
}
Card* selectionSort(Card* c, int n){
	Card tmp;
	int last = n-1, min_ind;
	for(int i = 0; i < last; i++){
		min_ind = i;
		for(int j = i+1; j < n; j++){
			if(c[min_ind].value > c[j].value){
				min_ind = j;
			}
		}
		if(min_ind != i){
			tmp = c[i];
			c[i] = c[min_ind];
			c[min_ind] = tmp;
		}
	}
	return c;
}

