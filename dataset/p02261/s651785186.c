#include<stdio.h>
#include<string.h>




int main(void)
{
	int n,i,j,p=0;
	char a[40],aa[40],box[3],x=0;
	int b[40],bb[40],y=0,minv,v=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",box);//入力文字をcharとint型配列に分けて格納
		a[i]=box[0];
		b[i]=box[1]-'0';
		aa[i]=a[i];//選択ソート用に別の配列にも格納
		bb[i]=b[i];
	}
	//bubble sort
	for(i=0;i<n-1;){ //i ソート済みの配列番号
		for(j=n-1;j>=i;j--){ //末尾からソート済みまでの範囲をソート
			if(j!=0&&b[j-1]>b[j]){//隣接交換
				y=b[j-1];
				x=a[j-1];
				b[j-1]=b[j];
				a[j-1]=a[j];
				b[j]=y;
				a[j]=x;
				if(b[j-1]==b[j]&&a[j]==a[j-1]) p=1;//bubblesortは同じ値なら入れ替わらないので起こり得ないが、出力の安定か否かを判断
			}
			if(i==j) i++;//ソート済みまでいけばiをインクリメント
			
		}
	}
	
	for(i=0;i<n;i++){
		printf("%c%d",a[i],b[i]);
		if(i!=n-1) printf(" ");
	}
	if(p==0) printf("\nStable\n");
	else printf("\nNot stable\n");
	
	//selection sort
	p=0;
	for(i=0;i<n;i++){//i ソート済みの配列番号
		minv=37;//制約条件より最大値を格納
		for(j=i;j<n;j++){//未ソート部分から最小値を捜索
			if(bb[j]<minv){
				minv=bb[j];
				v=j;
			}
		}
		if(minv!=bb[i]){//最小値が左端でなければ交換
			y=bb[i];
			x=aa[i];
			bb[i]=minv;
		    aa[i]=aa[v];
			bb[v]=y;
			aa[v]=x;
			if(aa[v]==aa[i]) p=1;//出力の安定か否かを判断
		}
	}
	for(i=0;i<n;i++){
		printf("%c%d",aa[i],bb[i]);
		if(i!=n-1) printf(" ");
	}
	if(p==0) printf("\nStable\n");
	else printf("\nNot stable\n");

   	return 0;
}
