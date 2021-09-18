#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define fastio ios::sync_with_stdio(false),cin.tie(0);
#define f first 
#define s second
const int INF=0x3f3f3f3f;
 
int main(){
	fastio
	int N,num;
	int dp[105][3]={0};//0 no,1 pe,2 it
	bool pe[4]={0,0,1,1};
	bool it[4]={0,1,0,1};
	memset(dp,INF,sizeof(dp));
	dp[0][0]=0,dp[0][1]=0,dp[0][2]=0;
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>num;
		if(pe[num]){
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
			dp[i][0]=min(dp[i][0],dp[i-1][1]+1);
		}
		if(it[num]){
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
			dp[i][0]=min(dp[i][0],dp[i-1][2]+1);
		}
		if(num==0)
			dp[i][0]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+1;
	}
	cout<<min({dp[N][0],dp[N][1],dp[N][2]})<<"\n";
	return 0;
}
