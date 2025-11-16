#include <stdio.h>
#include<stdlib.h>

//TODO データが入れ替わったという情報をどうやって保存する？

int stableSortChecker(int arraySize,int sortedArray[],int placeArray[]);
int selectionSort_CustomizedForALDS1_2_C(int arraySize1,int array1[],char charArray[],int placeArray[]);
int bubbleSort_CustomizedForALDS1_2_C(int n,int array1[],char charArray[],int placeArray[]);

int main() {
    int arraySize=0;
    scanf("%d",&arraySize);
    //2回ソートするので、ソートされる配列も2つ用意しておく
    //また、入力される文字は1要素につき2つなので、二倍の容量を確保しておく
    char*charArray1  = (char*)malloc(sizeof(char)*arraySize);
    int *intArray1   =  (int*)malloc( sizeof(int)*arraySize);
    char*charArray2  = (char*)malloc(sizeof(char)*arraySize);
    int *intArray2   =  (int*)malloc( sizeof(int)*arraySize);

    scanf("%*c%c%d",&charArray1[0],&intArray1[0]);
    charArray2[0]=charArray1[0];
    intArray2[0] = intArray1[0];
    for(int i=1;i<arraySize;i++)
    {
        scanf(" %c%d",&charArray1[i],&intArray1[i]);
        //2つ目の被並べ替え配列にも同じ値をセット
        charArray2[i]=charArray1[i];
        intArray2[i] = intArray1[i];
    }
    //配列のコピー完了
    //ここからソートに入る TODO ソートの中身をトランプ用に変更
    
    //ソート順番記憶配列を初期化
    int * startPlaceRememberArray   =  (int*)malloc( sizeof(int)*arraySize);
    for(int i=1;i<arraySize;i++)
    {
        startPlaceRememberArray[i]=i;
    }
    //バブルソート
    bubbleSort_CustomizedForALDS1_2_C(arraySize,intArray1,charArray1,startPlaceRememberArray);
    //TODO 安定なソートか？を判定
    int array1IsSorted=stableSortChecker(arraySize,intArray1,startPlaceRememberArray);

    //ソート順番記憶配列を初期化
    for(int i=0;i<arraySize;i++)
    {
        startPlaceRememberArray[i]=i;
    }
    //選択ソート
    selectionSort_CustomizedForALDS1_2_C(arraySize,intArray2,charArray2,startPlaceRememberArray);
    //TODO 安定なソートか？を判定
    int array2IsSorted = stableSortChecker(arraySize,intArray2,startPlaceRememberArray);
    //TODO 出力処理

    for(int i=0;i<arraySize;i++)
    {
        printf("%c%d",charArray1[i],intArray1[i]);
        if(i==arraySize-1)break;
        printf(" ");
    }
    printf("\n%s\n",array1IsSorted==1?"Stable":"Not stable");
    for(int i=0;i<arraySize;i++)
    {
        printf("%c%d",charArray2[i],intArray2[i]);
        if(i==arraySize-1)break;
        printf(" ");
    }
    printf("\n%s\n",array2IsSorted==1?"Stable":"Not stable");

    //メモリの開放
    free(charArray1);
    free(charArray2);
    free(intArray1);
    free(intArray2);
    free(startPlaceRememberArray);
    return 0;
}
//引数:配列の長さ、ソートされた配列、ソートされた配列の順番を記憶した配列
//返り値:ソートが安定…1ソートが不安定...-1
int stableSortChecker(int arraySize,int sortedArray[],int placeArray[])
{
    for(int i=0;i<arraySize;i++)
    {
        //不安定
        if(sortedArray[i]==sortedArray[i+1]&&placeArray[i]>placeArray[i+1])return -1;
    }
    //安定
    return 1;
}
int selectionSort_CustomizedForALDS1_2_C(int arraySize ,int array[],char charArray[],int placeArray[])
{
    int minPlace=0;
    int flag=0;
    int counter=0;
    //配列の初めから終わりまで精査する
    for(int i=0;i<arraySize;i++)
    {
        flag=0;
        minPlace=i;
        //i番目の精査では、後ろの(arraySize-i)個の配列の要素をチェックする
        for (int j=i+1;j<arraySize;j++)
        {
            //ifの方が高速(らしい)
            //min=array[j]<min?array[j]:min;
            if(array[minPlace]>array[j]) {
                if(flag==0)flag++;
                minPlace = j;
            }
        }
        if(flag>0)
        {
            //intの入れ替え
            flag=array[i];
            array[i] = array[minPlace];
            array[minPlace]=flag;

            char ctmp=charArray[i];
            charArray[i]=charArray[minPlace];
            charArray[minPlace]=ctmp;

            int tmp=placeArray[i];
            placeArray[i]=placeArray[minPlace];
            placeArray[minPlace]=tmp;
            counter++;
        }
    }
    return counter;
}
int bubbleSort_CustomizedForALDS1_2_C(int n,int array[],char charArray[],int placeArray[])
{
    int counter = 0;
    int flag=1;
    while(flag==1)
    {
        flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(array[i]>array[i+1])
            {
                int tmp=array[i];
                array[i]=array[i+1];
                array[i+1]=tmp;

                char ctmp=charArray[i];
                charArray[i]=charArray[i+1];
                charArray[i+1]=ctmp;

                tmp=placeArray[i];
                placeArray[i]=placeArray[i+1];
                placeArray[i+1]=tmp;

                flag=1;
                counter++;
            }
        }
    }
    return counter;
}

