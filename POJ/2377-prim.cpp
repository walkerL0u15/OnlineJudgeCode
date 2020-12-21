#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;

int line[1005][1005],mincost[1005];
bool used[1005];

int main(){
    int N,M;
    memset(line,INF,sizeof(line));
    memset(mincost,INF,sizeof(mincost));
    memset(used,0,sizeof(used));
    scanf(" %d %d",&N,&M);
    {
        int a,b,c;
        for(int i=0;i<M;++i){
            scanf(" %d %d %d",&a,&b,&c);
            c=-c;
            if(line[a][b]>c){
                line[a][b]=c;
                line[b][a]=c;
            }
        }
        for(int i=1;i<=N;++i)
            line[i][i]=0;
    }
    int ans=0;
    mincost[1]=0;
    while(true){
        int v=-1;
        for(int i=1;i<=N;++i){
            if((!used[i])&&(v==-1||mincost[v]>mincost[i]))
                v=i;
        }
        if(v==-1) break;
        else if(mincost[v]==INF){
            printf("-1\n");
            return 0;
        }
        used[v]=true;
        ans+=mincost[v];
        for(int i=1;i<=N;++i)
            mincost[i]=min(mincost[i],line[i][v]);
    }
    printf("%d\n",-ans);
    return 0;
}
