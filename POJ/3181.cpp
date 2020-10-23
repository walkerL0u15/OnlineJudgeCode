#include<cstdio>
#include<cstring>
typedef long long ll;
#define MOD (ll)1e18

ll dp[1005],dpt[1005];

int main(){
	int N,K;
	scanf(" %d %d",&N,&K);
	memset(dp,0,sizeof(dp));
    memset(dpt,0,sizeof(dpt));
	dp[0]=1;
	for(int i=1;i<=K;++i)
		for(int j=i;j<=N;++j){
            dp[j]+=dp[j-i];
            dpt[j]+=dp[j]/MOD+dpt[j-i];
            dp[j]%=MOD;
        }
    if(dpt[N]>0)
        printf("%lld",dpt[N]);
	printf("%lld\n",dp[N]);
	return 0;
}
