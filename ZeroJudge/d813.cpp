#include<cstdio>
#define MaxN 50001
int par[MaxN],dep[MaxN];

void init(int n){
	for(int i=1;i<=n;++i){
		par[i]=i;
		dep[i]=0;
	}
	return;
}
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(dep[x]>dep[y])
		par[y]=x;
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
	int N,M,c=1,s1,s2;
	while(scanf(" %d %d",&N,&M)==2&&N!=0&&M!=0){
		init(N+1);
		if(N==0){
			printf("Case %d: %d\n",c++,0);
			continue;
		}
		for(int i=0;i<M;++i){
			scanf(" %d %d",&s1,&s2);
			if(same(s1,s2)) continue;
			N-=1;
			unite(s1,s2);
		}
		printf("Case %d: %d\n",c++,N);
	}
  return 0;
}
