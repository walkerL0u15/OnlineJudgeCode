#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[(int)1e5+5];
struct C{
	int c,num;
}coin[1005];

int main(){
	int N,Max,ans;
	while(scanf(" %d %d",&N,&Max)==2&&N!=0){
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<=N;++i)
			scanf(" %d",&coin[i].c);
		for(int i=1;i<=N;++i)
			scanf(" %d",&coin[i].num);
		for(int i=1;i<=N;++i){
			for(int j=0;j<=Max;++j){
				if(dp[j]>=0)
					dp[j]=coin[i].num;
				else if(j>=coin[i].c&&dp[j-coin[i].c]>0)
					dp[j]=dp[j-coin[i].c]-1;
			}
		}
		ans=0;
		for(int i=1;i<=Max;++i)
			if(dp[i]>=0)
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}
