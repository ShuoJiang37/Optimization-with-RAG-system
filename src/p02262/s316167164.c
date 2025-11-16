#include <stdio.h>
#include <stdlib.h>

#define ARRAY_INIT 0
#define DIV_INIT 0
#define LOOP_INIT 0
#define G_MAX 12
#define FIRST_ITEM 0
#define EXIT_SUCCESS 0

int main( void )
{
	unsigned long ulW_Dtc_cnt;
	int *aulW_Dtestcase;
	unsigned long ulW_Cloop_cnt;
	unsigned long ulW_Cloop_sub_cnt;
	unsigned long ulW_Csort_cnt = DIV_INIT;
	unsigned long ulW_Dm = 1;//?????????????????????????????°
	unsigned long aulW_DG[ G_MAX ];//?????????????????????
	unsigned long ulW_Dv;
	signed long slW_Dk;
	unsigned long ulW_Dcalc;

	scanf( "%d", &ulW_Dtc_cnt );
	aulW_Dtestcase = malloc ( sizeof( int ) * ulW_Dtc_cnt );
	for( ulW_Cloop_cnt = LOOP_INIT; ulW_Cloop_cnt < ulW_Dtc_cnt; ulW_Cloop_cnt++ ){
		scanf( "%d", &aulW_Dtestcase[ ulW_Cloop_cnt ] );
	}

	aulW_DG[ FIRST_ITEM ] = 1;
	ulW_Dcalc = 3 * aulW_DG[ ulW_Dm - 1 ] + 1;
	while( ulW_Dcalc < ulW_Dtc_cnt ){
		aulW_DG[ ulW_Dm ] = 3 * aulW_DG[ ulW_Dm - 1 ] + 1;
		ulW_Dm++;
		ulW_Dcalc = 3 * aulW_DG[ ulW_Dm - 1 ] + 1;
	}

	for( ulW_Cloop_cnt = LOOP_INIT; ulW_Cloop_cnt < ulW_Dm / 2; ulW_Cloop_cnt++ ){
		ulW_Dv = aulW_DG[ ulW_Cloop_cnt ];
		aulW_DG[ ulW_Cloop_cnt ] = aulW_DG[ ulW_Dm - 1 - ulW_Cloop_cnt ];
		aulW_DG[ ulW_Dm - 1 - ulW_Cloop_cnt ] = ulW_Dv;
	}

	printf( "%d\n", ulW_Dm );
	for( ulW_Cloop_cnt = LOOP_INIT; ulW_Cloop_cnt < ulW_Dm; ulW_Cloop_cnt++ ){
		if( ulW_Cloop_cnt == ulW_Dm - 1 ){
			printf( "%d\n", aulW_DG[ ulW_Cloop_cnt ] );
		}
		else{
			printf( "%d ", aulW_DG[ ulW_Cloop_cnt ] );
		}
	}

	for( ulW_Cloop_cnt = LOOP_INIT; ulW_Cloop_cnt < ulW_Dm; ulW_Cloop_cnt++){
		for( ulW_Cloop_sub_cnt = aulW_DG[ ulW_Cloop_cnt ]; ulW_Cloop_sub_cnt < ulW_Dtc_cnt; ulW_Cloop_sub_cnt++ ){
			ulW_Dv = aulW_Dtestcase[ ulW_Cloop_sub_cnt ];
			slW_Dk = ulW_Cloop_sub_cnt - aulW_DG[ ulW_Cloop_cnt ];
			while( ( slW_Dk >= 0 ) && ( aulW_Dtestcase[ slW_Dk ] > ulW_Dv ) ){
				aulW_Dtestcase[ slW_Dk + aulW_DG[ ulW_Cloop_cnt ] ] = aulW_Dtestcase[ slW_Dk ];
				slW_Dk -= aulW_DG[ ulW_Cloop_cnt ];
				ulW_Csort_cnt++;
			}
			aulW_Dtestcase[ slW_Dk + aulW_DG[ ulW_Cloop_cnt ] ] = ulW_Dv;
		}
	}

	printf( "%d\n", ulW_Csort_cnt );
	for( ulW_Cloop_cnt = LOOP_INIT; ulW_Cloop_cnt < ulW_Dtc_cnt; ulW_Cloop_cnt++ ){
		printf( "%d\n", aulW_Dtestcase[ ulW_Cloop_cnt ] );
	}

	return EXIT_SUCCESS;
}