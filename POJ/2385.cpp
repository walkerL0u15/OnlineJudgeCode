#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int T,W,dp[2][1005],ans=-1;
	int apple[2][1005];
	scanf(" %d %d",&T,&W);
	for(int i=1;i<=T;++i){
		scanf(" %d",&apple[0][i]);
		--apple[0][i];
		apple[1][i]=!apple[0][i];
	}
	for(int k=0;k<=1;++k){
		memset(dp,0,sizeof(dp));
		for(int i=k&1;i<=W+k&1;++i){
			for(int j=1;j<=T;++j)
				dp[i&1][j]=max(dp[!(i&1)][j-1],dp[i&1][j-1])+apple[i&1][j];
			ans=max(ans,dp[i&1][T]);
		}
	}
	printf("%d\n",max(ans,T-ans));
	return 0;
}
