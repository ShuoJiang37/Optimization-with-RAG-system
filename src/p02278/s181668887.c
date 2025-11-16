#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,ans = 0,mi,cnt,now,sum,tmp;
    int mini = 10000; /* 最大値は10の4乗 */

    
    scanf("%d",&n); /* n個(1<=n<=1000)で全て異なる値 */
    
    int *W = malloc(sizeof(int)*n);
    memset(W,0,n);
    
    int *done = malloc(sizeof(int)*n);
    memset(done,0,n);
//    int mp[1010];
    int mp[1000];
    
    for( i=0 ; i<n ; i++ )
    {
        scanf("%d",&W[i]);
        if(W[i] < mini)
        {
            mini = W[i]; /* 最小に設定 */
        }
//        mp[W[i]] = 0;
        mp[i] = W[i]; /* W[i]は全て異なる値 */
    }
    
    /* mp[]を昇順にバブルソート */
    for( i=0 ; i<n; i++ )
    {
        for( j=1; j<n-i; j++ )
        {
            if( mp[j] < mp[j-1] )
            {
                tmp = mp[j];
                mp[j] = mp[j-1];
                mp[j-1] = tmp;
            }
        }
    }
    
    for( i=0 ; i<n ; i++)
    {
        if (done[i]==1) continue; /* 処理済なら次 */
        
//        cnt = 0,now = i, mi = 100000, sum = 0;
        cnt = 0;
        now = i;
        mi = 10000;
        sum = 0;

        while(1)
        {
            if (done[now]==1) break; /* 処理済ならループを抜ける */
            cnt++;
            done[now] = 1; /* 処理済 */
            if(W[now] < mi)
            {
                mi = W[now]; /* 最小値に設定 */
            }
            sum += W[now];

            for( j=0 ; j<n ; j++ )
            {
                if( mp[j] == W[now] )
                {
                    /* 検索 */
                    now = j;
                    break;
                }
            }
//            now = mp[W[now]];
        }

        if( (sum+(cnt-2)*mi) < (sum+mi+mini*(cnt+1)) )
        {
            tmp = sum+(cnt-2)*mi;
        }
        else
        {
            tmp = sum+mi+mini*(cnt+1);
        }
        ans += tmp;
    }
    
    printf("%d\n",ans);

    free(done);
    free(W);
    
    return 0;
}
