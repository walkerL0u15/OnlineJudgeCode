#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
const int INF=0x3f3f3f3f;
#define f first
#define s second
typedef pair<int,int> P;

struct E{
	int to,d;
};
typedef struct E E;
int dis[5005];
int dis2[5005];

int main(){
	int N,R,f,t,dis;
	scanf(" %d %d",&N,&R);
	vector<E> e[5003];
	for(int i=0;i<R;++i){
		scanf(" %d %d %d",&f,&t,&dis);
		e[f].push_back(E{t,dis});
		e[t].push_back(E{f,dis});
	}
	fill(dis,dis+5005,INF);
	fill(dis2,dis2+5005,INF);
	dis[1]=0;
	priority_queue<P,vector<P>,greater<P> > pq;
	pq.push({0,1});
	while(!pq.empty()){
		int v=pq.top().s,cost=pq.top().f;
		pq.pop();
		if(cost>dis2[v]) continue;
		for(int i=0;i<e[v].size();++i){
			int edge=e[v][i];
			int d2=cost+edge.d;
			if(d2<dis[edge.to]){
				swap(d2,dis[edge.to]);
				pq.push({dis[edge.to],edge.to});
			}
			if(d2<dis2[edge.to]&&d2!=dis[edge.to]){
				dis2[edge.to]=d2;
				pq.push({dis2[edge.to],edge.to});
			}
		}
	}
	printf("%d\n",dis2[N]);
	return 0;
}
