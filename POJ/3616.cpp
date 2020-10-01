#include<cstdio>
#include<algorithm>

using namespace std;
struct C{
	int s,e,m;
}cows[1005];

bool cmp(C a,C b){
	return a.e<b.e;
}

int main(){
	int N,M,R,ans=-1,dp[1005];
	scanf(" %d %d %d",&N,&M,&R);
	for(int i=0;i<M;++i)
		scanf(" %d %d %d",&cows[i].s,&cows[i].e,&cows[i].m);
	sort(cows,cows+M,cmp);
	for(int i=0;i<M;++i){
		dp[i]=cows[i].m;
		for(int j=0;j<i;++j)
			if(cows[j].e+R<=cows[i].s)
				dp[i]=max(dp[i],dp[j]+cows[i].m);
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
