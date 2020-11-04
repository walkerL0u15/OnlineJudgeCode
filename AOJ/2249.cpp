#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;
#define f first
#define s second
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;

struct edge{
    int v,dis,c;
};

int d[10005];
vector<edge> G[10005];

void dij(int s){
    priority_queue<P,vector<P>,greater<P> > pq;
    fill(d,d+10005,INF);
    d[s]=0;pq.push(P(0,s));
    while(!pq.empty()){
        P p=pq.top();pq.pop();
        int u=p.s;
        for(int i=0;i<G[u].size();++i){
            edge e=G[u][i];
            if(d[u]+e.dis<d[e.v]){
                d[e.v]=d[u]+e.dis;
                pq.push(P(d[e.v],e.v));
            }
        }
    }
}

int main(){
    int N,M;
    while(scanf(" %d %d",&N,&M)==2&&N!=0){
        for(int i=1;i<=N;++i)
            G[i].clear();
        {
            int u,v,di,c;
            for(int i=0;i<M;++i){
                scanf(" %d %d %d %d",&u,&v,&di,&c);
                G[u].push_back(edge{v,di,c});
                G[v].push_back(edge{u,di,c});
            }
        }
        dij(1);
        int ans=0,mincost;
        for(int i=2;i<=N;++i){
            mincost=INF;
            for(int j=0;j<G[i].size();++j){
                struct edge e=G[i][j];
                if(d[e.v]+e.dis==d[i])
                    mincost=min(mincost,e.c);
            }
            ans+=mincost;
        }
        printf("%d\n",ans);
    }
    return 0;
}
