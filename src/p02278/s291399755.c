#include<stdio.h>
#define vMAX 10001
#define INF (1<<30)
#define min(a,b) (a<b? a:b)
int n;

int A[1000],B[1000],L[550],R[550],sortedPos[vMAX], visited[1000];

//{{{ merge
void merge(int* A, int l, int mid, int r){
	int n1,n2,i,j,k;
	n1=mid-l;	n2=r-mid;
	for(i=0;i<n1;i++){
		L[i]=A[l+i];
	}
	for(int i=0;i<n2;i++){
		R[i]=A[mid+i];
	}
	L[n1]=R[n2]=INF;

	i=j=0;
	for(k=l;k<r;k++){
		if(L[i]<=R[j]){
			A[k]=L[i++];
		}else{
			A[k]=R[j++];
		}
	}
}

void MergeSort(int* A, int l, int r){
	int mid;
	if(r-l>1){
		mid=(l+r)/2;
		MergeSort(A,l,mid);
		MergeSort(A,mid,r);
		merge(A,l,mid,r);
	}
}

//}}}

int main(){
	int i,now,sum,cnt,m,smallest=INF,ans=0;
	for(i=0;i<vMAX;i++)sortedPos[vMAX]=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
		smallest=min(A[i],smallest);
		B[i]=A[i];
	}
	MergeSort(B,0,n);
	for(i=0;i<n;i++){
		sortedPos[B[i]]=i;
	}

	
	for(int i=0;i<n;i++){
		now=i;	sum=0;	cnt=0;	m=INF;
		if(visited[now])continue;
		while(1){
			//printf("%d->",A[now]);
			visited[now]=1;
			sum+=A[now];	cnt++;
			m=min(m,A[now]);

			now=sortedPos[A[now]];
			if(visited[now])break;
		}
		//printf("\n");
		/*
			A:sum+(cnt-2)*m

			B:sum+(cnt-2)*m
				+2*(smallest+m)
					-(cnt-1)(m-smallest)

				=sum+(cnt+1)*smallest + m
		*/
		ans+=min(sum+(cnt-2)*m, sum+(cnt+1)*smallest+m);
	}

	printf("%d\n",ans);

	return 0;
}

