#include <stdio.h>
#include <string.h>
/*!!!Char_A[n][3] = { "絵柄" "番号" "¥0" } すなわち*/
/*!!!Char_A[n][3] =  [ 0 ]  [ 1 ] [ 3 ] */

void Buble_Sort( int N ,char Char_A[][3] ) {
    
    /*Buble Sort*/
    int flag = 1;
    int i = 0;
    int j;
    char temp[1][3];
    
    do {
        flag = 0;
        for ( j = N - 1 ; j >= i + 1 ; j-- ) {
            if ( Char_A[j - 1][1] > Char_A[j][1] ) {
                /*swap*/
                strcpy(temp[0] ,Char_A[j - 1]);
                strcpy(Char_A[j - 1] ,Char_A[j]);
                strcpy(Char_A[j] ,temp[0]);
                flag = 1;
            }
        }
        i++;
    }while ( flag == 1 );
    
}

void Selection_Sort( int N ,char Char_A[][3] ){
    
    /*Selection Sort*/
    int minj;
    int i ,j ,k;
    char temp[1][3];
    
    for ( i = 0 ; i < N ; i++) {
        /*未ソート部分の先頭の要素をとりあえずminjにしてループjを開始し、要素内の最小要素を取り出す*/
        minj = i;
        for ( j = i ; j < N ; j++ ) {
            /*minjに要素の中で一番小さいものを代入*/
            if ( Char_A[minj][1] > Char_A[j][1] )
                minj = j;
        }
        /*で先頭要素A[i]と要素中の最小要素minjをswap(ただし選択した先頭要素が最小値minjだった場合、ソートはされない)*/
        if ( i != minj ) {
                strcpy(temp[0] ,Char_A[i]);
                strcpy(Char_A[i] ,Char_A[minj]);
                strcpy(Char_A[minj] ,temp[0]);
        }
    }
}

/*元の配列、ソート後の配列を比較し、元の手札とソート後の手札が一致した番号の絵柄が全て一緒なら安定なので1、そうでなければ不安定ということで-1を返す*/
/*const はconstを宣言した段階(今回はこの安定判定の関数内)で、それが一定(配列が一定＝要するに配列の中身を変えることはできない＝strcpyなどで他の配列からペーストしたりすることはできない)ということ*/
int Stable_Judge( int N ,const char Before_Sort_Char[][3] , char After_Sort_Char[][3] ) {
    
    for ( int i = 0 ; i < N ; i++ ) {
        for ( int j = 0 ; j < N ; j++ ){
            /*(同じカードが二枚入っていることがないので、もし順番が変わっていないなら（最初にくる番号Nの絵柄が同じなら、OKなので二枚目に進むから）breakでOK)*/
            if ( Before_Sort_Char[i][1] == After_Sort_Char[j][1] && Before_Sort_Char[i][0] == After_Sort_Char[j][0] ) {
                /*調査済みのものは塗りつぶす*/
                After_Sort_Char[j][0] = 'T';
                After_Sort_Char[j][1] = 'T';
                break;
            }
            else if ( Before_Sort_Char[i][1] == After_Sort_Char[j][1] && Before_Sort_Char[i][0] != After_Sort_Char[j][0] )
                return -1;
                
        }
    }
    /*全てクリアしていれば安定ということがわかるから1を返す*/
    return 1;
    
}

/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/

int main(void)
{
    int n ,m;
    
    /*Nの入力*/
    do {
        scanf("%d" , &n);
    }while ( n < 1 || n > 36 );
    
    /*配列の生成*/
    char Char_A[n][3];
    
    for ( m = 0 ; m < n ; m++) {
            scanf("%s" ,Char_A[m]);
    }
    
/*-----------------------------------------------------------------------*/
    
    /*安定か判定するため、元のコピーを作成(Cではstrcpyを使う)*/
    char Copy_Char_C[n][3];

    for ( int x = 0 ; x < n ; x++) {
        strcpy(Copy_Char_C[x] ,Char_A[x]);
    }
    /*コピーの作成完了*/
    
    
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

    /*バブルソート*/
    Buble_Sort( n ,Char_A);
    
    /*バブルソート結果の表示*/
    for (int s = 0 ; s < n - 1 ; s++ )
        printf("%s " , Char_A[s]);
    /*最後の一つ*/
    printf("%s\n" , Char_A[n - 1]);
    
/*------------------------------------------------------*/

    /*安定の判定*/
    if ( Stable_Judge( n ,Copy_Char_C ,Char_A ) == 1 ) {
        /*安定判定の出力*/
        puts("Stable");
    }
    else if ( Stable_Judge( n ,Copy_Char_C ,Char_A ) == -1 ) {
        /*安定判定の出力*/
        puts("Not stable");
    }

/*-----------------------------------------------------------------------*/
    
    /*選択ソートのためにAたちを元に戻す*/
    for ( int y = 0 ; y < n ; y++) {
        strcpy(Char_A[y] ,Copy_Char_C[y]);
    }
    /*コピーの作成完了*/
    
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
    
    /*選択ソート*/
    Selection_Sort( n ,Char_A);
    
    /*選択ソート結果の表示*/
    for (int s = 0 ; s < n - 1 ; s++ )
        printf("%s " , Char_A[s]);
    /*最後の一つ*/
    printf("%s\n" , Char_A[n - 1]);
    
    /*------------------------------------------------------*/
    
    /*安定の判定*/
    if ( Stable_Judge( n ,Copy_Char_C ,Char_A ) == 1 ) {
        /*安定判定の出力*/
        puts("Stable");
    }
    else if ( Stable_Judge( n ,Copy_Char_C ,Char_A ) == -1 ) {
        /*安定判定の出力*/
        puts("Not stable");
    }

/*-----------------------------------------------------------------------*/
    
    return 0;
}

