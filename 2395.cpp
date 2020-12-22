#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;

int road[2005][2005];
int mincost[2005];
bool used[2005];

int main(){
    int N,M;
    scanf(" %d %d",&N,&M);
    {
        memset(road,INF,sizeof(road));
        memset(mincost,INF,sizeof(mincost));
        memset(used,0,sizeof(used));
        int a,b,c;
        for(int i=0;i<M;++i){
            scanf(" %d %d %d",&a,&b,&c);
            if(road[a][b]>c){
                road[a][b]=c;
                road[b][a]=c;
            }
        }
    }
    int res=-1;
    mincost[1]=0;
    while(true){
        int v=-1;
        for(int i=1;i<=N;++i)
            if(!used[i]&&(v==-1||mincost[v]>mincost[i]))
                v=i;
        if(v==-1) break;
        used[v]=true;
        res=max(res,mincost[v]);
        for(int i=1;i<=N;++i)
            mincost[i]=min(mincost[i],road[v][i]);
    }
    printf("%d\n",res);
    return 0;
}
