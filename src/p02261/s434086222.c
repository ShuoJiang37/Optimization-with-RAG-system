#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct card{
	char card_type;
	int card_number;
} card_t;

void swap_operation( card_t *swap_card, int number1, int number2 )
{
	card_t tmp_card;

	tmp_card = swap_card[number1];
	swap_card[number1] = swap_card[number2];
	swap_card[number2] = tmp_card;

}

int main()
{
	int size;
	int roop_i, roop_j;
	card_t Card[36], Card_copy[36];
	int minj;
	char tmp;
	int flag;

	scanf( "%d", &size );
	for ( roop_i = 0 ; roop_i < size ; roop_i++ )
	{
		scanf( "%*c%c%d", &Card[roop_i].card_type, &Card[roop_i].card_number );
		Card_copy[roop_i].card_type = Card[roop_i].card_type;
		Card_copy[roop_i].card_number = Card[roop_i].card_number;
	}
	/* Bubble Sort */
	for ( roop_i = 0 ; roop_i < size ; roop_i++ )
	{
		for ( roop_j = size - 1 ; roop_j > roop_i ; roop_j-- )
		{
			if ( Card[roop_j].card_number < Card[roop_j - 1].card_number )
			{
				swap_operation( Card, roop_j, roop_j - 1 );
			}
		}
	}

	for ( roop_i = 0 ; roop_i < size ; roop_i++ )
	{
		if ( roop_i != size - 1 )
		{
			fprintf( stdout, "%c%d ", Card[roop_i].card_type, Card[roop_i].card_number );
		}
		else
		{
			fprintf( stdout, "%c%d\n", Card[roop_i].card_type, Card[roop_i].card_number );
			fprintf( stdout, "Stable\n" );
		}
	}

	/* Selection Sort */
	flag = 0;
	for ( roop_i = 0 ; roop_i < size ; roop_i++ )
	{
		minj = roop_i;
		for ( roop_j = roop_i ; roop_j < size ; roop_j++ )
		{
			if ( Card_copy[roop_j].card_number < Card_copy[minj].card_number )
			{
				minj = roop_j;
			}
		}
		swap_operation( Card_copy, roop_i, minj );
	}

	/* IsStabel */
	for ( roop_i = 0 ; roop_i < size ;roop_i++ )
	{
		if ( Card[roop_i].card_type != Card_copy[roop_i].card_type )
		{
			flag = 1;
		}
	}

	for ( roop_i = 0 ; roop_i < size ; roop_i++ )
	{
		if ( roop_i != size - 1 )
		{
			fprintf( stdout, "%c%d ", Card_copy[roop_i].card_type, Card_copy[roop_i].card_number );
		}
		else
		{
			fprintf( stdout, "%c%d\n", Card_copy[roop_i].card_type, Card_copy[roop_i].card_number );
			if ( flag == 1 )
			{
				fprintf( stdout, "Not stable\n" );
			}
			else 
			{
				fprintf( stdout, "Stable\n" );
			}
		}
	}

	return 0;
}