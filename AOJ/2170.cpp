#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MaxN=1e5+5;

int par[MaxN];
int qv[(int)1e5+5],qt[(int)1e5+5];
int mark[(int)1e5+5],time;
int find(int x){
	if(time>mark[x])
		return x;
	return par[x]=find(par[x]);
}

int main(){
	int N,Q,cnt,num;
	ll ans;
	char c;
	par[1]=1;
	mark[1]=0;
	while(scanf(" %d %d",&N,&Q)==2&&N!=0){
		cnt=0;
		for(int i=2;i<=N;++i){
			scanf(" %d",&par[i]);
			mark[i]=0x3f3f3f3f;
		}
		for(int i=1;i<=Q;++i){
			scanf(" %c %d",&c,&num);
			if(c=='M')
				mark[num]=min(mark[num],i);
			else{
				qv[cnt]=num;
				qt[cnt++]=i;
			}
		}
	 	ans=0;
		while(cnt--){
			time=qt[cnt];
			ans+=find(qv[cnt]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
