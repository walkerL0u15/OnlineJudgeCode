#include<stdio.h>
#include<algorithm>
using namespace std;
#define ll long long

struct E{
	int f,t,g;
};
bool cmp(E &a,E &b){
	if(a.f==b.f)
		return a.t<b.t;
	return a.f<b.f;
}

int main(){
	int N,M,R,dp[1005];
	E e[1005];
	ll ans=0;
	scanf(" %d %d %d",&N,&M,&R);
	for(int i=0;i<M;++i)
		scanf(" %d %d %d",&e[i].f,&e[i].t,&e[i].g);
	sort(e,e+M,cmp);
	for(int i=0;i<M;++i){
		dp[i]=e[i].g;
		for(int j=0;j<i;++j)
			if(e[j].t+R<=e[i].f)
				dp[i]=max(dp[i],dp[j]+e[i].g);
		ans=max(ans,(ll)dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
