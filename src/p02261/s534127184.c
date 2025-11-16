#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct CARD {
	int seqno;
	char suit;
	int number;

} CARD;

void swap_ref(CARD **p1, CARD **p2){
	CARD *tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

typedef int (*CARD_CHECKER)(CARD *p1, CARD *p2);

int sort_by_number_asc(CARD *p1, CARD *p2){
	return p1->number - p2->number;
}

int sort_by_seqno_asc(CARD *p1, CARD *p2){
	return p1->seqno - p2->seqno;
}

typedef int (*CARD_REF_SORTER)(CARD **card_ref_list, int size, CARD_CHECKER checker);

int bubble_sort(CARD **card_ref_list, int size, CARD_CHECKER checker){
	int swap_count = 0;
	int i,j;

	for(i=0;i<size;i++){
		for(j=size-1;j>i;j--){
			if( checker( card_ref_list[j], card_ref_list[j-1] ) < 0 ){
				swap_ref( card_ref_list + j, card_ref_list + j - 1 );
				swap_count++;
			}
		}
	}

	return swap_count;
}

int select_sort(CARD **card_ref_list, int size, CARD_CHECKER checker){
	int swap_count = 0;
	int i,j,minj;

	for(i=0;i<size;i++){
		minj = i;
		for(j=i;j<size;j++){
			if( checker( card_ref_list[j], card_ref_list[minj] ) < 0 ){
				minj = j;
			}
		}
		if( i != minj ){
			swap_ref( card_ref_list + i, card_ref_list + minj );
			swap_count++;
		}
	}

	return swap_count;
}

void print_card_ref_list(CARD **card_ref_list, int size){
	int i;
	for(i=0;i<size;i++){
		if( i >= 1 ){
			putchar(' ');
		}
		// printf("[%d]",card_ref_list[i]->seqno);
		printf("%c",card_ref_list[i]->suit);
		printf("%d",card_ref_list[i]->number);
	}
	putchar('\n');
}

int is_stable(CARD **card_ref_list, int size, CARD_CHECKER checker){
	int i;
	int check_result;

	for(i=0;i<size-1;i++){
		check_result = checker(card_ref_list[i], card_ref_list[i+1]);
		if( check_result > 0 ){
			// Not Stable
			return 0;
		} else if( check_result < 0 ){
			// Stable -> Check Next
		} else {
			if( sort_by_seqno_asc( card_ref_list[i], card_ref_list[i+1] ) > 0 ){
				// Not Stable
				return 0;
			} else {
				// Stable -> Check Next
			}
		}
	}

	return 1;
}

int main(int argc, char** argv){
	CARD_REF_SORTER card_ref_sorter_list[] = { bubble_sort, select_sort };
	int n;
	CARD *card_list,**card_ref_list;
	int i;
	char s[3];

	// Input & Create CARD List
	scanf("%d",&n);
	card_list = malloc(sizeof(CARD)*n);
	card_ref_list = malloc(sizeof(CARD*)*n);
	for(i=0;i<n;i++){
		scanf("%2s",s);
		card_list[i].seqno = i;
		card_list[i].suit = s[0];
		card_list[i].number = atoi(s+1);
		card_ref_list[i] = &card_list[i];
	}

	// Sort & Check
	for(i=0;i<sizeof(card_ref_sorter_list)/sizeof(CARD_REF_SORTER);i++){
		// Sort
		card_ref_sorter_list[i](card_ref_list, n, sort_by_number_asc);
		// Output Sorte d List
		print_card_ref_list(card_ref_list, n);
		// Check Stable or Not
		if( is_stable(card_ref_list, n, sort_by_number_asc) ){
			printf("Stable\n");	
		} else {
			printf("Not stable\n");	
		}
		// Reset List
		card_ref_sorter_list[i](card_ref_list, n, sort_by_seqno_asc);
	}

	// Delete CARD List
	free(card_list);
	free(card_ref_list);

	return 0;
}