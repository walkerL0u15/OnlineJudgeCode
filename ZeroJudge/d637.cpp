#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N;
	int w,v;
	int dp[105]={-1};
	dp[0]=0;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>w>>v;
		for(int j=100-w;j>=0;--j)
			dp[j+w]=max(dp[j+w],dp[j]+v);
	}
	int ans=-1;
	for(int i=0;i<=100;++i)
		ans=max(ans,dp[i]);
	cout<<ans<<"\n";
	return 0;
}
