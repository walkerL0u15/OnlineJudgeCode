#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N,num[105],dp[105][105]={0};
	cin>>N;
	memset(dp,INF,sizeof(dp));
	for(int i=1;i<=N;++i)
		cin>>num[i];
	for(int i=0;i<=1;++i)
		for(int j=1;j+i<=N;++j)
			dp[j][j+i]=0;
	for(int t=2;t+1<=N;++t)
		for(int i=1;i+t<=N;++i){
			int l=i,r=i+t;//(l,r)
			for(int k=l+1;k<r;++k)
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+num[l]*num[k]*num[r]);
		}
	cout<<dp[1][N]<<"\n";
	return 0;
}
