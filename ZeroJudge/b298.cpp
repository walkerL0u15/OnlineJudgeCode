#include<cstdio>
#include<vector>
using namespace std;

vector<int> f[10005];
bool pollute[10005]={0};

void dfs(int cur){
	pollute[cur]=true;
	for(int i=0;i<f[cur].size();++i)
		if(!pollute[f[cur][i]])
			dfs(f[cur][i]);
	return;
}

int main(){
	int N,M,L,Q;
	scanf(" %d %d %d %d",&N,&M,&L,&Q);
	int a,b;
	for(int i=0;i<M;++i){
		scanf(" %d %d",&a,&b);
		f[a].push_back(b);
	}
	for(int i=0;i<L;++i){
		scanf(" %d",&a);
		dfs(a);
	}
	for(int i=0;i<Q;++i){
		scanf(" %d",&a);
		if(pollute[a])
			printf("TUIHUOOOOOO\n");
		else
			printf("YA~~\n");
	}
	return 0;
}
