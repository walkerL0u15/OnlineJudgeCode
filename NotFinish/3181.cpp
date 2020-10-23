#include<cstdio>
#include<cstring>

long long dp[2][1005];

int main(){
	int N,K;
	scanf(" %d %d",&N,&K);
	memset(dp,0,sizeof(dp));
	dp[1][0]=dp[0][0]=1;
	for(int i=1;i<=K;++i)
		for(int j=1;j<=N;++j){
			if(j>=i)
				dp[i&1][j]=dp[(i-1)&1][j]+dp[i&1][j-i];
			else
				dp[i&1][j]=dp[(i-1)&1][j];
		}
	printf("%lld\n",dp[K&1][N]);
	return 0;
}
