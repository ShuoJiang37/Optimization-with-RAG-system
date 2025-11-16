#include<stdio.h>
#include<limits.h>

#define SENTINEL 2000000000

typedef struct box{
	int a;//初期の位置を格納
	int b;//重さ
	int c;//サイクル別にサイクル番号を格納
} num;

long int cnt=0;//case#19で解がint型の最大値を越えるためlongを用いる

void merge(num *A,int left,int mid,int right)//分割した配列を小さい順に結合
{
  int n1 = mid - left;
  int n2 = right - mid;
  num L[n1+1],R[n2+1];
  int k,i,j;
  for (i=0;i<n1;i++) {
  	L[i].a = A[left + i].a;
  	L[i].b = A[left + i].b;
  }
  for (i=0;i<n2;i++) {
  	R[i].a = A[mid + i].a;
  	R[i].b = A[mid + i].b;
  }
  L[n1].b = SENTINEL;//EOF
  R[n2].b = SENTINEL;//EOF
  i = 0;
  j = 0;
    
  for(k=left;k<right;k++){//iが左の要素番号,jが右の要素番号
    if(L[i].b<=R[j].b){//左が小さい場合
      A[k].a = L[i].a;
      A[k].b = L[i].b;
      i=i+1;
    }else{ //右が小さい場合
      A[k].a = R[j].a;
       A[k].b = R[j].b;
      if(L[i].b!=SENTINEL) cnt+=(n1-i);//SENTINELと比較する場合を除いて左側の未ソート部分の要素数をcntに加算
      j = j + 1;
    }
  }
}


void mergeSort(num *A,int left,int right)
{
  int mid,i;
  if(left+1<right){//二分探索のように左端が右端を超えたら終了
    mid = (left + right)/2;
    mergeSort(A, left, mid);//左半分で再帰
    mergeSort(A, mid, right);//右半分で再帰
    merge(A, left, mid, right);//結合
  }
}
int minsearch(num *A,int n,int group)//サイクル外の最小値を返す
{
    int i,min=INT_MAX;
    group--;
    for(i=0;i<n;i++){
        if(A[i].c!=group&&min>A[i].b) min=A[i].b;
    }
    return min;
}

int main(void)
{
    int n,i,j;
    num A[500001];//荷物の情報を格納
    int left,right;
    int box=0,start,sum=0;
    int min=INT_MAX,cnt=0,S,T,group=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++) {
    	scanf("%d",&A[i].b);
    	A[i].a=i;
    	A[i].c=-1;
    }
    
    left=0;
    right=n;
    mergeSort(A,left,right);
    
    for(i=0;i<n;i++)
    {
        if(A[i].c==-1){//サイクルグループに属していない場合
    	    if(i!=A[i].a){//入れ替える必要がある場合サイクルを探索
    		    start=i;
    	    	j=i;
    		    for(;;){
    			    box+=A[j].b;
    			    if(min>A[j].b) min=A[j].b;
    			    A[j].c=group;
    			    cnt++;
    			    if(start==A[j].a){
    			       group++;
    			       break;
    		    	}
    			    j=A[j].a;
    		    }
    	        S=box+min+(cnt+1)*minsearch(A,n,group);// サイクル外から最小値を借りた場合
    	        T=min*(cnt-2)+box;//借りない場合
    	        if(S>T||S<0) sum+=T;
    	        else sum+=S;
            }else{//移動しない場合
    	        A[i].c=group;
    	        group++;
    	    }
    	    min=INT_MAX;
    	    box=0;
    	    cnt=0;
        }
    }
    printf("%d\n",sum);
    return 0;
}
