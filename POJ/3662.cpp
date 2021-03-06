#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;

struct edge{
    int u,cost;
    edge(){}
    edge(int u,int cost):u(u),cost(cost){}
};
int N,Path,K;
vector<edge> G[1005];
int dijkstra(int s,int x){
    int step[1005];
    memset(step,INF,sizeof(step));
    step[s]=0;
    priority_queue<P,vector<P>,greater<P> > pq;
    pq.push(P(0,s));
    while(!pq.empty()){
        P p=pq.top();pq.pop();
        int v=p.second;
        if(step[v]<p.first) continue;
        for(int i=0;i<G[v].size();++i){
            edge e=G[v][i];
            int len=e.cost>x;
            if(step[v]+len<step[e.u]){
                step[e.u]=step[v]+len;
                pq.push(P(step[e.u],e.u));
            }
        }
    }
    return step[N];
}

int main(){
    scanf(" %d %d %d",&N,&Path,&K);
    {
        int v,u,c;
        for(int i=0;i<Path;++i) {
            scanf(" %d %d %d", &v, &u, &c);
            G[v].push_back(edge(u,c));
            G[u].push_back(edge(v,c));
        }
    }
    int r=1e6+5,l=-1;
    while(r-l>1){
        int mid=(r+l)/2;
        if(dijkstra(1,mid)<=K)
            r=mid;
        else
            l=mid;
    }
    printf("%d\n",(r>1e6)?-1:r);
    return 0;
}
