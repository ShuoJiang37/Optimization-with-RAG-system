#include <stdio.h>

int BubbleSort ( int *Arr, int *Order, int Max_order );

int SelectionSort ( int *Arr, int *Order, int Max_order );

int Judge_stable ( int *Arr, int *Order, int Max_order );

int Display_Arr ( char *name, int *Arr, int *Order, int Max_order );


int main(void)
{
    int     Max_order       = 0;
    int     Card_value[36]  = {};
    char    Card_name[36]   = {};
    int     Order[36]       = {};
    int     i               = 0;
    int     Judge_Bubble    = 0;
    int     Judge_Selection = 0;
    
    for ( i = 0; i < 36; i++ ) {
        Order[i] = i;
    }
    
    scanf ( "%d\n", &Max_order );
    
    for ( i = 0; i < Max_order; i++ ) {
        scanf( "%c%d ", &Card_name[i], &Card_value[i] );
    }
    

    BubbleSort( Card_value, Order, Max_order );
    
    Judge_Bubble = Judge_stable( Card_value, Order, Max_order );

        
    Display_Arr( Card_name, Card_value, Order, Max_order );
    
    if ( Judge_Bubble == 0 ) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
    
    
    for ( i = 0; i < 36; i++ ) {
        Order[i] = i;
    }

    SelectionSort( Card_value, Order, Max_order );
    
    Judge_Selection = Judge_stable( Card_value, Order, Max_order );


    Display_Arr( Card_name, Card_value, Order, Max_order );
    
    if ( Judge_Selection == 0 ) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }    
    
    
    return 0;
}

int BubbleSort ( int *Arr, int *Order, int Max_order )
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    
    for ( i = 0; i < Max_order; i++ ) {
        for ( j = Max_order - 1; j > i; j-- ) {
            if ( Arr[Order[j]] < Arr[Order[j-1]] ) {
                tmp = Order[j];
                Order[j] = Order[j-1];
                Order[j-1] = tmp;
            }
        }
    }
    
    return 0;
}

int SelectionSort ( int *Arr, int *Order, int Max_order )
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int  mini = 0;
    
    for ( i = 0; i < Max_order; i++ ) {
        mini = i;
        for ( j = i; j < Max_order; j++ ) {
            if ( Arr[Order[j]] < Arr[Order[mini]] ) {
                mini = j;
            }
            
            
        }
        tmp = Order[i];
        Order[i] = Order[mini];
        Order[mini] = tmp;
    }
    
    
    return 0;
}

int Judge_stable ( int *Arr, int *Order, int Max_order )
{
    int number_for_comp = 1;
    int indexes_of_the_same_value[10][5] ={};
    int count_of_indexes = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int target_index[4] = {};
    int stable = 0;
    
    /*元のデータから同じ値をとる添え字を格納する*/
    for ( number_for_comp = 1; number_for_comp < 10; number_for_comp++ ) {
        count_of_indexes = 0;
        for ( i = 0; i < Max_order; i++ ) {
            
            if ( Arr[i] == number_for_comp) {
                
                indexes_of_the_same_value[number_for_comp][count_of_indexes] = i;
                count_of_indexes++;
            }
            
        }
        indexes_of_the_same_value[number_for_comp][4] = count_of_indexes;
        //printf("count of indexes: %d\n", count_of_indexes);
    }
    
    /*同じ値の添え字が入れ替わったのかを確認する*/
    stable = 0;
    for ( number_for_comp = 1; number_for_comp < 10; number_for_comp++ ) {
        if ( indexes_of_the_same_value[number_for_comp][4] < 2 ) {
            continue;
        }
        
        /*判断に使う添え字をそろえる*/
        k = 0;
        for ( j = 0; j < indexes_of_the_same_value[number_for_comp][4]; j++ ) {
            for ( i = 0; i < Max_order; i++ ) {
                if ( Order[i] == indexes_of_the_same_value[number_for_comp][j] ) {
                    target_index[k] = i;
                    //printf("%d count of indexes: %d\n", number_for_comp, target_index[k]);
                    k++;
                }
            }
        }
        
        
        for ( k = 0; k < indexes_of_the_same_value[number_for_comp][4]; k++ ) {
            for ( j = k+1; j < indexes_of_the_same_value[number_for_comp][4]; j++ ) {
                if ( target_index[k] > target_index[j] ) {
                    stable = 1;
                    //printf("target_index: %d\n", target_index[k]);
                    break;
                }
            }
            if (stable == 1) {
                break;
            }
        }
        
        if (stable == 1) {
            //printf("target_index: %d\n", target_index[k]);
            //printf("target_index: %d\n", stable);
            break;
        }
        
    }
    //printf("target_index: %d\n", stable);
    return stable;
    
}

int Display_Arr ( char *name, int *Arr, int *Order, int Max_order )
{
    int i = 0;
    for ( i = 0; i < Max_order-1; i++ ) {
        printf("%c%d ", name[Order[i]], Arr[Order[i]]);
    }
    
    printf("%c%d\n", name[Order[i]], Arr[Order[i]]);
    
    return 0;
}
