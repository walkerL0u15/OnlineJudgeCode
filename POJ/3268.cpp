#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define c first
#define v second
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;

int N,M,X;
int d[1005];
vector<P> p[1005];
int dij(int from,int to){
    priority_queue<P,vector<P>,greater<P> > pq;
    fill(d,d+1005,INF);
    d[from]=0;
    pq.push(make_pair(0,from));
    while(!pq.empty()){
        P n=pq.top();pq.pop();
        if(n.c>d[n.v]) continue;
        for(int i=0;i<p[n.v].size();++i){
            P e=p[n.v][i];
            if(d[n.v]+e.c<d[e.v]){
                d[e.v]=d[n.v]+e.c;
                pq.push(make_pair(d[e.v],e.v));
            }
        }
    }
    return d[to];
}

int main(){
    int ans=-1;
    scanf(" %d %d %d",&N,&M,&X);
    {
        int u,v,c;
        for(int i=0;i<M;++i){
            scanf(" %d %d %d",&u,&v,&c);
            p[u].push_back(make_pair(c,v));
        }
    }
    for(int i=1;i<=N;++i)
        if(i!=X)
            ans=max(ans,dij(i,X)+dij(X,i));
    printf("%d\n",ans);
    return 0;
}
