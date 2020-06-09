#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MaxN 5002
#define INF 200000000
typedef pair<int,int> P;
struct edge{
	int to,cost;
};
int dis1[MaxN],dis2[MaxN];

int main()
{
	int N,R,f,t,c;
	vector<edge> road[MaxN];
	edge ed;
	scanf(" %d %d",&N,&R);
	for(int i=0;i<R;++i){
		scanf(" %d %d %d",&f,&t,&c);
		ed.to=t,ed.cost=c;
		road[f].push_back(ed);
		ed.to=f;
		road[t].push_back(ed);
	}
	priority_queue<P,vector<P>,greater<P> > que;
	fill(dis1,dis1+MaxN,INF);
	fill(dis2,dis2+MaxN,INF);
	dis1[1]=0;
	que.push(P(0,1));
	while(!que.empty()){
		int num=que.top().first,p=que.top().second;
		que.pop();
		if(num>dis2[p]) continue;
		for(int i=0;i<road[p].size();++i){
			edge &e=road[p][i];
			int d=num+e.cost;
			if(dis1[e.to]>d){
				swap(dis1[e.to],d);
				que.push(P(dis1[e.to],e.to));
			}
			if(dis2[e.to]>d&&dis1[e.to]<d){
				dis2[e.to]=d;
				que.push(P(dis2[e.to],e.to));
			}
		}
	}
	printf("%d\n",dis2[N]);
	return 0;
}
