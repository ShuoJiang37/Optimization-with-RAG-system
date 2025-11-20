#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CARD_MAX 36

typedef struct{
	char suit,value;
} card;

void print_cards(card[],int);
void bubble_sort(card[],int);
void selection_sort(card[],int);
void swap(card[],int,int);
void cards_copy(card[],card[],int);
int cards_compare(card[],card[],int);

int main(void){
	int i,card_count;
	char buf[128],*ch;
	fgets(buf, sizeof(buf), stdin);
  card_count = atoi(buf);

	card cards1[CARD_MAX];
	card cards2[CARD_MAX];

	fgets(buf,sizeof(buf),stdin);
	ch = strtok(buf," ");
	for (i = 0;i < CARD_MAX;i++) {
		if (ch == NULL) {
			break;
		} else {
			cards1[i].suit = ch[0];
			cards1[i].value = ch[1];
		}
		ch = strtok(NULL," ");
	}

	cards_copy(cards1, cards2, CARD_MAX);

	bubble_sort(cards1, card_count);
	selection_sort(cards2,card_count);
	print_cards(cards1, card_count);
	printf("Stable\n");
	print_cards(cards2, card_count);
	printf(cards_compare(cards1,cards2,card_count) == 1 ? "Stable\n" : "Not stable\n");
}

void print_cards(card array[], int array_length){
	for (int i = 0; i < array_length;i++){
		printf("%c%c",array[i].suit,array[i].value);
		if (i < array_length - 1){
			printf(" ");
		} else{
			printf("\n");
		}
	}
}

void bubble_sort(card array[], int array_length){
	for (int i = 0; i < array_length; i++){
		for(int j = array_length - 1; j >= i+1; j--){
			if(array[j].value < array[j-1].value){
				swap(array, j, j-1);
			}
		}
	}
}

void selection_sort(card array[], int array_length){
	for (int i = 0; i < array_length; i++) {
		int mini = i;
		for (int j = i; j < array_length; j++){
			if (array[j].value < array[mini].value){
				mini = j;
			}
		}
		swap(array, i,mini);
	}
}

void swap(card array[], int a, int b){
	card tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

void cards_copy(card original[], card destination[], int original_length){
	for(int i = 0; i < original_length; i++){
		destination[i] = original[i];
	}
}

int cards_compare(card a[], card b[], int length){
	for(int i = 0; i < length; i++){
		if(a[i].suit != b[i].suit || a[i].value != b[i].value) return 0;
	}
	return 1;
}

