#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;

#define MaxN 202
#define MaxR 19902
#define INF 10000000
struct edge{int to,cost;};

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int name,N,R,c,a,b,d[MaxN],cnt=1;
    string u,v;
    edge e;
    bool f,used[MaxN];
    string city[MaxN];
    //input
    while(cin>>N>>R&&N!=0){
        vector<edge> V[MaxN];
        name=1;
        for(int i=0;i<R;++i){
            f=false;
            cin>>u>>v>>c;
            for(int i=1;i<name;++i)
                if(city[i]==u){
                    a=i;
                    f=true;
                    break;
                }
            if(!f)
                city[name]=u,a=name,name++;
            f=false;
            for(int i=1;i<name;++i)
                if(city[i]==v){
                    b=i;
                    f=true;
                    break;
                }
            if(!f)
                city[name]=v,b=name,name++;
            e.to=b,e.cost=c;
            V[a].push_back(e);
            e.to=a;
            V[b].push_back(e);
        }
        cin>>u>>v;
        for(int i=1;i<name;++i)
            if(city[i]==u){
                a=i;
                break;
            }
        for(int i=1;i<name;++i)
            if(city[i]==v){
                b=i;
                break;
            }
        //dijkstra
        fill(d,d+N+1,-1);
        fill(used,used+N+1,false);
        d[a]=INF;
        queue<int> que;
        que.push(a);
        while(!que.empty()){
            int q=que.front();que.pop();
            used[q]=false;
            for(int i=0;i<V[q].size();++i){
                edge l=V[q][i];
                if(l.to!=a&&min(d[q],l.cost)>d[l.to]){
                    d[l.to]=min(d[q],l.cost);
                    if(!used[l.to]){
                        que.push(l.to);
                        used[l.to]=true;
                    }
                }
            }
        }
        printf("Scenario #%d\n%d tons\n\n",cnt,d[b]);
        ++cnt;
    }
    return 0;
}
