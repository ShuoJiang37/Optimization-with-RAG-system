#include <stdio.h>
#include <string.h>


void bubbleSort( char A[][3], char B[][3], int N )
{
    char tmp[3];

	for ( int i = 0; i < N; i++ ) {
    	memcpy( B[i], A[i], 3 );
	}

    for ( int i = 0; i < N; i++ ) {
        for ( int j = N - 1; j >= i + 1; j-- ) {
            if ( B[j][1] < B[j - 1][1] ) {
               memcpy( tmp, B[j], 3 );
               memcpy( B[j], B[j - 1], 3 );
               memcpy( B[j - 1], tmp, 3);
            }
        }
    }
}

void selectionSort( char A[][3], char C[][3], int N )
{
    int minj;
    char tmp[3];

	for ( int i = 0; i < N; i++ ) {
    	memcpy( C[i], A[i], 3 );
	}

    for ( int i = 0; i < N; i++ ) {
        minj = i;
        for ( int j = i + 1; j < N; j++ ) {
            if ( C[j][1] < C[minj][1] ) {
                minj = j;
            }
        }
        if ( minj != i ) {
            memcpy( tmp, C[i], 3 );
            memcpy( C[i], C[minj], 3 );
            memcpy( C[minj], tmp, 3);
        }
    }
}

int isStable( char in[][3], char out[][3], int N )
{
    for ( int i = 0; i < N; i++ ) {
        for ( int j = i + 1; j < N; j++ ) {
            for ( int a = 0; a < N; a++ ) {
                for ( int b = a + 1; b < N; b++ ) {
                    if ( ( in[i][1] == in[j][1] ) && ( strcmp( in[i], out[b] ) == 0 ) && ( strcmp( in[j], out[a] ) == 0 ) ) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main(void)
{
    int N;
    char A[36][3];
    char B[36][3];
    char C[36][3];

    scanf("%d", &N);
    
    for ( int i = 0; i < N; i++ ) {
        scanf("%s", A[i]);
    }
    
    bubbleSort( A, B, N );
	for ( int i = 0; i < N; i++ ) {
        printf("%s", B[i]);
        if ( i != N - 1 ) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    if ( isStable( A, B, N ) == 1 ) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
    
    selectionSort( A, C, N );
    for ( int i = 0; i < N; i++ ) {
        printf("%s", C[i]);
        if ( i != N - 1 ) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    if ( isStable( A, C, N ) == 1 ) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
    
    return 0;
}
