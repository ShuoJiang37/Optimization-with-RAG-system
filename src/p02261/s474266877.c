#include <stdio.h>
#include <stdlib.h>

typedef struct card_
{
    char SHCD;
    int num;
}card;

void cardPrint(card*,card*,int,int);

void cardPrint(card *C,card *C_cp,int n,int flg){
    for(int i=0;i<n;i++)
    {
        if(C[i].num == C[i+1].num && flg == 0)
        {
            for(int j=0;j<n;j++)
            {
                if(C[i].SHCD == C_cp[j].SHCD&&C[i].num==C_cp[j].num)
                {
                    break;
                }else if(C[i+1].SHCD == C_cp[j].SHCD&&C[i+1].num==C_cp[j].num)
                {
                    flg = 1;
                    break;
                }
            }
        }
        if(i != n-1)    printf("%c%d ",C[i].SHCD,C[i].num);
        else printf("%c%d\n",C[i].SHCD,C[i].num);
    }
    if(flg == 1)
    {
        printf("Not stable\n");
    }else
    {
        printf("Stable\n");
    }
}

int main()
{
    int n,nums,flg = 0,minj;
    char SHCDs;
    scanf("%d",&n);
    if(n > 36) return 0;
    card *C = malloc(sizeof(card)*n);
    card *C_cp = malloc(sizeof(card)*n);
    card tmp;
    for(int i = 0;i<n;i++)
    {
        scanf(" %c%d",&SHCDs,&nums);
        C[i].SHCD = SHCDs;
        C[i].num = nums;
        C_cp[i].SHCD = SHCDs;
        C_cp[i].num = nums;
    }
    for(int i = 0;i<n-1;i++)
    {
        for(int j = n-1;j>=i+1;j--)
        {
            if(C[j].num < C[j-1].num)
            {
                tmp = C[j];
                C[j] = C[j-1];
                C[j-1] = tmp;
            }
        }
    }
    cardPrint(C,C_cp,n,flg);
    for(int i=0;i<n;i++)
    {
        C[i] = C_cp[i];
    }
    for(int i = 0;i < n;i++)
    {
        minj = i;
        for(int j = i;j < n;j++)
        {
            if(C[j].num< C[minj].num)
            {
                minj = j;
            }
        }
        tmp = C[i];
        C[i] = C[minj];
        C[minj] = tmp;
    }
    cardPrint(C,C_cp,n,flg);
    free(C_cp);
    free(C);
    return 0;
}
