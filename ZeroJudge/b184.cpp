#include<iostream>
#include<cstring>
using namespace std;

long N;
int v[1000005],c[1000005];
int dp[1000003][103];
long rec(int idx,int W){
	long res;
	if(idx==N)
		res=0;
	else if(dp[idx][W]!=-1)
		res=dp[idx][W];
	else if(v[idx]>W)
		res=rec(idx+1,W);
	else
		res=max(rec(idx+1,W),rec(idx+1,W-v[idx])+c[idx]);
	return dp[idx][W]=res;
}

int main()
{
	while(scanf("%ld",&N)!=EOF){
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<N;++i)
			scanf(" %d %d",&v[i],&c[i]);
		printf("%ld\n",rec(0,100));
	}
	return 0;
}