#include <stdio.h>
#include <stdlib.h>

#define DIV_INIT 0
#define LOOP_INIT 0
#define G_MAX 12
#define FIRST_ITEM 0
#define ONE 1
#define EXIT_SUCCESS 0
#define PREV_ITEM( x ) x - 1
#define THREE_TIMES( x ) x * 3
#define HALF( x ) x / 2

int main( void )
{
	unsigned long ulW_Dtc_cnt;
	int *aulW_Dtestcase;
	unsigned long ulW_Cloop_cnt;
	unsigned long ulW_Cloop_sub_cnt;
	unsigned long ulW_Csort_cnt = DIV_INIT;
	unsigned long ulW_Dinterval_num = ONE;//?????????????????????????????°
	unsigned long ulW_Dinterval_array[ G_MAX ];//?????????????????????
	unsigned long ulW_Dshell_div;
	signed long slW_Dsort_div;
	unsigned long ulW_Dcalc;

	scanf( "%d", &ulW_Dtc_cnt );
	aulW_Dtestcase = malloc ( sizeof( int ) * ulW_Dtc_cnt );
	for( ulW_Cloop_cnt = LOOP_INIT; ulW_Cloop_cnt < ulW_Dtc_cnt; ulW_Cloop_cnt++ ){
		scanf( "%d", &aulW_Dtestcase[ ulW_Cloop_cnt ] );
	}

	ulW_Dinterval_array[ FIRST_ITEM ] = ONE;
	ulW_Dcalc = THREE_TIMES( ulW_Dinterval_array[ PREV_ITEM( ulW_Dinterval_num ) ] ) + ONE;
	while( ulW_Dcalc < ulW_Dtc_cnt ){
		ulW_Dinterval_array[ ulW_Dinterval_num ] = THREE_TIMES( ulW_Dinterval_array[ PREV_ITEM( ulW_Dinterval_num ) ] ) + ONE;
		ulW_Dinterval_num++;
		ulW_Dcalc = THREE_TIMES( ulW_Dinterval_array[ PREV_ITEM( ulW_Dinterval_num ) ] ) + ONE;
	}

	for( ulW_Cloop_cnt = LOOP_INIT; ulW_Cloop_cnt < HALF( ulW_Dinterval_num ); ulW_Cloop_cnt++ ){
		ulW_Dshell_div = ulW_Dinterval_array[ ulW_Cloop_cnt ];
		ulW_Dinterval_array[ ulW_Cloop_cnt ] = ulW_Dinterval_array[ PREV_ITEM( ulW_Dinterval_num ) - ulW_Cloop_cnt ];
		ulW_Dinterval_array[ PREV_ITEM( ulW_Dinterval_num ) - ulW_Cloop_cnt ] = ulW_Dshell_div;
	}

	printf( "%d\n", ulW_Dinterval_num );
	for( ulW_Cloop_cnt = LOOP_INIT; ulW_Cloop_cnt < ulW_Dinterval_num; ulW_Cloop_cnt++ ){
		if( ulW_Cloop_cnt == PREV_ITEM( ulW_Dinterval_num ) ){
			printf( "%d\n", ulW_Dinterval_array[ ulW_Cloop_cnt ] );
		}
		else{
			printf( "%d ", ulW_Dinterval_array[ ulW_Cloop_cnt ] );
		}
	}

	for( ulW_Cloop_cnt = LOOP_INIT; ulW_Cloop_cnt < ulW_Dinterval_num; ulW_Cloop_cnt++){
		for( ulW_Cloop_sub_cnt = ulW_Dinterval_array[ ulW_Cloop_cnt ]; ulW_Cloop_sub_cnt < ulW_Dtc_cnt; ulW_Cloop_sub_cnt++ ){
			ulW_Dshell_div = aulW_Dtestcase[ ulW_Cloop_sub_cnt ];
			slW_Dsort_div = ulW_Cloop_sub_cnt - ulW_Dinterval_array[ ulW_Cloop_cnt ];
			while( ( slW_Dsort_div >= FIRST_ITEM ) && ( aulW_Dtestcase[ slW_Dsort_div ] > ulW_Dshell_div ) ){
				aulW_Dtestcase[ slW_Dsort_div + ulW_Dinterval_array[ ulW_Cloop_cnt ] ] = aulW_Dtestcase[ slW_Dsort_div ];
				slW_Dsort_div -= ulW_Dinterval_array[ ulW_Cloop_cnt ];
				ulW_Csort_cnt++;
			}
			aulW_Dtestcase[ slW_Dsort_div + ulW_Dinterval_array[ ulW_Cloop_cnt ] ] = ulW_Dshell_div;
		}
	}

	printf( "%d\n", ulW_Csort_cnt );
	for( ulW_Cloop_cnt = LOOP_INIT; ulW_Cloop_cnt < ulW_Dtc_cnt; ulW_Cloop_cnt++ ){
		printf( "%d\n", aulW_Dtestcase[ ulW_Cloop_cnt ] );
	}

	return EXIT_SUCCESS;
}