#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define Nmax 5002
#define INF 2000000000
typedef pair<int,int> P;
struct edge{
	int to,cost;
};
int dis1[MaxN],dis2[MaxN];

int main()
{
	int N,R,f,t,c;
	vector<edge> road[Nmax];
	edge p;
	scanf(" %d %d",&N,&R);
	for(int i=0;i<N;++i){
		scanf(" %d %d %d",&f,&t,&c);
		p.to=t,p.cost=c;
		road[f].push_back(p);
		p.to=f;
		road[t].push_back(p);
	}
	priority_queue<P,vector<P>,greater<P> > que;
	fill(dis1,dis1+N+1,INF);
	fill(dis2,dis2+N+1,INF);
	dis1[1]=0,dis2[1]=0;
}
