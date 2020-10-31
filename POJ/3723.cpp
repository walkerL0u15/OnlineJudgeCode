#include<cstdio>
#include<algorithm>
using namespace std;
const int MaxF=10005,MaxM=10005;
typedef long long ll;

struct edge{
    int u,v,cost;
}e[50005];
int par[MaxF+MaxM],dep[MaxF+MaxM];
void init(int n){
    for(int i=0;i<=n;++i)
        par[i]=i,dep[i]=0;
    return;
}
int find(int x){
    if(par[x]==x) return par[x];
    return par[x]=find(par[x]);
}
bool unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return false;
    if(dep[fx]>dep[fy]) par[fy]=fx;
    else{
        par[fx]=fy;
        if(dep[fx]==dep[fy]) ++dep[fy];
    }
    return true;
}
bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

int main(){
    int T;
    int R,F,M,ans;
    scanf(" %d",&T);
    while(T--){
        ans=0;
        scanf(" %d %d %d",&F,&M,&R);
        for(int i=0;i<R;++i){
            scanf(" %d %d %d",&e[i].u,&e[i].v,&e[i].cost);
            e[i].v+=F,e[i].cost=-e[i].cost;
        }
        init(F+M+5);
        sort(e,e+R,cmp);
        for(int i=0;i<R;++i)
            if(unite(e[i].u,e[i].v))
                ans+=e[i].cost;
        printf("%d\n",(F+M)*10000+ans);
    }
    return 0;
}
