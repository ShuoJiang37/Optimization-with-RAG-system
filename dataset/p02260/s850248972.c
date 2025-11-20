#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
        int input_num, out_i, in_i;
        int array[100], min, tmp;
        int sorted_seq = 0;

        scanf("%d", &input_num);

        for ( in_i = 0 ; in_i < input_num ; in_i++ )
        {
                scanf("%d", &array[in_i]);
        }

        /*Selection sort*/
        for ( out_i = 0 ; out_i < input_num ; out_i++ )
        {
                min = out_i;
                for ( in_i = out_i ; in_i < input_num ; in_i++ )
                {
                        if ( array[in_i] < array[min] )
                                min = in_i;
                }

                if ( out_i != min )
                {
                        tmp = array[out_i];
                        array[out_i] = array[min];
                        array[min] = tmp;
                        sorted_seq = sorted_seq + 1;
                }
        }

        for ( in_i = 0 ; in_i < input_num ; in_i++ )
        {
                if ( in_i == input_num - 1 )
                        fprintf( stdout, "%d\n", array[in_i] );
                else 
                        fprintf( stdout, "%d ", array[in_i] );
        }
        fprintf( stdout, "%d\n", sorted_seq );

        return 0;
}