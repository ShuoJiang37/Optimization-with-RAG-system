#include <stdio.h>

#define TRUE 1
#define VER_INIT 0
#define LOOP_INIT 0
#define ARRAY_INIT 0
#define CARD_ARRAY_MAX 36
#define EXIT_SUCCESS 0
#define PREV_ITEM( x ) x - 1

int main( void )
{
	unsigned char ubW_Dcard_cnt;
	unsigned char aubW_Dbubble_mark[ CARD_ARRAY_MAX ] = { ARRAY_INIT };
	unsigned char aubW_Dbubble_num[ CARD_ARRAY_MAX ] = { ARRAY_INIT };
	unsigned char aubW_Dselect_mark[ CARD_ARRAY_MAX ] = { ARRAY_INIT };
	unsigned char aubW_Dselect_num[ CARD_ARRAY_MAX ] = { ARRAY_INIT };
	unsigned char ubW_Dtrade_num = VER_INIT;
	unsigned char ubW_Dtrade_mark = VER_INIT;
	unsigned char ubW_Dcard_min;
	unsigned char ubW_Cloop_cnt;
	unsigned char ubW_Cloop_cnt_sub;
	unsigned char ubW_Cstable_cnt = VER_INIT;

	scanf( "%d", &ubW_Dcard_cnt );
	for( ubW_Cloop_cnt = LOOP_INIT; ubW_Cloop_cnt < ubW_Dcard_cnt; ubW_Cloop_cnt++ ){
		scanf( " %c%d", &aubW_Dbubble_mark[ ubW_Cloop_cnt ], &aubW_Dbubble_num[ ubW_Cloop_cnt ] );
		aubW_Dselect_mark[ ubW_Cloop_cnt ] = aubW_Dbubble_mark[ ubW_Cloop_cnt ];
		aubW_Dselect_num[ ubW_Cloop_cnt ] = aubW_Dbubble_num[ ubW_Cloop_cnt ];
	}

	/* ?????????????????? */
	for( ubW_Cloop_cnt = LOOP_INIT; ubW_Cloop_cnt < ubW_Dcard_cnt; ubW_Cloop_cnt++ ){
		for( ubW_Cloop_cnt_sub = PREV_ITEM( ubW_Dcard_cnt ); ubW_Cloop_cnt_sub > ubW_Cloop_cnt; ubW_Cloop_cnt_sub-- ){
			if( aubW_Dbubble_num[ ubW_Cloop_cnt_sub ] < aubW_Dbubble_num[ PREV_ITEM( ubW_Cloop_cnt_sub ) ] ){
				ubW_Dtrade_num = aubW_Dbubble_num[ ubW_Cloop_cnt_sub ];
				ubW_Dtrade_mark = aubW_Dbubble_mark[ ubW_Cloop_cnt_sub ];
				
				aubW_Dbubble_num[ ubW_Cloop_cnt_sub ] = aubW_Dbubble_num[ PREV_ITEM( ubW_Cloop_cnt_sub ) ];
				aubW_Dbubble_mark[ ubW_Cloop_cnt_sub ] = aubW_Dbubble_mark[ PREV_ITEM( ubW_Cloop_cnt_sub ) ];
				
				aubW_Dbubble_num[ PREV_ITEM( ubW_Cloop_cnt_sub ) ] = ubW_Dtrade_num;
				aubW_Dbubble_mark[ PREV_ITEM( ubW_Cloop_cnt_sub ) ] = ubW_Dtrade_mark;
			}
		}
	}
	/* ??????????????????????????? */

	/* ??????????????? */
	for( ubW_Cloop_cnt = LOOP_INIT; ubW_Cloop_cnt < ubW_Dcard_cnt; ubW_Cloop_cnt++ ){
		ubW_Dcard_min = ubW_Cloop_cnt;
		for( ubW_Cloop_cnt_sub = ubW_Cloop_cnt; ubW_Cloop_cnt_sub < ubW_Dcard_cnt; ubW_Cloop_cnt_sub++ ){
			if( aubW_Dselect_num[ ubW_Cloop_cnt_sub ] < aubW_Dselect_num[ ubW_Dcard_min ] ){
				ubW_Dcard_min = ubW_Cloop_cnt_sub;
			}
			else{
				/* else?????????????????????????????\ */
			}
		}
		if( ubW_Cloop_cnt != ubW_Dcard_min ){
			ubW_Dtrade_num = aubW_Dselect_num[ ubW_Cloop_cnt ];
			ubW_Dtrade_mark = aubW_Dselect_mark[ ubW_Cloop_cnt ];

			aubW_Dselect_num[ ubW_Cloop_cnt ] = aubW_Dselect_num[ ubW_Dcard_min ];
			aubW_Dselect_mark[ ubW_Cloop_cnt ] = aubW_Dselect_mark[ ubW_Dcard_min ];

			aubW_Dselect_num[ ubW_Dcard_min ] = ubW_Dtrade_num;
			aubW_Dselect_mark[ ubW_Dcard_min ] = ubW_Dtrade_mark;
		}
	}
	/* ???????????????????????? */

	for( ubW_Cloop_cnt = LOOP_INIT; ubW_Cloop_cnt < ubW_Dcard_cnt; ubW_Cloop_cnt++ ){
		if( aubW_Dbubble_mark[ ubW_Cloop_cnt ] != aubW_Dselect_mark[ ubW_Cloop_cnt ] ){
			ubW_Cstable_cnt++;
		}
	}
	for( ubW_Cloop_cnt = LOOP_INIT; ubW_Cloop_cnt < PREV_ITEM( ubW_Dcard_cnt ); ubW_Cloop_cnt++ ){
		printf( "%c%d ", aubW_Dbubble_mark[ ubW_Cloop_cnt ], aubW_Dbubble_num[ ubW_Cloop_cnt ] );
	}
	printf( "%c%d\n", aubW_Dbubble_mark[ PREV_ITEM( ubW_Dcard_cnt ) ], aubW_Dbubble_num[ PREV_ITEM( ubW_Dcard_cnt ) ] );
	printf("Stable\n");
	for( ubW_Cloop_cnt = LOOP_INIT; ubW_Cloop_cnt < PREV_ITEM( ubW_Dcard_cnt ); ubW_Cloop_cnt++ ){
		printf( "%c%d ", aubW_Dselect_mark[ ubW_Cloop_cnt ], aubW_Dselect_num[ ubW_Cloop_cnt ]);
	}
	printf( "%c%d\n", aubW_Dselect_mark[ PREV_ITEM( ubW_Dcard_cnt ) ], aubW_Dselect_num[ PREV_ITEM( ubW_Dcard_cnt ) ]);
	if( ubW_Cstable_cnt >= TRUE ){
		printf( "Not stable\n" );
	}
	else{
		printf( "Stable\n" );
	}
	return EXIT_SUCCESS;
}