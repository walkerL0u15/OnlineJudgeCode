#include<iostream>
#include<queue>
using namespace std;

int main()
{
	priority_queue<int,vector<int>,less<int> > oil;
	int N,L,P,A[10005],B[10005],ans,to;
	scanf(" %d",&N);
	for(int i=0;i<N;++i)
		scanf(" %d %d",&A[i],&B[i]);
	scanf(" %d %d",&L,&P);
	for(int i=0;i<N;++i)
		A[i]=L-A[i];
	for(int i=1;i<N;++i)
		for(int j=i;j>0;--j)
			if(A[j]<A[j-1]){
				swap(A[j],A[j-1]);
				swap(B[j],B[j-1]);
			}
	int pos=0;
	ans=0;
	A[N]=L,B[N]=0;
	for(int i=0;i<=N;++i){
		to=A[i]-pos;
		while(P-to<0){
			if(oil.empty()){
				puts("-1\n");
				return 0;
			}
			P+=oil.top();
			oil.pop();
			++ans;
		}
		pos=A[i];
		P-=to;
		oil.push(B[i]);
	}
	printf("%d\n",ans);
	return 0;
}
