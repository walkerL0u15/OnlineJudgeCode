#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int id[(int)1e6+5];

int main(){
	int P;
	set<int> idx;
	scanf(" %d",&P);
	for(int i=0;i<P;++i){
		scanf(" %d",&id[i]);
		idx.insert(id[i]);
	}
	int now=0,total=idx.size();
	map<int,int> cnt;
	int s=0,t=-1,ans=1e8;
	while(s<P){
		while(t<P-1&&now<total){
			if(cnt[id[++t]]++==0)
				++now;
		}
		if(now<total) break;
		ans=min(ans,t-s+1);
		if(--cnt[id[s++]]==0) --now;
	}
	printf("%d\n",ans);
	return 0;
}
