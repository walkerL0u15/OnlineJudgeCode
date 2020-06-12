#include<stdio.h>
#include<algorithm>
using namespace std;

#define MaxN 1005
#define MaxMD 10005
#define MaxML 10005
#define INF 20000000

struct edge{int a,b,cost;};
int N,ML,MD,d[MaxN];
edge eml[MaxML],emd[MaxMD];

void bellman(){
	fill(d,d+N+1,INF);
	d[1]=0;
	for(int j=0;j<N;++j){
		for(int j=N;j>=2;--j)
			d[j-1]=min(d[j],d[j-1]);
		for(int j=0;j<ML;++j)
			d[eml[j].b]=min(d[eml[j].b],d[eml[j].a]+eml[j].cost);
		for(int j=0;j<MD;++j){
			d[emd[j].a]=min(d[emd[j].a],d[emd[j].b]-emd[j].cost);
			if(d[emd[j].a]<0){
				d[N]=-1;
				return;
			}
		}
	}
	return;
}

int main()
{
	int v,u,c;
	scanf(" %d %d %d",&N,&ML,&MD);
	for(int i=0;i<ML;++i){
		scanf(" %d %d %d",&v,&u,&c);
		eml[i].a=v,eml[i].b=u,eml[i].cost=c;
	}
	for(int i=0;i<MD;++i){
		scanf(" %d %d %d",&v,&u,&c);
		emd[i].a=v,emd[i].b=u,emd[i].cost=c;
	}
	bellman();
	if(d[N]==INF)
		puts("-2");
	else
		printf("%d\n",d[N]);
	return 0;
}
