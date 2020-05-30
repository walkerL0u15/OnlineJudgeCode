#include<stdio.h>
#include<vector>
using namespace std;
#define MaxN 1002
int par[MaxN],dep[MaxN];

void init(int n){
	for(int i=1;i<=n;++i)
		par[i]=i,dep[i]=0;
	return;
}
int find(int x){
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(dep[x]>dep[y]) par[y]=x;
	else{
		par[x]=y;
		if(dep[x]==dep[y]) ++dep[y];
	}
	return;
}
bool same(int x,int y){
	return find(x)==find(y);
}

int main(){
	int N,D,corx[1002],cory[1002],x,y,a,b;
	vector<int> f;
	char w;
	scanf(" %d %d",&N,&D);
	init(N);
	for(int i=1;i<=N;++i)
		scanf(" %d %d",&corx[i],&cory[i]);
	while(scanf(" %c",&w)==1){
		if(w=='S'){
			scanf(" %d %d",&a,&b);
			if(same(a,b)) puts("SUCCESS");
			else puts("FAIL");
		}
		else{
			scanf(" %d",&a);
			for(int i=0;i<f.size();++i){
				x=corx[f[i]]-corx[a],y=cory[f[i]]-cory[a];
				if(x*x+y*y<=D*D)
					unite(f[i],a);
			}
			f.push_back(a);
		}
	}
	return 0;
}
