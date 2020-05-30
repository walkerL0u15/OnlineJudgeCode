#include<stdio.h>
#define MaxN 30001
int par[MaxN],dep[MaxN];

void init(int n){
	for(int i=0;i<n;++i)
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

int main(){
	int N,M,num[2],ans,amount;
	bool in=true;
	while(scanf(" %d %d",&N,&M)==2&&(N!=0||M!=0)){
		ans=1;
		if(N==0) puts("0");
		init(N);
		while(M--){
			scanf(" %d %d",&amount,&num[in]);
			in=!in;
			amount-=1;
			while(amount--){
				scanf(" %d",&num[in]);
				unite(num[in],num[!in]);
				in=!in;
			}
		}
		int c=find(0);
		for(int i=1;i<N;++i)
			if(find(i)==c)
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}
