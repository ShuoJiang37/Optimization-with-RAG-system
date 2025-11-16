#include<stdio.h>
int g[1000],top=1,cnt=0,n;
void add(){
    while(g[top]*3+1<n){  
        top++;
        g[top]=g[top-1]*3+1;
    }
}
void sort(int a[],int g){//挿入ソート
    int v,i,j;
    for(i=g+1;i<=n;i++){
        v=a[i];
        j=i-g;
        while(j>=1&&a[j]>v){
            a[j+g]=a[j];
            j-=g;
            cnt++;
        }
        a[j+g]=v;
    }
}
int main(){
    int i;
    scanf("%d",&n);
	int a[n];
    g[1]=1;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);//入力で与えらえるAの数列
    add();//飛ばし飛ばしでA[]の数列の要素をとってきてg配列を作成
    for(i=top;i>=1;i--)//A配列をソートする
        sort(a,g[i]);
    printf("%d\n",top);//g配列の要素数を出力
    for(i=top;i>=1;i--)//g配列の全要素を出力
        printf("%d ",g[i]);
    printf("\n");
    printf("%d\n",cnt);//入れ替え回数を表示
    for(i=1;i<=n;i++)
        printf("%d\n",a[i]);
    return 0;
}


