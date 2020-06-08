#include<stdio.h>
#include<string.h>
#define MaxN 501

struct edge{int from,to,cost;};
int farm[MaxN],T,N,M,W;;
edge es[2701];

bool bellman(){
	memset(farm,0,sizeof(farm));
	for(int i=1;i<=N;++i)
		for(int j=0;j<W+M;++j)
			if(farm[es[j].to]>farm[es[j].from]+es[j].cost){
				farm[es[j].to]=farm[es[j].from]+es[j].cost;
				if(i==N) return true;
			}
	return false;
}
 

int main(){
	scanf(" %d",&T);
	while(T--){
		scanf(" %d %d %d",&N,&M,&W);
		for(int i=0;i<M;++i)
			scanf(" %d %d %d",&es[i].from,&es[i].to,&es[i].cost);
		for(int i=M;i<M+W;++i){
			scanf(" %d %d %d",&es[i].from,&es[i].to,&es[i].cost);
			es[i].cost=-es[i].cost;
		}
		if(bellman())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
