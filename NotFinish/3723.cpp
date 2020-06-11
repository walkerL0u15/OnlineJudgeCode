#include<stdio.h>
#include<algorithm>
using namespace std;

#define MaxN 10005
#define MaxM 10005
#define MaxE 50002

struct edge{int f,t,cost;};
int N,M,E;
edge es[MaxE];
int par[MaxN+MaxM],dep[MaxN+MaxM];

void init_union(int n){
    for(int i=0;i<=n;++i)
        dep[i]=0,par[i]=i;
    return;
}
bool find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
bool same(int x,int y){
    return find(x)==find(y);
}
void unite(int x,int y){
    int xp=find(x),yp=find(y);
    if(xp==yp) return;
    if(dep[xp]>dep[yp])
        par[yp]=xp;
    else{
        par[xp]=yp;
        if(dep[xp]==dep[yp]) dep[yp]++;
    }
    return;
}
bool cmp(edge &a,edge &b){
    return a.cost<b.cost;
}
int kruskal(){
    sort(es,es+E,cmp);
    init_union(N+M+3);
    int res=0;
    for(int i=0;i<E;++i){
        if(!same(es[i].f,es[i].t)){
            unite(es[i].f,es[i].t);
            res+=es[i].cost;
            printf("%d\n",es[i].cost);
        }
    }
    return res;
}

int main()
{
    int T,f,t,c;
    scanf(" %d",&T);
    while(T--){
        scanf(" %d %d %d",&N,&M,&E);
        for(int i=0;i<E;++i){
            scanf(" %d %d %d",&f,&t,&c);
            es[i].f=f,es[i].t=N+t,es[i].cost=-c;
        }
        printf("%d\n",(N+M)*10000+kruskal());
    }
    return 0;
}
