#include<stdio.h>
#include<set>
using namespace std;
#define MaxN 805

int N,M,a,b;
bool num[MaxN];
set<int> city[MaxN];

bool dfs(int x){
	num[x]=false;
	for(set<int>::iterator i=city[x].begin();i!=city[x].end();++i){
		if(*i==b||(num[*i]&&dfs(*i)))
			return true;
		
	}
	return false;
}

int main()
{
	while(scanf(" %d %d",&N,&M)!=EOF){
		for(int i=1;i<=N;++i){
			city[i].clear();
			num[i]=true;
		}
		for(int i=0;i<M;++i){
			scanf(" %d %d",&a,&b);
			if(!city[a].count(b))
				city[a].insert(b);
		}
		scanf(" %d %d",&a,&b);
		if(dfs(a))
			puts("Yes!!!");
		else
			puts("No!!!");
	}
	return 0;
}
