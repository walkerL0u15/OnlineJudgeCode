#include<cstdio>
#include<utility>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
#define f first
#define s second

int dp[10005]={0};
P path[10005];
bool cmp(P a,P b){
	return a.s<b.s;
}

int main(){
	int M,T;
	scanf(" %d %d",&M,&T);
	path[0].f=0,path[0].s=0;
	for(int i=1;i<=T;++i)
		scanf(" %d %d",&path[i].f,&path[i].s);
	sort(path,path+T+1,cmp);
	int p=1;
	for(int i=1;i<=M;++i){
		dp[i]=dp[i-1];
		while(p<=T&&path[p].s==i){
			dp[i]=max(dp[i],dp[path[p].f]+path[p].s-path[p].f);
			++p;
		}
	}
	printf("%d\n",dp[M]);
	return 0;
}
