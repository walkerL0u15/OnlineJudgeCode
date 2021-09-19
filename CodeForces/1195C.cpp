#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define fastio ios::sync_with_stdio(false),cin.tie(0);
#define f first 
#define s second

int h1[(int)1e5+10];
int h2[(int)1e5+10];
LL dp[(int)1e5+10][3]={0};//0 h1,1 h2,2 no

int main(){
	fastio
	int N;
	cin>>N;
	for(int i=1;i<=N;++i)
		cin>>h1[i];
	for(int i=1;i<=N;++i)
		cin>>h2[i];
	for(int i=1;i<=N;++i){
		dp[i][0]=max(dp[i-1][1],dp[i-1][2])+h1[i];
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+h2[i];
		dp[i][2]=max(dp[i-1][0],dp[i-1][1]);
	}
	cout<<max({dp[N][0],dp[N][1],dp[N][2]});
	return 0;
}
