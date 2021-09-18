#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define fastio ios::sync_with_stdio(false),cin.tie(0);
#define f first 
#define s second

int main(){
	fastio
	int n,a,b,c;
	int dp[4005]={0};
	cin>>n>>a>>b>>c;
	fill(dp+1,dp+1+n,-1);
	for(int i=0;i<n;++i){
		if(dp[i]==-1) continue;
		if(i+a<=n)
			dp[i+a]=max(dp[i+a],dp[i]+1);
		if(i+b<=n)
			dp[i+b]=max(dp[i+b],dp[i]+1);
		if(i+c<=n)
			dp[i+c]=max(dp[i+c],dp[i]+1);
	}
	cout<<dp[n]<<"\n";
	return 0;
}
